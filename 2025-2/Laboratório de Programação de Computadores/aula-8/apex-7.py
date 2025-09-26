# 7 – Leia uma lista com 10 números e exiba apenas os números múltiplos de 3.

numbers = [int(input("Digite um numero: ")) for _ in range(10)]

for number in numbers:
    if number % 3 == 0:
        print(number)