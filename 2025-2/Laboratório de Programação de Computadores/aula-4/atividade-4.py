# 4) Calculadora de Média: Crie uma função que calQlla a média de uma
# lista de números.

def calculateAverage(array):
    return sum(array) / len(array)

numbers = [float(interval) for interval in (input("Digite a lista de numeros separados por espaço\n").split())]

print(f'{calculateAverage(numbers)}')

