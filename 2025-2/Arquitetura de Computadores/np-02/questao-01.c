#include <stdio.h>

// Verifica se dois numeros sao pares ou impares e exibe o resultado
int availaNumeros(int n1, int n2)
{
    // Verificar se ambos sao pares, ambos impares, ou um de cada
    if (n1 % 2 == 0 && n2 % 2 == 0)
    {
        printf("Ambos os numeros sao pares");
    }
    if (n1 % 2 != 0 && n2 % 2 != 0)
    {
        printf("Ambos os numeros sao impar");
    }
    if (n1 % 2 == 0 && n2 % 2 != 0)
    {
        printf("O primeiro numero eh par e o segundo numero eh impar");
    }
    if (n1 % 2 != 0 && n2 % 2 == 0)
    {
        printf("O primeiro numero eh impar e o segundo numero eh par");
    }
    return 0;
}

int main()
{
    int n1, n2;
    printf("Digite dois numeros inteiros: ");
    scanf("%d %d", &n1, &n2);
    availaNumeros(n1, n2);

    return 0;
}