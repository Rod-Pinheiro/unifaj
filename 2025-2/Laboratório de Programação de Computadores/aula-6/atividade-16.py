lista = [int(number) for number in (input("Digite 8 numeros inteiros separados por espaco: ").split())]

lista.reverse()

for number in lista:
  print(number)
