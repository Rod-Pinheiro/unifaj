#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int guessNumber()
{
    srand(time(NULL));                // Inicializa o gerador de números aleatórios
    int numberToGuess = rand() % 101; // Número aleatório entre 0 e 100
    int userGuess;
    int attempts = 0;

    printf("Adivinhe o numero entre 0 e 100:\n");
    do
    {
        scanf("%d", &userGuess);
        attempts++;
        if (userGuess < numberToGuess)
        {
            printf("Muito baixo! Tente novamente.\n");
        }
        else if (userGuess > numberToGuess)
        {
            printf("Muito alto! Tente novamente.\n");
        }
        else
        {
            printf("Parabens! Voce adivinhou o numero %d em %d tentativas.\n", numberToGuess, attempts);
        }
    } while (userGuess != numberToGuess);
    return 0;
}

int countdown()
{
    int number;
    printf("Digite um numero para a contagem regressiva:\n");
    scanf("%d", &number);
    for (int i = number; i >= 0; i--)
    {
        printf("%d\n", i);
    }
    return 0;
}

int weirdCountdown()
{
    int number;
    do
    {
        printf("Digite um numero entre 50 e 99 para a contagem regressiva esquisita:\n");
        scanf("%d", &number);
    } while (number < 50 || number > 99);

    if (number % 2 == 0)
    {
        for (int i = number; i >= 0; i -= 3)
        {
            printf("%d\n", i);
        }
    }
    else
    {
        for (int i = number; i >= 0; i -= 5)
        {
            printf("%d\n", i);
        }
    }

    return 0;
}

int main()
{
    int option;
    do
    {
        printf("Selecione uma opcao:\n");
        printf("1. Adivinhe um numero entre 0 e 100\n");
        printf("2. Contagem regressiva\n");
        printf("3. Contagem regressiva esquisita\n");
        printf("4. Sair\n");
        scanf("%d", &option);
        switch (option)
        {
        case 1:
            guessNumber();
            option = 0;
            break;
        case 2:
            countdown();
            option = 0;
            break;
        case 3:
            weirdCountdown();
            option = 0;
            break;
        case 4:
            printf("Saindo...");
            break;
        default:
            printf("Opcao invalida. Tente novamente.\n");
            break;
        }

    } while (option != 4);

    return 0;
}