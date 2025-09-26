# 14 – Crie uma lista com 20 números e exiba apenas os números na posição par da lista.

numbers = [int(input("Digite um numero: ")) for _ in range(20)]

for index in range(len(numbers)):
    if index % 2 == 0:
        print(numbers[index])