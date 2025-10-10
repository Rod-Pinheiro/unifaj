# importa biblioteca random do python
import random
# declara array vazio
numbers = []
# loop para iterar 15 vezes
for _ in range(15):
    # pendura inteiro random entre 1 e 200 no fim do array 
    numbers.append(random.randint(1,200))

# Declara variavel para armazenar a soma dos numeros    
sum = 0

# Loop para iterar entre os elementos do array
for number in numbers:
    # condicional para saber se o numero eh multiplo de 4 e maior que 50
    if number % 4 == 0 and number > 50:
        # soma valor do numero a variavel soma
        sum += number
        # imprime o numero na tela
        print(number)
        
# imprime o valor da variavel soma        
print("soma:", sum)