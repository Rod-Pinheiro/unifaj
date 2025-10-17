#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void generateBoats(int boats[5])
{
    srand(time(NULL));
    for (int i = 0; i < 5; i++)
    {
        boats[i] = rand() % 5;
    }
}

void printField(char field[5][5])
{
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            printf("%c", field[i][j]);
            printf(" ");
        }
        printf("\n");
    }
}

int game()
{
    int points = 0;
    int tries = 0;
    int boats[5];
    generateBoats(boats);
    char field[5][5] = {{'_', '_', '_', '_', '_'},
                        {'_', '_', '_', '_', '_'},
                        {'_', '_', '_', '_', '_'},
                        {'_', '_', '_', '_', '_'},
                        {'_', '_', '_', '_', '_'}};
    printField(field);

    do
    {
        int line, column;
        printf("Digite o valor de linha e coluna \n");
        scanf("%d"
              "%d",
              &line, &column);

        // Logica de verificacao
        if (line < 1 || line > 5 || column < 1 || column > 5)
        {
            printf("Digite valores de 1 a 5 para as posicoes \n");
            continue;
        }
        if (field[line - 1][column - 1] != '_')
        {
            printf("Voce ja disparou nessa posicao, tente novamente \n");
            continue;
        }
        // Logica de pontuacao
        if (boats[line - 1] == column - 1)
        {
            field[line - 1][column - 1] = 'X';
            points += 1;
            tries += 1;
            printf("Acertou um barco!\n");
        }
        else
        {
            field[line - 1][column - 1] = 'O';
            tries += 1;
            printf("Errou!\n");
        }
        printField(field);
    } while (points != 5);

    if (points == tries)
    {
        printf("Perfect!!! ");
    }
    printf("Nao atingiu %d posicoes\n", 25 - tries);

    return 0;
}

int main()
{
    printf("teste");
    int option = 0;
    do
    {
        printf("Digite uma opcao: \n");
        printf("1 - Jogar \n");
        printf("2 - Sair \n");
        scanf("%d", &option);
        switch (option)
        {
        case 1:
            game();
            break;
        case 2:
            printf("Saindo...\n");
            break;
        default:
            break;
        }
    } while (option != 2);
    return 0;
}