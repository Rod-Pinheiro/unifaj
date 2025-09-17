lista = [int(number) for number in (input("Digite 6 numeros separados por espacos: ").split())]

for number in range(0,6):
  if lista[number] % 2 == 0:
    print(lista[number])