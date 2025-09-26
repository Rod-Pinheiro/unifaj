# 2 – Crie uma lista com 7 nomes e exiba-os em ordem alfabética.

names = [input("Digite um nome: ") for _ in range(7)]
names.sort()
for name in names:
    print (name)