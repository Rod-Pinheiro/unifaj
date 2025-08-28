# 2) Conversão de temperatura: Crie uma função que converte uma
# temperatura de Celsius para Fahrenheit Lembre-se (Q c x 9/5) + 32 =
# 32 F

def tempConverter(temp):
    farenheit = temp * 9/5 + 32
    return farenheit
    
temp = int(input("Digite uma temperatura em celsius \n"))

print(f'{tempConverter(temp)}')