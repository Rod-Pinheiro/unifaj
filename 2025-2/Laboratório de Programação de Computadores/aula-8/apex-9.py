# 9 – Leia uma lista com 15 números e exiba a quantidade de números maiores que 100.

numbers = [1,2,3,4,5,6,7,8,9,100,200,300,400,500,600]

def biggerThan100(arr):
    biggerThan100 = []
    for number in arr:
        if number > 100:
            biggerThan100.append(number)
    print(len(biggerThan100))


biggerThan100(numbers)