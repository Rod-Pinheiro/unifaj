lista = [int(number) for number in (input("Digite 8 numeros separados por espacos: ").split())]

for number in range(0,8):
  if lista[number] % 2 != 0:
    print(lista[number])


