import { useState, useEffect, useCallback } from 'react';

interface ParkingSpot {
  id: number;
  occupied: boolean;
}

interface Gate {
  open: boolean;
  sensor: boolean;
}

interface ParkingData {
  parking: ParkingSpot[];
  gates: {
    entrance: Gate;
    exit: Gate;
  };
}

interface UseParkingDataReturn {
  data: ParkingData | null;
  loading: boolean;
  error: string | null;
  openGate: (gate: 'entrance' | 'exit') => Promise<void>;
  refreshData: () => Promise<void>;
}

export function useParkingData(): UseParkingDataReturn {
  const [data, setData] = useState<ParkingData | null>(null);
  const [loading, setLoading] = useState(true);
  const [error, setError] = useState<string | null>(null);

  const fetchData = useCallback(async () => {
    try {
      setLoading(true);
      setError(null);

      // Try ESP32 first, fallback to mock data
      let response;
      try {
        response = await fetch('/api/esp32/status');
        if (!response.ok) {
          throw new Error(`ESP32 HTTP error: ${response.status}`);
        }
      } catch (esp32Error) {
        console.warn('ESP32 not available, using mock data:', esp32Error);
        response = await fetch('/api/esp32/mock');
        if (!response.ok) {
          throw new Error(`Mock HTTP error: ${response.status}`);
        }
      }

      const parkingData: ParkingData = await response.json();
      setData(parkingData);
    } catch (err) {
      const errorMessage = err instanceof Error ? err.message : 'Unknown error';
      setError(`Failed to fetch parking data: ${errorMessage}`);
      console.error('Error fetching parking data:', err);
    } finally {
      setLoading(false);
    }
  }, []);

  const openGate = useCallback(async (gate: 'entrance' | 'exit') => {
    try {
      setError(null);

      // Try ESP32 first, fallback to mock data
      let response;
      try {
        response = await fetch(`/api/esp32/gate/${gate}/open`, {
          method: 'POST',
          headers: {
            'Content-Type': 'application/json',
          },
        });
        if (!response.ok) {
          throw new Error(`ESP32 HTTP error: ${response.status}`);
        }
      } catch (esp32Error) {
        console.warn('ESP32 not available, using mock data:', esp32Error);
        response = await fetch(`/api/esp32/mock`, {
          method: 'POST',
          headers: {
            'Content-Type': 'application/json',
          },
          body: JSON.stringify({ gate }),
        });
        if (!response.ok) {
          throw new Error(`Mock HTTP error: ${response.status}`);
        }
      }

      const result = await response.json();

      // Refresh data after opening gate
      await fetchData();

      // Show success message (you might want to use a toast library)
      alert(result.message || `Cancela de ${gate === 'entrance' ? 'entrada' : 'saída'} aberta com sucesso`);

    } catch (err) {
      const errorMessage = err instanceof Error ? err.message : 'Unknown error';
      setError(`Failed to open gate: ${errorMessage}`);
      console.error('Error opening gate:', err);
      throw err; // Re-throw so the component can handle it
    }
  }, [fetchData]);

  const refreshData = useCallback(async () => {
    await fetchData();
  }, [fetchData]);

  // Auto-refresh every 2 seconds
  useEffect(() => {
    fetchData(); // Initial fetch

    const interval = setInterval(fetchData, 2000);

    return () => clearInterval(interval);
  }, [fetchData]);

  return {
    data,
    loading,
    error,
    openGate,
    refreshData,
  };
}