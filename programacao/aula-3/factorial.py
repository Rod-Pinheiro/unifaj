def factorial():
    result = 1
    number = int(input("Digite um numero para calcular o fatorial \n"))
    while number > 0:
        result = result * number
        number -= 1
    print(result)
factorial()
