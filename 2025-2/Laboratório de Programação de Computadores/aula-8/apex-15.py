# 15 – Leia uma lista com 6 números e exiba o produto deles.

numbers = [1,2,3,4,5,6]

def multplyAll(arr):
    result = 1
    for number in arr:
        result *= number
    print(result)

multplyAll(numbers)