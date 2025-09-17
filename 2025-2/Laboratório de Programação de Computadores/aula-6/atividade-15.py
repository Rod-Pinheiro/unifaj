lista = [str(word) for word in (input("Digite 6 palavras separadas por espaco: ").split())]

for word in lista:
  if(len(word) > 5):
    print(word)
