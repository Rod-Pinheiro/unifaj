def fibo():
    number = int(input("Digite um numero para gerar a sequencia \n"))
    a,b = 0,1
    print(a)
    while number > b:
        print(b)
        a, b = b, a + b
        

fibo()
