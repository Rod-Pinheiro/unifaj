# 16 – Crie uma lista com 8 cidades e exiba apenas aquelas que possuem mais de 7 caracteres.

cities = [input("Digite um cidade: ") for _ in range(8)]

for city in cities:
    if len(city) > 7:
        print(city)