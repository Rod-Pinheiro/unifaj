#include <Servo.h>
#include <LiquidCrystal_I2C.h>

// ---- Pinos dos servos ----
#define SERVO_ENTRADA 6
#define SERVO_SAIDA   7

Servo cancelaEntrada;
Servo cancelaSaida;

LiquidCrystal_I2C lcd(0x27, 16, 2);

// ---- Sensores das vagas ----
int vagas[6] = { 22, 24, 26, 28, 30, 32 };
int estadoSensores[6];

// ---- LEDs das vagas ----
int leds[6] = { 36, 38, 40, 42, 44, 46 };

// ---- Sensores das cancelas ----
int sensorEntrada = 9;
int sensorSaida   = 10;
int estadoEntrada;
int estadoSaida;

// ---- Controle de estados das cancelas ----
bool entradaAberta = false;
bool saidaAberta   = false;
bool entradaAbertaManualmente = false;
bool saidaAbertaManualmente = false;
unsigned long tempoEntrada = 0;
unsigned long tempoSaida   = 0;
const unsigned long TEMPO_FECHAR = 2000; // 2 segundos
const unsigned long TEMPO_FECHAR_MANUAL = 10000; // 10 segundos

// ---- Controle de envio periódico ----
unsigned long lastSend = 0;
const unsigned long SEND_INTERVAL = 1000; // 1 segundo

void setup() {
  Serial.begin(9600);
  Serial2.begin(9600); // Comunicação com ESP32

  // Inicializa display LCD
  lcd.init();
  lcd.backlight();
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Sistema");
  lcd.setCursor(0, 1);
  lcd.print("Iniciando...");
  delay(2000);

  // Pinos das vagas
  for (int i = 0; i < 6; i++) {
    pinMode(vagas[i], INPUT);
  }

  // Pinos dos LEDs das vagas
  for (int i = 0; i < 6; i++) {
    pinMode(leds[i], OUTPUT);
    digitalWrite(leds[i], LOW); // Inicialmente apagados
  }

  // Pinos das cancelas
  pinMode(sensorEntrada, INPUT);
  pinMode(sensorSaida, INPUT);

  // Configura servos
  cancelaEntrada.attach(SERVO_ENTRADA);
  cancelaSaida.attach(SERVO_SAIDA);

  // Inicialmente fechadas  
  cancelaEntrada.write(0);
  cancelaSaida.write(90);
}

void loop() {
  // Lê sensores das vagas
  int vagasLivres = 0;
  for (int i = 0; i < 6; i++) {
    estadoSensores[i] = digitalRead(vagas[i]);
    // Atualiza LEDs conforme estado das vagas
    if (estadoSensores[i] == LOW) {
      digitalWrite(leds[i], LOW); // Vaga ocupada - LED apagado
    } else {
      digitalWrite(leds[i], HIGH);  // Vaga livre - LED aceso
      vagasLivres++;
    }
  }

  // Update LCD with available spots
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Vagas Livres:");
  lcd.setCursor(0, 1);
  lcd.print(vagasLivres);

  // Lê sensores das cancelas
  estadoEntrada = digitalRead(sensorEntrada);
  estadoSaida   = digitalRead(sensorSaida);

  // ---- Cancela da ENTRADA ----
  if (estadoEntrada == LOW && !entradaAberta) {
    abreEntrada();
    entradaAbertaManualmente = false;
    tempoEntrada = millis(); // marca o tempo que abriu
  }
  if (entradaAberta && !entradaAbertaManualmente && millis() - tempoEntrada > TEMPO_FECHAR) {
    // Verifica se o sensor está desobstruído antes de fechar
    if (digitalRead(sensorEntrada) == HIGH) {
      fechaEntrada();
    } else {
      // Mantém aberta se houver obstrução
      tempoEntrada = millis(); // Reseta o tempo para tentar novamente
    }
  }
  if (entradaAberta && entradaAbertaManualmente && millis() - tempoEntrada > TEMPO_FECHAR_MANUAL) {
    // Verifica se o sensor está desobstruído antes de fechar
    if (digitalRead(sensorEntrada) == HIGH) {
      fechaEntrada();
    } else {
      // Mantém aberta se houver obstrução
      tempoEntrada = millis(); // Reseta o tempo para tentar novamente
    }
  }

  // ---- Cancela da SAÍDA ----
  if (estadoSaida == LOW && !saidaAberta) {
    abreSaida();
    tempoSaida = millis(); // marca o tempo que abriu
  }
  if (saidaAberta && millis() - tempoSaida > TEMPO_FECHAR) {
    // Verifica se o sensor está desobstruído antes de fechar
    if (digitalRead(sensorSaida) == HIGH) {
      fechaSaida();
    } else {
      // Mantém aberta se houver obstrução
      tempoSaida = millis(); // Reseta o tempo para tentar novamente
    }
  }

  // ---- Comunicação com ESP32 ----
  if (Serial2.available()) {
    String command = Serial2.readStringUntil('\n');
    command.trim();
    Serial.println("Comando recebido via Serial2: [" + command + "]");
    processCommand(command, "Serial2");
  }

  // ---- Comunicação Serial (USB) para debug ----
  if (Serial.available()) {
    String command = Serial.readStringUntil('\n');
    command.trim();
    Serial.println("Comando recebido via Serial: [" + command + "]");
    processCommand(command, "Serial");
  }

  // ---- Envio periódico de status para ESP32 ----
  if (millis() - lastSend > SEND_INTERVAL) {
    sendStatusToESP32();
    lastSend = millis();
  }

  delay(500);
}

// ---- Funções da cancela ENTRADA ----
void abreEntrada() {
  cancelaEntrada.write(90);  
  entradaAberta = true;
  Serial.println("Cancela ENTRADA aberta");
}
void fechaEntrada() {
  cancelaEntrada.write(0);  
  entradaAberta = false;
  Serial.println("Cancela ENTRADA fechada");
}

// ---- Funções da cancela SAÍDA ----
void abreSaida() {
  cancelaSaida.write(0);
  saidaAberta = true;
  Serial.println("Cancela SAÍDA aberta");
}
void fechaSaida() {
  cancelaSaida.write(90);
  saidaAberta = false;
  Serial.println("Cancela SAÍDA fechada");
}

// ---- Função para processar comandos recebidos ----
void processCommand(String command, String source) {
  Serial.println("Processando comando via " + source + ": " + command);
  
  command.toUpperCase();
  
  if (command == "ABRIR_ENTRADA" || command == "OPEN_ENTRY") {
    if (!entradaAberta) {
      abreEntrada();
      entradaAbertaManualmente = true;
      tempoEntrada = millis();
      Serial.println("Comando executado: Abrir entrada");
    } else {
      Serial.println("Entrada ja esta aberta");
    }
  }
  else if (command == "FECHAR_ENTRADA" || command == "CLOSE_ENTRY") {
    if (entradaAberta) {
      fechaEntrada();
      Serial.println("Comando executado: Fechar entrada");
    } else {
      Serial.println("Entrada ja esta fechada");
    }
  }
  else if (command == "ABRIR_SAIDA" || command == "OPEN_EXIT") {
    if (!saidaAberta) {
      abreSaida();
      Serial.println("Comando executado: Abrir saida");
    } else {
      Serial.println("Saida ja esta aberta");
    }
  }
  else if (command == "FECHAR_SAIDA" || command == "CLOSE_EXIT") {
    if (saidaAberta) {
      fechaSaida();
      Serial.println("Comando executado: Fechar saida");
    } else {
      Serial.println("Saida ja esta fechada");
    }
  }
  else if (command == "STATUS" || command == "GET_STATUS") {
    sendStatusToESP32();
    Serial.println("Status enviado");
  }
  else if (command == "DEBUG" || command == "DEBUG_INFO") {
    printDebugInfo();
  }
  else if (command == "HELP" || command == "AJUDA") {
    printHelpCommands();
  }
  else {
    Serial.println("Comando nao reconhecido: " + command);
    Serial.println("Digite 'HELP' para ver comandos disponiveis");
  }
}

// ---- Função para enviar informações de debug ----
void printDebugInfo() {
  Serial.println("=== DEBUG INFO ===");
  Serial.print("Vagas livres: ");
  int vagasLivres = 0;
  for (int i = 0; i < 6; i++) {
    Serial.print(estadoSensores[i] == HIGH ? "L" : "O");
    if (estadoSensores[i] == HIGH) vagasLivres++;
  }
  Serial.println(" (" + String(vagasLivres) + "/6)");
  
  Serial.println("Cancela Entrada: " + String(entradaAberta ? "ABERTA" : "FECHADA"));
  Serial.println("Cancela Saida: " + String(saidaAberta ? "ABERTA" : "FECHADA"));
  Serial.println("Sensor Entrada: " + String(estadoEntrada == LOW ? "CARRO" : "LIVRE"));
  Serial.println("Sensor Saida: " + String(estadoSaida == LOW ? "CARRO" : "LIVRE"));
  Serial.println("Uptime: " + String(millis() / 1000) + "s");
  Serial.println("==================");
}

// ---- Função para imprimir comandos disponíveis ----
void printHelpCommands() {
  Serial.println("=== COMANDOS DISPONIVEIS ===");
  Serial.println("ABRIR_ENTRADA / OPEN_ENTRY - Abre cancela de entrada");
  Serial.println("FECHAR_ENTRADA / CLOSE_ENTRY - Fecha cancela de entrada");
  Serial.println("ABRIR_SAIDA / OPEN_EXIT - Abre cancela de saida");
  Serial.println("FECHAR_SAIDA / CLOSE_EXIT - Fecha cancela de saida");
  Serial.println("STATUS / GET_STATUS - Envia status atual");
  Serial.println("DEBUG / DEBUG_INFO - Mostra informacoes de debug");
  Serial.println("HELP / AJUDA - Mostra esta ajuda");
  Serial.println("=============================");
}

// ---- Função para enviar status para ESP32 ----
void sendStatusToESP32() {
  // Formato: VAGAS:estado1,estado2,...;ENTRADA:bool;SAIDA:bool;SENTRADA:estado;SSAIDA:estado
  Serial2.print("VAGAS:");
  for (int i = 0; i < 6; i++) {
    Serial2.print(estadoSensores[i]);
    if (i < 5) Serial2.print(",");
  }
  Serial2.print(";ENTRADA:");
  Serial2.print(entradaAberta ? "1" : "0");
  Serial2.print(";SAIDA:");
  Serial2.print(saidaAberta ? "1" : "0");
  Serial2.print(";SENTRADA:");
  Serial2.print(estadoEntrada);
  Serial2.print(";SSAIDA:");
  Serial2.print(estadoSaida);
  Serial2.println();
}
