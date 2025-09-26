# 17 – Leia uma lista com 10 números e informe quantos são negativos.

numbers = [-5,-4,-3,-2,-1,0,1,2,3,4]

def checkNegatives(arr):
    counter = 0
    for number in arr:
        if number < 0:
            counter += 1
    print(counter)

checkNegatives(numbers)