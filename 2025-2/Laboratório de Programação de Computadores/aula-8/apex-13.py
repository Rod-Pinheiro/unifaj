# 13 – Leia uma lista com 7 nomes e informe quantos têm mais de 6 letras.

names = ["Rodolfo", "Joao", "Maria", "Oswaldo", "Adriano", "Rodrigo", "Pedro"]

def countChars(arr):
    counter = 0
    for name in arr:
        if len(name) > 6:
            counter+=1
    print(counter)


countChars(names)