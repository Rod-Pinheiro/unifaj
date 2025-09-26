# 1 - Crie uma lista com 10 números inteiros aleatórios e exiba apenas os números pares.

numbers = [int(input("Insira um numero: ")) for _ in range(10)]
for number in numbers:
    if number % 2 == 0:
        print(number)

