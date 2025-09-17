lista = [str(animal) for animal in (input("Digite 5 animais separados por espacos: ").split())]

lista[2] = input("Digite um novo animal: ")

for animal in lista:
  print(animal)
