# 5 – Crie uma lista com 12 números e calcule a soma dos números ímpares.

numbers = [int(input("Digite um numero: ")) for _ in range(12)]
odd = []

for number in numbers:
    if number % 2 != 0:
        odd.append(number)

print(sum(odd))