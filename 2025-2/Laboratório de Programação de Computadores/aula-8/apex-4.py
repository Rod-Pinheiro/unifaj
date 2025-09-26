# 4 – Crie uma lista com 6 palavras e exiba apenas aquelas que começam com a letra 'A'.

words = [input("Digite um palavra: ") for _ in range(6)]

for word in words:
    if word.lower().startswith("a"):
        print(word)