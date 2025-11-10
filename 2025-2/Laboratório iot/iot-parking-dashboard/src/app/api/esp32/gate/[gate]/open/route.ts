import { NextRequest, NextResponse } from 'next/server';

const ESP32_BASE_URL = process.env.ESP32_BASE_URL || 'http://192.168.4.1';

export async function POST(
  request: NextRequest,
  { params }: { params: Promise<{ gate: string }> }
) {
  const { gate } = await params;

  // Validate gate parameter
  if (!gate || !['entrance', 'exit'].includes(gate)) {
    return NextResponse.json(
      { error: 'Invalid gate parameter. Must be "entrance" or "exit"' },
      { status: 400 }
    );
  }

  try {
    const response = await fetch(`${ESP32_BASE_URL}/api/gate/${gate}/open`, {
      method: 'POST',
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
    console.error(`Error opening ${gate} gate:`, error);
    return NextResponse.json(
      {
        error: `Failed to open ${gate} gate`,
        details: error instanceof Error ? error.message : 'Unknown error'
      },
      { status: 500 }
    );
  }
}