# 20 – Leia uma lista com 6 nomes e exiba o primeiro e o último nome digitado.

names = [input("Digite um nome: ") for _ in range(6)]

print(names[0], names[-1])