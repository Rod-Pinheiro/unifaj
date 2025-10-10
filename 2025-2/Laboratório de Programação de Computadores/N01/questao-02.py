# Declara array de nomes
names = ["aaa","aaa","aa"]
# Declara funcao
def analisa_nomes(arr):
    # faz o cast do parametro da funcao pro tipo lista
    arr = list(arr)
    # Ordena a lista
    arr.sort()
    # Declara contador
    counter = 0
    # Loop para iterar entre os elemetos do array
    for name in arr:
        # soma o valor do comprimento da string ao valor de counter
        counter += len(name)
        
    # Imprime a menor(posicao 0) a maior(posicao -1) e a media com duas casas decimais    
    print("Menos letras:", arr[0], "Mais letras:", arr[-1], "Media de caracteres por nome:", round(counter / len(arr), 2))

# Chama a funcao
analisa_nomes(names)