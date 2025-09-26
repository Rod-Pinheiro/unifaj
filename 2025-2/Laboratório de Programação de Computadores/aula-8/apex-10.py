# 10 – Crie uma lista com 8 palavras e exiba aquelas que terminam com a letra 'o'.

words = [input("Digite uma palavra: ") for _ in range(8)]

for word in words:
    if word.lower().endswith("o"):
        print(word)