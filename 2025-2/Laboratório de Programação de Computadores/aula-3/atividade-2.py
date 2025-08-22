# 2) Crie um algoritmo em Python para
# calcular a quantidade de números pares e primos em um intervalo numérico. O
# usuário deverá informar o intervalo (mínimo e máximo). Exemplo: intervalo de 10
# a 100.

def primesAndEvens():
    interval = [int(interval) for interval in (input("Digite o intervalo separado por espaço para calcular os primos e pares \n").split())]
    counter = 0
    for number in range(interval[0], interval[1] + 1):
        notPrime = 0
        
        for value in range(2, number):
            if number % value == 0: 
                notPrime += 1
            
        if number % 2 == 0:
            counter += 1
        
        if notPrime == 0 and number != 1 and number > 0:
            counter += 1
         
    print(counter)

primesAndEvens()


