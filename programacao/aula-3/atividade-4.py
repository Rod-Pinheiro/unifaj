# 4) Tabuada: Peça ao usuário um número e, em
# seguida, use um loop para exibir a tabuada desse número de 1 a 10.

def multiply():
    number = int(input("Digite um número para fazer a multiplicação \n"))
    multiplicator = 10
    while multiplicator >= 1:
        print(number * multiplicator)
        multiplicator -= 1

multiply()
