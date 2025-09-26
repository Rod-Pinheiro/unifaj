# 3 – Leia uma lista com 8 números e exiba o maior e o menor valor.

numberList = [5,3,6,7,8,4,1,10]

def biggerAndSmaller(arr):
    arr.sort()
    print(arr[-1], arr[0])

biggerAndSmaller(numberList)