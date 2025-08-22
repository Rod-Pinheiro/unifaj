# 1) Crie um algoritmo em Python para
# calcular a média de 3 atividades.

def calculateAverage():
    notas = [int(nota) for nota in (input("Digite as 3 notas separadas por espaço").split())]
    print(sum(notas)/3)

calculateAverage()