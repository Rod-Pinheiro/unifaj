#include <Servo.h>

// ---- Pinos dos servos ----
#define SERVO_ENTRADA 9
#define SERVO_SAIDA   10

Servo cancelaEntrada;
Servo cancelaSaida;

// ---- Sensores das vagas ----
int vagas[6] = { 22, 23, 24, 25, 26, 27 };
int estadoSensores[6];

// ---- Sensores das cancelas ----
int sensorEntrada = 28;
int sensorSaida   = 30;
int estadoEntrada;
int estadoSaida;

// ---- Controle de estados das cancelas ----
bool entradaAberta = false;
bool saidaAberta   = false;
unsigned long tempoEntrada = 0;
unsigned long tempoSaida   = 0;
const unsigned long TEMPO_FECHAR = 2000; // 2 segundos

void setup() {
  Serial.begin(9600);

  // Pinos das vagas
  for (int i = 0; i < 6; i++) {
    pinMode(vagas[i], INPUT);
  }

  // Pinos das cancelas
  pinMode(sensorEntrada, INPUT);
  pinMode(sensorSaida, INPUT);

  // Configura servos
  cancelaEntrada.attach(SERVO_ENTRADA);
  cancelaSaida.attach(SERVO_SAIDA);

  // Inicialmente fechadas
  cancelaEntrada.write(0);
  cancelaSaida.write(0);
}

void loop() {
  // Lê sensores das vagas
  for (int i = 0; i < 6; i++) {
    estadoSensores[i] = digitalRead(vagas[i]);
  }

  // Lê sensores das cancelas
  estadoEntrada = digitalRead(sensorEntrada);
  estadoSaida   = digitalRead(sensorSaida);

  // ---- Cancela da ENTRADA ----
  if (estadoEntrada == LOW && !entradaAberta) {
    abreEntrada();
    tempoEntrada = millis(); // marca o tempo que abriu
  }
  if (entradaAberta && millis() - tempoEntrada > TEMPO_FECHAR) {
    fechaEntrada();
  }

  // ---- Cancela da SAÍDA ----
  if (estadoSaida == LOW && !saidaAberta) {
    abreSaida();
    tempoSaida = millis(); // marca o tempo que abriu
  }
  if (saidaAberta && millis() - tempoSaida > TEMPO_FECHAR) {
    fechaSaida();
  }

  // ---- Mostrar vagas no Serial ----
  for (int i = 0; i < 6; i++) {
    Serial.print("Vaga ");
    Serial.print(i + 1);
    if (estadoSensores[i] == LOW) {
      Serial.println(": OCUPADA");
    } else {
      Serial.println(": LIVRE");
    }
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
  cancelaSaida.write(90);  
  saidaAberta = true;
  Serial.println("Cancela SAÍDA aberta");
}
void fechaSaida() {
  cancelaSaida.write(0);  
  saidaAberta = false;
  Serial.println("Cancela SAÍDA fechada");
}
