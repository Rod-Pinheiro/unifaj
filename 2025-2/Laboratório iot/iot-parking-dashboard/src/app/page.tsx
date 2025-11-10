'use client';

import { useParkingData } from '@/hooks/useParkingData';
import ParkingSpot from '@/components/ParkingSpot';
import GateControl from '@/components/GateControl';

export default function Home() {
  const { data, loading, error, openGate } = useParkingData();

  const handleOpenGate = async (gate: 'entrance' | 'exit') => {
    try {
      await openGate(gate);
    } catch (err) {
      // Error is already handled in the hook
      console.error('Failed to open gate:', err);
    }
  };

  return (
    <div className="min-h-screen bg-gray-100 py-8 px-4">
      <div className="max-w-4xl mx-auto">
        {/* Header */}
        <div className="text-center mb-8">
          <h1 className="text-4xl font-bold text-gray-800 mb-2">
            🚗 Estacionamento IoT
          </h1>
          <p className="text-gray-600">
            Sistema de monitoramento e controle de estacionamento inteligente
          </p>
        </div>

        {/* Error Display */}
        {error && (
          <div className="bg-red-100 border border-red-400 text-red-700 px-4 py-3 rounded mb-6">
            <strong>Erro:</strong> {error}
          </div>
        )}

        {/* Loading State */}
        {loading && !data && (
          <div className="text-center py-12">
            <div className="animate-spin rounded-full h-12 w-12 border-b-2 border-blue-500 mx-auto"></div>
            <p className="mt-4 text-gray-600">Carregando dados do estacionamento...</p>
          </div>
        )}

        {/* Parking Grid */}
        {data && (
          <div className="bg-white rounded-lg shadow-lg p-6 mb-6">
            <h2 className="text-2xl font-bold text-gray-800 mb-4 text-center">
              Status das Vagas
            </h2>
            <div className="grid grid-cols-1 sm:grid-cols-2 lg:grid-cols-3 gap-4">
              {data.parking.map((spot) => (
                <ParkingSpot
                  key={spot.id}
                  id={spot.id}
                  occupied={spot.occupied}
                />
              ))}
            </div>
          </div>
        )}

        {/* Gate Controls */}
        {data && (
          <div className="bg-white rounded-lg shadow-lg p-6">
            <h2 className="text-2xl font-bold text-gray-800 mb-4 text-center">
              Controle das Cancelas
            </h2>
            <div className="flex flex-col sm:flex-row justify-center gap-6">
              <GateControl
                type="entrance"
                isOpen={data.gates.entrance.open}
                isLoading={loading}
                onOpen={() => handleOpenGate('entrance')}
              />
              <GateControl
                type="exit"
                isOpen={data.gates.exit.open}
                isLoading={loading}
                onOpen={() => handleOpenGate('exit')}
              />
            </div>
          </div>
        )}

        {/* Footer */}
        <div className="text-center mt-8 text-gray-500 text-sm">
          <p>Conectado ao ESP32 via WiFi: Estacionamento-IoT</p>
          <p>Atualização automática a cada 2 segundos</p>
        </div>
      </div>
    </div>
  );
}
