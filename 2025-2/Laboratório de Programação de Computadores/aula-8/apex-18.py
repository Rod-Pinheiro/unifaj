# 18 – Crie uma lista com 5 palavras e exiba-as em maiúsculas.

words = [input("Digite uma palavra: ") for _ in range(5)]

for word in words:
    print(word.upper())