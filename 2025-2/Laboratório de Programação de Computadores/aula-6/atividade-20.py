lista = [str(name) for name in (input("Digite 6 nomes separados por espaco: ").split())]

for name in lista:
  print(f"{name} tem {len(name)} letras")