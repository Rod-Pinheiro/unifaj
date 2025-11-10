# IoT Parking Dashboard

A modern Next.js dashboard for monitoring and controlling an IoT parking system built with ESP32.

## Features

- **Real-time Monitoring**: Live status of 6 parking spots
- **Gate Control**: Remote control of entrance and exit gates
- **Responsive Design**: Works on desktop and mobile devices
- **Auto-refresh**: Updates every 2 seconds
- **Error Handling**: Graceful fallbacks and error messages
- **Mock Data**: Built-in mock API for testing without hardware

## Tech Stack

- **Next.js 15** - React framework with App Router
- **TypeScript** - Type-safe development
- **Tailwind CSS** - Utility-first CSS framework
- **ESP32** - IoT microcontroller backend

## Getting Started

### Prerequisites

- Node.js 18+
- ESP32 with the parking system firmware

### Installation

1. Install dependencies:
```bash
npm install
```

2. Configure environment variables:
```bash
cp .env.local.example .env.local
```

Edit `.env.local` with your ESP32 configuration:
```env
ESP32_BASE_URL=http://192.168.4.1
ESP32_WIFI_SSID=Estacionamento-IoT
ESP32_WIFI_PASSWORD=12345678
```

3. Start the development server:
```bash
npm run dev
```

4. Open [http://localhost:3000](http://localhost:3000) in your browser.

## ESP32 Configuration

### Network Setup
The ESP32 creates a WiFi access point with these default settings:
- **SSID**: `Estacionamento-IoT`
- **Password**: `12345678`
- **IP Address**: `192.168.4.1` (when in AP mode)

Connect your device to the "Estacionamento-IoT" WiFi network to access the dashboard.

### ESP32 Address Configuration

The ESP32 IP address is configured through environment variables:

#### Environment Variables (`.env.local`)
```env
# ESP32 Configuration
ESP32_BASE_URL=http://192.168.4.1
ESP32_WIFI_SSID=Estacionamento-IoT
ESP32_WIFI_PASSWORD=12345678
```

#### Code Implementation
The address is used in two API route files with automatic fallback:

**File**: `src/app/api/esp32/status/route.ts`
```typescript
const ESP32_BASE_URL = process.env.ESP32_BASE_URL || 'http://192.168.4.1';
```

**File**: `src/app/api/esp32/gate/[gate]/open/route.ts`
```typescript
const ESP32_BASE_URL = process.env.ESP32_BASE_URL || 'http://192.168.4.1';
```

#### Changing the ESP32 Address
1. Edit `.env.local`:
```env
ESP32_BASE_URL=http://YOUR_NEW_IP_ADDRESS
```

2. Restart the development server:
```bash
npm run dev
```

### Automatic Fallback System
The dashboard automatically switches between real ESP32 data and mock data:

- **Primary**: Connects to ESP32 at configured `ESP32_BASE_URL`
- **Fallback**: Uses mock data when ESP32 is unreachable
- **Seamless**: No manual configuration needed - happens automatically
- **Testing**: Mock data enables development without hardware

## ESP32 API Endpoints

The dashboard expects the ESP32 to be running firmware that provides these endpoints:

### GET `/api/parking/status`
Returns parking and gate status:
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

### POST `/api/gate/{entrance|exit}/open`
Opens the specified gate and returns:
```json
{
  "status": "ok",
  "message": "Abrindo cancela de entrada"
}
```

## API Routes

The Next.js app provides proxy routes to handle CORS and provide fallbacks:

- `/api/esp32/status` - Proxies to ESP32 status endpoint
- `/api/esp32/gate/[gate]/open` - Proxies to ESP32 gate control
- `/api/esp32/mock` - Mock data for testing

## Project Structure

```
src/
├── app/
│   ├── api/esp32/          # API proxy routes
│   ├── globals.css         # Global styles and Tailwind config
│   ├── layout.tsx          # Root layout
│   └── page.tsx            # Main dashboard
├── components/
│   ├── ParkingSpot.tsx     # Individual parking space component
│   └── GateControl.tsx     # Gate control component
└── hooks/
    └── useParkingData.ts   # Data fetching and state management
```

## Development

### Available Scripts

- `npm run dev` - Start development server
- `npm run build` - Build for production
- `npm run start` - Start production server
- `npm run lint` - Run ESLint

### Testing

The app includes mock data endpoints for testing without ESP32 hardware. When the ESP32 is unavailable, it automatically falls back to mock data.

## Docker Deployment

### Prerequisites
- Docker and Docker Compose installed
- ESP32 device accessible from the Docker host

### Quick Start

1. **Build and run with Docker Compose:**
```bash
docker-compose up -d
```

2. **Access the dashboard:**
Open [http://localhost:3000](http://localhost:3000) in your browser.

3. **Configure ESP32 URL (optional):**
Create a `.env` file or set environment variable:
```bash
echo "ESP32_BASE_URL=http://your-esp32-ip" > .env
docker-compose up -d --force-recreate
```

### Docker Commands

- **Build and start:** `docker-compose up -d`
- **View logs:** `docker-compose logs -f`
- **Stop:** `docker-compose down`
- **Rebuild:** `docker-compose build --no-cache`
- **Shell access:** `docker-compose exec iot-parking-dashboard sh`

### Environment Variables

Create a `.env` file from the example:
```bash
cp .env.example .env
```

Key variables:
- `ESP32_BASE_URL` - ESP32 device URL (default: `http://192.168.4.1`)
- `PORT` - Dashboard port (default: `3000`)
- `NODE_ENV` - Environment (default: `production`)

### Production Deployment

1. **Build the application:**
```bash
npm run build
```

2. **Start the production server:**
```bash
npm start
```

3. **Or use Docker for production:**
```bash
docker-compose -f docker-compose.yml up -d
```

For deployment to platforms like Vercel, ensure the ESP32 is accessible from the deployment environment.
