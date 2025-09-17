lista = [int(number) for number in (input("Digite 10 numeros separados por espaco: ").split())]

for number in lista:
  if(number > 50):
    print(number)