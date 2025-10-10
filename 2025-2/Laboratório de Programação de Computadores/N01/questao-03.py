# Pede 10 vezes que o usuario digite um numero
numbers = [int(input("Insira um numero: ")) for _ in range(10)]
# Declara variaveis para armazenar valores
sumEven = 0
multOdd = 1

# Loop que itera entre os elementos de numbers
for number in numbers:
    # Condicional para saber se eh par
    if number % 2 == 0:
        # Soma o valor da variavel com o valor do elemento
        sumEven += number
    else:
        #Caso seja impar ele multiplica
        multOdd *= number

# Imprime os valores da soma do produto e a media com 2 casas decimais
print("Soma dos pares:", sumEven, "Produto dos impares:", multOdd,"Media dos valores:", round(sum(numbers)/len(numbers)))