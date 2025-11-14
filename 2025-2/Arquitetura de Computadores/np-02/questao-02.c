#include <stdio.h>

// Conta pares e impares em um array e retorna qual tipo predomina
int parOuImpar(int arr[10])
{
    int par= 0; 
    int impar= 0;
    // Contar pares e impares
    for (int i = 0; i < 10; i++)
    {
        printf("%d", arr[i]);
        if (arr[i] % 2 == 0)
        {
            par += 1;
        }
        else
        {
            impar += 1;
        }
    }
    // Comparar quantidade de pares e impares
    if (par < impar)
    {
        return 1;
    }
    else if (par > impar)
    {
        return 2;
    }
    else if (par == impar)
    {
        return 0;
    }
}

// Le 10 numeros e exibe qual tipo (par/impar) predomina
int main()
{
    int arr[10];
    int result;
    for (int i = 0; i < 10; i++)
    {
        printf("Digite um numero inteiro\n");
        scanf("%d", &arr[i]);
    }
    result = parOuImpar(arr);
    switch (result)
    {
    case 0:
        printf("5 numeros pares e 5 numeros impares");
        break;
    case 1:
        printf("Foram digitados mais numeros impares");
        break;

    case 2:
        printf("Foram digitados mais numeros pares");
    default:
        break;
    }
    return 0;
}