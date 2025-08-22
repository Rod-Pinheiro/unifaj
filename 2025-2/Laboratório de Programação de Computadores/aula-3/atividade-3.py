# 3) Contagem Regressiva: Crie um algoritmo
# que solicite um número e imprima os valores em ordem decrescente.

def countdown():
    n = int(input("Digite um número para iniciar a contagem regressiva: "))
    while n >= 0:
        print(n)
        n -= 1

countdown()