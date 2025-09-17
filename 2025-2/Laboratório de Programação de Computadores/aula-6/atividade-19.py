lista = [float(score) for score in (input("Digite as 4 notas separadas por espaco: ").split())]

if( sum(lista) / len(lista) >= 7):
  print("Aprovado")
else:
  print("Reprovado")