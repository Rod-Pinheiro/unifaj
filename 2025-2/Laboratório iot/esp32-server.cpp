#include <WiFi.h>
#include <WebServer.h>
#include <ArduinoJson.h>
#include <HardwareSerial.h>

// ---- Configuração WiFi ----
const char* ssid = "Estacionamento-IoT";
const char* password = "12345678";

// ---- Porta Serial para comunicação com Arduino ----
#define ARDUINO_SERIAL Serial2
#define BAUD_RATE 9600

// ---- Web Server na porta 80 ----
WebServer server(80);

// ---- Estrutura de dados do estacionamento ----
struct ParkingData {
  int vagas[6];
  bool entradaAberta;
  bool saidaAberta;
  bool sensorEntrada;
  bool sensorSaida;
} parkingData;

// ---- Variáveis de controle ----
unsigned long lastArduinoUpdate = 0;
const unsigned long UPDATE_INTERVAL = 1000; // 1 segundo

// ---- Inicialização WiFi ----
void setupWiFi() {
  WiFi.softAP(ssid, password);
  IPAddress IP = WiFi.softAPIP();
  Serial.print("AP IP address: ");
  Serial.println(IP);
}

// ---- Comunicação com Arduino ----
void sendCommandToArduino(String command) {
  ARDUINO_SERIAL.println(command);
}

void readArduinoData() {
  if (ARDUINO_SERIAL.available()) {
    String data = ARDUINO_SERIAL.readStringUntil('\n');
    data.trim();
    Serial.println("Dados recebidos do Arduino: [" + data + "] tamanho: " + String(data.length()));
    parseArduinoData(data);
  }
}

void parseArduinoData(String data) {
  // Formato esperado: "VAGAS:1,0,1,0,1,0;ENTRADA:0;SAIDA:0;SENTRADA:0;SSAIDA:0"
  if (data.startsWith("VAGAS:")) {
    int vagasEnd = data.indexOf(';');
    String vagasStr = data.substring(6, vagasEnd);
    
    int entradaEnd = data.indexOf(';', vagasEnd + 1);
    String entradaStr = data.substring(vagasEnd + 9, entradaEnd);
    
    int saidaEnd = data.indexOf(';', entradaEnd + 1);
    String saidaStr = data.substring(entradaEnd + 7, saidaEnd);
    
    int sensorEntradaEnd = data.indexOf(';', saidaEnd + 1);
    String sensorEntradaStr = data.substring(saidaEnd + 10, sensorEntradaEnd);
    
    String sensorSaidaStr = data.substring(sensorEntradaEnd + 8);
    
    // Parse vagas
    for (int i = 0; i < 6; i++) {
      int commaIndex = vagasStr.indexOf(',');
      if (commaIndex == -1) commaIndex = vagasStr.length();
      parkingData.vagas[i] = vagasStr.substring(0, commaIndex).toInt();
      vagasStr = vagasStr.substring(commaIndex + 1);
    }
    
    parkingData.entradaAberta = entradaStr.toInt();
    parkingData.saidaAberta = saidaStr.toInt();
    parkingData.sensorEntrada = sensorEntradaStr.toInt();
    parkingData.sensorSaida = sensorSaidaStr.toInt();
  }
}

// ---- Endpoints da API ----
void handleStatus() {
  DynamicJsonDocument doc(1024);
  
  JsonArray parkingArray = doc.createNestedArray("parking");
  for (int i = 0; i < 6; i++) {
    JsonObject vaga = parkingArray.createNestedObject();
    vaga["id"] = i + 1;
    vaga["occupied"] = (parkingData.vagas[i] == LOW);
  }
  
  JsonObject gates = doc.createNestedObject("gates");
  JsonObject entrance = gates.createNestedObject("entrance");
  entrance["open"] = parkingData.entradaAberta;
  entrance["sensor"] = (parkingData.sensorEntrada == LOW);
  
  JsonObject exit = gates.createNestedObject("exit");
  exit["open"] = parkingData.saidaAberta;
  exit["sensor"] = (parkingData.sensorSaida == LOW);
  
  String response;
  serializeJson(doc, response);
  server.send(200, "application/json", response);
}

void handleOpenGate() {
  String uri = server.uri();
  String gate;

  if (uri == "/api/gate/entrance/open") {
    gate = "entrance";
  } else if (uri == "/api/gate/exit/open") {
    gate = "exit";
  } else {
    gate = "";
  }

  Serial.println("Gate parameter: [" + gate + "]");

  if (gate == "entrance") {
    sendCommandToArduino("ABRIR_ENTRADA");
    server.send(200, "application/json", "{\"status\":\"ok\",\"message\":\"Abrindo cancela de entrada\"}");
  } else if (gate == "exit") {
    sendCommandToArduino("ABRIR_SAIDA");
    server.send(200, "application/json", "{\"status\":\"ok\",\"message\":\"Abrindo cancela de saída\"}");
  } else {
    Serial.println("Invalid gate: " + gate);
    server.send(400, "application/json", "{\"status\":\"error\",\"message\":\"Cancela inválida\"}");
  }
}

void handleRoot() {
  String html = getIndexHTML();
  server.send(200, "text/html", html);
}

// ---- Página HTML ----
String getIndexHTML() {
  String html = "<!DOCTYPE html><html><head>";
  html += "<title>Estacionamento IoT</title>";
  html += "<meta charset=\"UTF-8\">";
  html += "<meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0\">";
  html += "<style>";
  html += "body { font-family: Arial, sans-serif; margin: 20px; background: #f0f0f0; }";
  html += ".container { max-width: 800px; margin: 0 auto; background: white; padding: 20px; border-radius: 10px; }";
  html += "h1 { text-align: center; color: #333; }";
  html += ".parking-grid { display: grid; grid-template-columns: repeat(3, 1fr); gap: 10px; margin: 20px 0; }";
  html += ".parking-spot { padding: 20px; text-align: center; border-radius: 5px; font-weight: bold; }";
  html += ".occupied { background: #ff4444; color: white; }";
  html += ".free { background: #44ff44; color: white; }";
  html += ".gates { display: flex; justify-content: space-around; margin: 20px 0; }";
  html += ".gate { padding: 15px; text-align: center; border-radius: 5px; min-width: 150px; }";
  html += ".gate-open { background: #ffaa00; color: white; }";
  html += ".gate-closed { background: #666; color: white; }";
  html += "button { padding: 10px 20px; margin: 5px; border: none; border-radius: 5px; cursor: pointer; }";
  html += ".btn-open { background: #4CAF50; color: white; }";
  html += ".btn-open:hover { background: #45a049; }";
  html += ".status { text-align: center; margin: 10px 0; }";
  html += "</style></head><body>";
  html += "<div class=\"container\">";
  html += "<h1>🚗 Estacionamento IoT</h1>";
  html += "<div class=\"status\">";
  html += "<h3>Status das Vagas</h3>";
  html += "<div class=\"parking-grid\" id=\"parkingGrid\">";
  html += "<!-- Vagas serão preenchidas via JavaScript -->";
  html += "</div></div>";
  html += "<div class=\"status\">";
  html += "<h3>Status das Cancelas</h3>";
  html += "<div class=\"gates\">";
  html += "<div class=\"gate\" id=\"entranceGate\">";
  html += "<h4>Entrada</h4>";
  html += "<div id=\"entranceStatus\">Carregando...</div>";
  html += "<button class=\"btn-open\" onclick=\"openGate('entrance')\">Abrir Entrada</button>";
  html += "</div>";
  html += "<div class=\"gate\" id=\"exitGate\">";
  html += "<h4>Saída</h4>";
  html += "<div id=\"exitStatus\">Carregando...</div>";
  html += "<button class=\"btn-open\" onclick=\"openGate('exit')\">Abrir Saída</button>";
  html += "</div></div></div></div>";
  html += "<script>";
  html += "function updateStatus() {";
  html += "fetch('/api/parking/status')";
  html += ".then(response => response.json())";
  html += ".then(data => {";
  html += "const parkingGrid = document.getElementById('parkingGrid');";
  html += "parkingGrid.innerHTML = '';";
  html += "data.parking.forEach(spot => {";
  html += "const div = document.createElement('div');";
  html += "div.className = \"parking-spot \" + (spot.occupied ? \"occupied\" : \"free\");";
  html += "div.textContent = \"Vaga \" + spot.id + \": \" + (spot.occupied ? \"Ocupada\" : \"Livre\");";
  html += "parkingGrid.appendChild(div);";
  html += "});";
  html += "const entranceDiv = document.getElementById('entranceGate');";
  html += "entranceDiv.className = \"gate \" + (data.gates.entrance.open ? \"gate-open\" : \"gate-closed\");";
  html += "document.getElementById('entranceStatus').textContent = ";
  html += "data.gates.entrance.open ? 'Aberta' : 'Fechada';";
  html += "const exitDiv = document.getElementById('exitGate');";
  html += "exitDiv.className = \"gate \" + (data.gates.exit.open ? \"gate-open\" : \"gate-closed\");";
  html += "document.getElementById('exitStatus').textContent = ";
  html += "data.gates.exit.open ? 'Aberta' : 'Fechada';";
  html += "})";
  html += ".catch(error => console.error('Erro:', error));";
  html += "}";
  html += "function openGate(gate) {";
  html += "fetch(\"/api/gate/\" + gate + \"/open\", {method: \"POST\"})";
  html += ".then(response => response.json())";
  html += ".then(data => {";
  html += "alert(data.message);";
  html += "setTimeout(updateStatus, 500);";
  html += "})";
  html += ".catch(error => console.error('Erro:', error));";
  html += "}";
  html += "setInterval(updateStatus, 2000);";
  html += "updateStatus();";
  html += "</script></body></html>";
  return html;
}

void setup() {
  Serial.begin(9600);
  ARDUINO_SERIAL.begin(BAUD_RATE, SERIAL_8N1, 16, 17); // RX=16, TX=17
  
  // Inicializar dados
  for (int i = 0; i < 6; i++) {
    parkingData.vagas[i] = HIGH;
  }
  parkingData.entradaAberta = false;
  parkingData.saidaAberta = false;
  parkingData.sensorEntrada = HIGH;
  parkingData.sensorSaida = HIGH;
  
  setupWiFi();
  
  // Configurar rotas do servidor
  server.on("/", handleRoot);
  server.on("/api/parking/status", handleStatus);
  server.on("/api/gate/entrance/open", HTTP_POST, handleOpenGate);
  server.on("/api/gate/exit/open", HTTP_POST, handleOpenGate);
  
  server.begin();
  Serial.println("Servidor HTTP iniciado");
}

void loop() {
  server.handleClient();
  
  // Ler dados do Arduino periodicamente
  if (millis() - lastArduinoUpdate > UPDATE_INTERVAL) {
    sendCommandToArduino("STATUS");
    readArduinoData();
    lastArduinoUpdate = millis();
  }
  
  // Ler dados disponíveis do Arduino
  readArduinoData();
}