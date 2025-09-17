lista = [int(number) for number in (input("Digite 7 numeros separados por espaco: ").split())]

number = int(input("Digite um numero para ver se esta na lista anterior."))

if lista.count(number) > 0:
  print(f"O numero {number} esta na lista")
else:
  print(f"O numero {number} nao esta na lista")