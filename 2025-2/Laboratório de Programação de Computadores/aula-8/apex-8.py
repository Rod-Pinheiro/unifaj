# 8 – Crie uma lista com 6 nomes e exiba-os em ordem inversa.


names = [input("Digite um nome: ") for _ in range(6)]


for name in names:
    print(name[::-1])