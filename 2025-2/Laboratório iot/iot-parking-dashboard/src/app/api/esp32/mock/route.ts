import { NextResponse } from 'next/server';

export async function GET() {
  return NextResponse.json({
    parking: [
      { id: 1, occupied: false },
      { id: 2, occupied: true },
      { id: 3, occupied: false },
      { id: 4, occupied: true },
      { id: 5, occupied: false },
      { id: 6, occupied: false }
    ],
    gates: {
      entrance: { open: false, sensor: false },
      exit: { open: false, sensor: false }
    }
  });
}

export async function POST(request: Request) {
  try {
    const body = await request.json();
    const { gate } = body;

    return NextResponse.json({
      status: 'ok',
      message: `Abrindo cancela de ${gate === 'entrance' ? 'entrada' : 'saída'}`
    });
  } catch (error) {
    return NextResponse.json({ error: 'Mock gate error' }, { status: 500 });
  }
}