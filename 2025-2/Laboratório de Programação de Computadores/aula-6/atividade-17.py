lista = [str(movie) for movie in (input("Digite 5 filmes separados por espaco: ").split())]

lista[0] = input("Digite um novo filme: ")

for movie in lista: print(movie)