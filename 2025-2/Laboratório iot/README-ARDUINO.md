# 🚗 Sistema de Estacionamento IoT

Projeto de estacionamento inteligente utilizando Arduino Mega, ESP32 e interface web para monitoramento e controle remoto.

## 📋 Descrição do Projeto

Sistema completo de gerenciamento de estacionamento com 6 vagas, cancelas automatizadas de entrada e saída, sensores de presença, LEDs indicadores e dashboard web para monitoramento em tempo real.

### Componentes Principais
- **Arduino Mega**: Controle dos servos, sensores e LEDs
- **ESP32**: Servidor web e comunicação WiFi
- **Display LCD**: Mostra quantidade de vagas disponíveis
- **Sensores**: Detecção de veículos nas vagas e cancelas
- **Servos**: Controle das cancelas de entrada e saída
- **LEDs**: Indicação visual do status das vagas

## 🔧 Hardware Necessário

### Arduino Mega
- 2 Servomotores (cancelas entrada/saída)
- 6 Sensores digitais (vagas 1-6)
- 2 Sensores digitais (cancelas entrada/saída)
- 6 LEDs (indicação das vagas)
- Display LCD I2C 16x2
- Jumpers e protoboard

### ESP32
- Módulo ESP32 DevKit
- Conexão serial com Arduino (pinos 16/17)

## 📁 Estrutura dos Arquivos

```
├── projeto-iot.cpp          # Código principal do Arduino Mega
├── esp32-server.cpp         # Código do servidor ESP32
├── README.md               # Este arquivo
└── iot-parking-dashboard/  # Dashboard web (Next.js)
```

## 🔌 Conexões Hardware

### Arduino Mega - Pinout
```
Servos:
- Servo Entrada: Pino 6
- Servo Saída:   Pino 7

Sensores das Vagas:
- Vaga 1: Pino 22
- Vaga 2: Pino 24
- Vaga 3: Pino 26
- Vaga 4: Pino 28
- Vaga 5: Pino 30
- Vaga 6: Pino 32

LEDs das Vagas:
- LED Vaga 1: Pino 36
- LED Vaga 2: Pino 38
- LED Vaga 3: Pino 40
- LED Vaga 4: Pino 42
- LED Vaga 5: Pino 44
- LED Vaga 6: Pino 46

Sensores das Cancelas:
- Sensor Entrada: Pino 9
- Sensor Saída:   Pino 10

Display LCD I2C:
- SDA: Pino A4
- SCL: Pino A5

Comunicação ESP32:
- Serial2: Pinos 16 (RX2), 17 (TX2)
```

### ESP32 - Pinout
```
Comunicação Arduino:
- RX: Pino 16
- TX: Pino 17

WiFi Access Point:
- SSID: "Estacionamento-IoT"
- Senha: "12345678"
- IP: 192.168.4.1
```

## 💻 Instalação e Configuração

### 1. Preparar o Ambiente
- Instalar Arduino IDE
- Instalar bibliotecas necessárias:
  - `Servo.h`
  - `LiquidCrystal_I2C.h`
  - `WiFi.h` (ESP32)
  - `WebServer.h` (ESP32)
  - `ArduinoJson.h` (ESP32)

### 2. Compilar e Carregar

#### Arduino Mega
```bash
# No Arduino IDE:
# 1. Abrir projeto-iot.cpp
# 2. Selecionar placa: Arduino Mega
# 3. Selecionar porta COM correta
# 4. Compilar e carregar
```

#### ESP32
```bash
# No Arduino IDE:
# 1. Abrir esp32-server.cpp
# 2. Selecionar placa: ESP32 Dev Module
# 3. Selecionar porta COM correta
# 4. Compilar e carregar
```

### 3. Dashboard Web (Opcional)
```bash
cd iot-parking-dashboard
npm install
npm run dev
```

## 🚀 Funcionamento

### Sistema Arduino
1. **Monitoramento Contínuo**: Lê sensores das vagas a cada 500ms
2. **Controle Automático**: Cancelas abrem automaticamente com detecção de veículo
3. **Temporização**: Cancelas fecham após 2 segundos (automático) ou 10 segundos (manual)
4. **Comunicação Serial**: Envia status para ESP32 a cada 1 segundo
5. **Display LCD**: Mostra quantidade de vagas livres em tempo real

### Sistema ESP32
1. **Access Point**: Cria rede WiFi "Estacionamento-IoT"
2. **Servidor Web**: Interface web no IP 192.168.4.1
3. **API REST**: Endpoints para controle e monitoramento
4. **Comunicação**: Recebe dados do Arduino via Serial2

### Interface Web
- Dashboard em tempo real
- Controle manual das cancelas
- Visualização do status das vagas
- Design responsivo

## 📡 API Endpoints

### GET /api/parking/status
Retorna status completo do estacionamento:
```json
{
  "parking": [
    {"id": 1, "occupied": false},
    {"id": 2, "occupied": true},
    ...
  ],
  "gates": {
    "entrance": {"open": false, "sensor": false},
    "exit": {"open": false, "sensor": false}
  }
}
```

### POST /api/gate/entrance/open
Abre cancela de entrada manualmente

### POST /api/gate/exit/open
Abre cancela de saída manualmente

## 🎮 Comandos Serial

### Via Monitor Serial (Arduino)
```
ABRIR_ENTRADA / OPEN_ENTRY     - Abre cancela de entrada
FECHAR_ENTRADA / CLOSE_ENTRY   - Fecha cancela de entrada
ABRIR_SAIDA / OPEN_EXIT        - Abre cancela de saída
FECHAR_SAIDA / CLOSE_EXIT      - Fecha cancela de saída
STATUS / GET_STATUS            - Envia status atual
DEBUG / DEBUG_INFO             - Mostra informações de debug
HELP / AJUDA                   - Lista comandos disponíveis
```

## 🔧 Configurações

### Tempos de Operação
```cpp
const unsigned long TEMPO_FECHAR = 2000;           // 2 segundos (automático)
const unsigned long TEMPO_FECHAR_MANUAL = 10000;    // 10 segundos (manual)
const unsigned long SEND_INTERVAL = 1000;          // 1 segundo (envio status)
```

### WiFi (ESP32)
```cpp
const char* ssid = "Estacionamento-IoT";
const char* password = "12345678";
```

## 🐛 Troubleshooting

### Problemas Comuns

1. **Servos não movem**
   - Verificar alimentação (servos precisam de fonte externa)
   - Confirmar pinos 6 e 7

2. **Sensores não detectam**
   - Verificar lógica invertida (LOW = carro presente)
   - Testar com multímetro

3. **Display não funciona**
   - Verificar endereço I2C (geralmente 0x27)
   - Confirmar conexões SDA/SCL

4. **ESP32 não conecta**
   - Verificar comunicação serial (pinos 16/17)
   - Confirmar baud rate 9600

5. **WiFi não acessível**
   - Aguardar inicialização completa
   - Verificar IP: 192.168.4.1

### Debug
- Usar comando `DEBUG` no monitor serial
- Verificar comunicação entre Arduino e ESP32
- Testar endpoints via Postman ou curl

## 📱 Acesso ao Sistema

1. **Conectar na rede**: "Estacionamento-IoT" (senha: 12345678)
2. **Acessar dashboard**: http://192.168.4.1
3. **Monitor serial**: 9600 baud para debug


## 📄 Licença

MIT License - Livre para uso educacional e comercial.


---

**Desenvolvido para disciplina de Internet das Coisas** 🎓