# 6 – Crie uma lista com 5 notas de alunos e exiba a maior nota.

scores = [int(input("Digite uma nota: ")) for _ in range(5)]

scores.sort()

print(scores[-1])