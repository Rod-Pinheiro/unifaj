# Declara array de strings
cities = ["poiu", "sdfg", "qwer", "asdf"]
# Declara funcao
def filtra_cidades(arr):
    # Faz o cast do parametro de funcao para uma lista
    arr = list(arr)
    # Declara contados
    counter = 0
    # Loop que itera entre os elementos do array
    for city in arr:
        # Verifica se cidade comeca com as letras "p" ou "s"
        if city.lower().startswith("p") or city.lower().startswith("s"):
            # Soma 1 ao contador
            counter += 1
            # Imprime a cidade que comeca com as letras "p" ou "s"
            print(city)
    # Ordena o array
    arr.sort()
    # Imprime a quantidade e o array ordenado
    print("quantidade", counter, arr)            
# Chama a funcao
filtra_cidades(cities)