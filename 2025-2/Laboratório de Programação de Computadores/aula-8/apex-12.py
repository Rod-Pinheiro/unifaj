# 12 – Crie uma lista com 10 números e exiba a soma total.

numbers = [int(input("Digite um numero: ")) for _ in range(10)]

print(sum(numbers))
