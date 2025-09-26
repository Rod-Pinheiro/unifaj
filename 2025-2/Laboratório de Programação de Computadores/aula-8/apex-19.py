# 19 – Crie uma lista com 12 números e exiba apenas os que estão entre 50 e 100.

numbers = [int(input("Digite um numero: ")) for _ in range(12)]

for number in numbers:
    if number >= 50 and number <= 100: print(number)