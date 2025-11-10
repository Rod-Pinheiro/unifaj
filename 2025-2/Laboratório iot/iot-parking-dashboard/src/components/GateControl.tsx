import { useState } from 'react';

interface GateControlProps {
  type: 'entrance' | 'exit';
  isOpen: boolean;
  isLoading: boolean;
  onOpen: () => void;
}

export default function GateControl({ type, isOpen, isLoading, onOpen }: GateControlProps) {
  const [isAnimating, setIsAnimating] = useState(false);

  const handleOpen = async () => {
    setIsAnimating(true);
    await onOpen();
    // Reset animation after a short delay
    setTimeout(() => setIsAnimating(false), 500);
  };

  const gateName = type === 'entrance' ? 'Entrada' : 'Saída';
  const buttonText = `Abrir ${gateName}`;

  return (
    <div className={`
      p-4 text-center rounded-lg min-w-[200px] transition-all duration-300
      ${isOpen
        ? 'bg-yellow-500 text-white'
        : 'bg-gray-600 text-white'
      }
      ${isAnimating ? 'animate-pulse' : ''}
    `}>
      <h3 className="text-lg font-bold mb-2">{gateName}</h3>
      <div className="text-sm mb-3">
        {isOpen ? 'Aberta' : 'Fechada'}
      </div>
      <button
        onClick={handleOpen}
        disabled={isLoading}
        className={`
          px-4 py-2 rounded font-semibold transition-all duration-200
          ${isLoading
            ? 'bg-gray-400 cursor-not-allowed'
            : 'bg-green-600 hover:bg-green-700 active:bg-green-800'
          }
          text-white
        `}
      >
        {isLoading ? 'Abrindo...' : buttonText}
      </button>
    </div>
  );
}