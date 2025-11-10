interface ParkingSpotProps {
  id: number;
  occupied: boolean;
  onClick?: () => void;
}

export default function ParkingSpot({ id, occupied, onClick }: ParkingSpotProps) {
  return (
    <div
      className={`
        p-4 text-center rounded-lg font-bold cursor-pointer transition-all duration-300
        ${occupied
          ? 'bg-red-500 text-white hover:bg-red-600'
          : 'bg-green-500 text-white hover:bg-green-600'
        }
      `}
      onClick={onClick}
    >
      <div className="text-lg">Vaga {id}</div>
      <div className="text-sm mt-1">
        {occupied ? 'Ocupada' : 'Livre'}
      </div>
    </div>
  );
}