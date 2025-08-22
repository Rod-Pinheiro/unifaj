#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int checkPassword(char password[4], char userInput[4])
{
    char clue[4];
    for (int i = 0; i < 4; i++)
    {
        if (password[i] != userInput[i])
        {
            return 0;
        }
    }
    return 1;
}

int generateClue(char password[4], char userInput[4])
{
    char clue[4] = {'_', '_', '_', '_'};
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (password[i] == userInput[j] && i == j)
            {
                clue[i] = 'x';
            }
            else if (password[i] == userInput[j] && i != j)
            {
                clue[i] = 'o';
            }
        }
    }
    printf("dica: %4s  \n", clue);
    return 0;
}

int validatePassword(char password[4])
{
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (password[i] == password[j] && i != j)
            {
                printf("Senha invalida, nao repita cores. Tente novamente.\n");
                return 0;
            }
        }
    }
    return 1;
}

int randomPassword()
{
    srand(time(NULL));
    char colors[] = {'p', 'b', 'v', 'a', 'r', 'm'};
    char password[4];
    int tries = 10;

    do
    {
        for (int i = 0; i < 4; i++)
        {
            password[i] = colors[rand() % 6];
        }
    } while (!validatePassword(password));

    do
    {
        tries--;
        char userInput[4];
        printf("Tente adivinhar a senha de 4 digitos:");
        scanf("%4s", userInput);
        if (checkPassword(password, userInput))
        {
            printf("Acertou miseravi! \n");
            return 0;
        }
        else
        {
            generateClue(password, userInput);
            printf("Errrou, restam tentativa(s):%d \n", tries);
        }
    } while (tries != 0);

    return 0;
}

int pickPassword()
{
    char password[4];
    int tries = 10;
    int validPassword;

    printf("Escolha uma senha de 4 digitos (P,B,V,A,R,M)");
    scanf("%4s", password);
    validPassword = validatePassword(password);
    if (!validPassword)
    {
        return 0;
    }

    do
    {
        tries--;
        char userInput[4];
        printf("Tente adivinhar a senha de 4 digitos:");
        scanf("%4s", userInput);
        if (checkPassword(password, userInput))
        {
            printf("Acertou miseravi! \n");
            return 0;
        }
        else
        {
            generateClue(password, userInput);
            printf("Errrou, restam tentativa(s):%d \n", tries);
        }
    } while (tries != 0);

    return 0;
}

int main()
{
    int option;
    do
    {
        printf("Selecione uma opcao:\n");
        printf("1. Jogar escolhendo uma senha\n");
        printf("2. Jogar com senha aleatoria\n");
        printf("3. Sair\n");
        scanf("%d", &option);
        switch (option)
        {
        case 1:
            pickPassword();
            option = 0;
            break;
        case 2:
            randomPassword();
            option = 0;
            break;
        case 3:
            printf("Saindo... \n");
            break;
        default:
            printf("Opcao invalida. Tente novamente.\n");
            break;
        }

    } while (option != 3);

    return 0;
}
