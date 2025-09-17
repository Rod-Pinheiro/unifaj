lista = [str(color) for color in (input("Digite 3 cores separados por espacos: ").split())]

lista.append(input("Digite uma nova cor: "))

for color in lista:
  print(color)