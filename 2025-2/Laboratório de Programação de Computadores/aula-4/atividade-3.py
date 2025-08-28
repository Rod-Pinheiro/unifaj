# 3) Lista de Números Pares: Crie uma função que recebe um número inteiro
# positivo como argumento e retorna uma lista de números pares até esse
# número.

def printEvens(number):
    for numbers in range(0,number + 1) : 
        if numbers % 2 == 0:
            print(f'{numbers}') 
            
printEvens(int(input("Digite um numero \n")))