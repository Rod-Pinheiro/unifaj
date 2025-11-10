import { NextResponse } from 'next/server';

const ESP32_BASE_URL = process.env.ESP32_BASE_URL || 'http://192.168.4.1';

export async function GET() {
  try {
    const response = await fetch(`${ESP32_BASE_URL}/api/parking/status`, {
      method: 'GET',
      headers: {
        'Content-Type': 'application/json',
      },
      // Add timeout for ESP32 requests
      signal: AbortSignal.timeout(5000),
    });

    if (!response.ok) {
      throw new Error(`ESP32 responded with status: ${response.status}`);
    }

    const data = await response.json();
    return NextResponse.json(data);
  } catch (error) {
    console.error('Error fetching parking status:', error);
    return NextResponse.json(
      {
        error: 'Failed to fetch parking status',
        details: error instanceof Error ? error.message : 'Unknown error'
      },
      { status: 500 }
    );
  }
}