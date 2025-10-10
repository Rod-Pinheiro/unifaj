# Declara array de strings
words = ["abcdef", "abcdefgh", "abc", "abc", "abc","abc","abc", "abc"]
# Declara contador
counter = 0
# Loop que itera entre os elementos de words
for word in words:
    # Imprime string reversa e em maiusculas
    print(word.upper()[::-1])
    # Verifica se palavra tem mais que 5 caracteres
    if len(word) > 5:
        # Soma 1 ao contador
        counter += 1
        
 # Imprime o contador       
print(counter)