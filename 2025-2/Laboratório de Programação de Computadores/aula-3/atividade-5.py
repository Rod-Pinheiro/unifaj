# 5) Sequência de Fibonacci: Crie um programa que solicite um número
# ao usuário e, em seguida, use um loop while para gerar e exibir a sequência de Fibonacci até
# o número especificado.

def fibo():
    number = int(input("Digite um numero para gerar a sequencia \n"))
    a,b = 0,1
    print(a)
    while number > b:
        print(b)
        a, b = b, a + b
        

fibo()
