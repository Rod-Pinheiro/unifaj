# Declara array de numeros
numbers = [1,2,3,4,5,6,7,8,9,10,11,12]
# Declara array para armazenar os quadrados
sqrNumbers= []
# Loop que gera os indices de 0 ao comprimento do array
for index in range(len((numbers))):
    # Condicional que verifica se eh par
    if index % 2 == 0:
        # Adiciona o quadrado no novo array
        sqrNumbers.append(numbers[index] * numbers[index])
        # Imprime o valor na posicao do indice
        print(numbers[index])
# Imprime array de numeros quadrados
print(sqrNumbers)