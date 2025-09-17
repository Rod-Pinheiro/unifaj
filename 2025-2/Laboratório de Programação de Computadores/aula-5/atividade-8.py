lista = [int(number) for number in (input("Digite 6 numeros separados por espacos: ").split())]

lista.sort()

print(lista[-1], lista[0])