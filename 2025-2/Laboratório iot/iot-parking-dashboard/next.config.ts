import type { NextConfig } from "next";

const nextConfig: NextConfig = {
  // Enable standalone output for Docker
  output: 'standalone',
  
  // Configure hostname for Docker environment
  hostname: '0.0.0.0',
  
  // Port configuration
  port: parseInt(process.env.PORT || '3000', 10),
  
  // API rewrites for ESP32 communication
  async rewrites() {
    return [
      {
        source: '/api/esp32/:path*',
        destination: `${process.env.ESP32_BASE_URL || 'http://192.168.4.1'}/api/:path*`,
      },
    ];
  },
  
  // Environment variables for client-side
  env: {
    ESP32_BASE_URL: process.env.ESP32_BASE_URL || 'http://192.168.4.1',
  },
};

export default nextConfig;
