def countdown():
    n = int(input("Digite um número para iniciar a contagem regressiva: "))
    while n >= 0:
        print(n)
        n -= 1

countdown()