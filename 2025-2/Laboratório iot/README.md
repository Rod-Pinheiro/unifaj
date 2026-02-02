# IoT Parking System

Sistema inteligente de gerenciamento de estacionamento com interface web e controle automatizado de cancelas.

## Visão Geral

Este projeto consiste em um sistema de estacionamento IoT composto por:
- **ESP32**: Servidor WiFi com interface web e API REST
- **Arduino**: Controle de sensores e servomotores
- **Interface Web**: Dashboard em tempo real para monitoramento e controle

## Arquitetura do Sistema

```
┌─────────────────┐    Serial (9600)    ┌─────────────────┐
│   ESP32 Server  │ ◄─────────────────► │   Arduino Uno   │
│                 │                     │                 │
│ • WiFi AP       │                     │ • 6 Sensores    │
│ • Web Server    │                     │   de Vaga       │
│ • API REST      │                     │ • 2 Sensores    │
│ • HTML/JS       │                     │   de Cancela    │
│                 │                     │ • 2 Servos      │
└─────────────────┘                     └─────────────────┘
         │                                       │
         ▼                                       ▼
┌─────────────────┐                     ┌─────────────────┐
│   Client Web    │                     │   Hardware      │
│   (Browser)     │                     │   (Sensores/    │
│                 │                     │    Servos)      │
└─────────────────┘                     └─────────────────┘
```

## Componentes de Hardware

### ESP32
- Placa de desenvolvimento ESP32
- Cria ponto de acesso WiFi
- Servidor web na porta 80

### Arduino Uno
- 6 sensores digitais para vagas (pinos 22-27)
- 2 sensores digitais para cancelas (pinos 28, 30)
- 2 servomotores para cancelas (pinos 9, 10)

### Conexões
```
Arduino Uno:
├── Sensores de Vaga: Pinos 22, 23, 24, 25, 26, 27
├── Sensor Entrada: Pino 28
├── Sensor Saída: Pino 30
├── Servo Entrada: Pino 9
└── Servo Saída: Pino 10

ESP32:
├── Serial2: Comunicação com Arduino
└── WiFi: Ponto de acesso "Estacionamento-IoT"
```

## Requisitos de Software

### Bibliotecas
- **ESP32**: 
  - `WiFi.h`
  - `WebServer.h`
  - `ArduinoJson.h`
- **Arduino**:
  - `Servo.h`

### Ferramentas
- Arduino IDE ou PlatformIO
- Monitor Serial (9600 baud)

## Instalação e Configuração

### 1. Preparação do Hardware
1. Monte os sensores nas vagas de estacionamento
2. Instale os servomotores nas cancelas de entrada/saída
3. Conecte todos os componentes conforme pinagem acima
4. Conecte ESP32 e Arduino via comunicação serial

### 2. Upload do Código
1. **Arduino Uno**:
   ```bash
   # Abra projeto-iot.cpp no Arduino IDE
   # Selecione placa "Arduino Uno"
   # Faça upload do código
   ```

2. **ESP32**:
   ```bash
   # Abra esp32-server.cpp no Arduino IDE
   # Selecione placa ESP32 apropriada
   # Faça upload do código
   ```

### 3. Configuração WiFi
- O ESP32 criará automaticamente um ponto de acesso:
  - **SSID**: `Estacionamento-IoT`
  - **Senha**: `12345678`
  - **IP**: Geralmente `192.168.4.1`

## Uso do Sistema

### Interface Web
1. Conecte-se ao WiFi "Estacionamento-IoT"
2. Abra o navegador e acesse `http://192.168.4.1`
3. Visualize o dashboard com:
   - Status das 6 vagas (ocupada/livre)
   - Status das cancelas (aberta/fechada)
   - Botões para controle manual das cancelas

### API REST
O sistema oferece endpoints para integração:

#### Status do Estacionamento
```http
GET /api/parking/status
```
Resposta:
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

#### Abrir Cancela
```http
POST /api/gate/entrance/open
POST /api/gate/exit/open
```
Resposta:
```json
{
  "status": "ok",
  "message": "Abrindo cancela de entrada"
}
```

## Protocolo de Comunicação

### ESP32 → Arduino
- `"STATUS"` - Solicita status atual
- `"ABRIR_ENTRADA"` - Abre cancela de entrada
- `"ABRIR_SAIDA"` - Abre cancela de saída

### Arduino → ESP32
Formato: `"VAGAS:1,0,1,0,1,0;ENTRADA:0;SAIDA:0;SENTRADA:0;SSAIDA:0"`

Onde:
- `VAGAS`: 6 valores (0=ocupada, 1=livre)
- `ENTRADA`: Estado da cancela (0=fechada, 1=aberta)
- `SAIDA`: Estado da cancela de saída
- `SENTRADA`: Sensor de entrada (0=detecção, 1=livre)
- `SSAIDA`: Sensor de saída

## Configurações de Tempo

- **Atualização de status**: 1 segundo
- **Auto-fechamento cancelas**: 2 segundos após abertura
- **Refresh interface web**: 2 segundos

## Debug e Monitoramento

### Monitor Serial Arduino
- Baud rate: 9600
- Mostra status das vagas em tempo real
- Exibe eventos das cancelas

### Monitor Serial ESP32
- Baud rate: 115200
- Mostra IP do ponto de acesso
- Exibe requisições HTTP

## Estrutura dos Arquivos

```
├── README.md              # Documentação do projeto
├── AGENTS.md              # Diretrizes para desenvolvimento
├── esp32-server.cpp       # Código do servidor ESP32
└── projeto-iot.cpp        # Código do Arduino Uno
```

## Personalização

### Alterar Senha WiFi
Edite `esp32-server.cpp`:
```cpp
const char* ssid = "Estacionamento-IoT";
const char* password = "NOVA_SENHA";
```

### Ajustar Número de Vagas
Modifique em ambos os arquivos:
- Array `vagas[6]` no Arduino
- Loop `for (int i = 0; i < 6; i++)` no ESP32

### Alterar Tempo de Fechamento
Edite `projeto-iot.cpp`:
```cpp
const unsigned long TEMPO_FECHAR = 3000; // 3 segundos
```

## Troubleshooting

### Problemas Comuns

**WiFi não conecta:**
- Verifique se o ESP32 está funcionando
- Reinicie o ESP32

**Sensores não funcionam:**
- Verifique conexões dos pinos
- Confirme alimentação dos sensores
- Use monitor serial para debug

**Servos não movem:**
- Verifique conexão de alimentação (servos precisam de 5V)
- Confirme pinos de sinal
- Teste servos individualmente

**Interface web não carrega:**
- Confirme conexão com o WiFi "Estacionamento-IoT"
- Verifique IP correto no navegador
- Use monitor serial do ESP32 para ver erros

### Debug Avançado

1. **Teste comunicação serial**:
   - Envie comandos manualmente pelo monitor serial
   - Verifique respostas do Arduino

2. **Teste sensores individualmente**:
   - Use código de teste simples para cada sensor
   - Verifique valores lidos (HIGH/LOW)

3. **Teste servos**:
   - Use exemplo da biblioteca Servo
   - Verifique movimento em 0° e 90°

## Licença

Projeto desenvolvido para fins educacionais na disciplina de Laboratório IoT.

## Contribuição

Siga as diretrizes em `AGENTS.md` para desenvolvimento e manutenção do código.