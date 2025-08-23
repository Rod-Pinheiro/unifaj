#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void generateBoats(int boats[5])
{
    srand(time(NULL));
    for (int i = 0; i < 5; i++)
    {
        boats[i] = 1 + rand() % 5;
        printf("%d", boats[i]);
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
        int line,column;
        printf("Digite o valor de linha e coluna \n");
        scanf("%d"
              "%d",
              &line, &column);

        if (boats[line -1] == column)
        {
            field[line -1][column -1] = 'X';
            points += 1;
        }
        else
        {
            field[line -1][column -1] = 'O';
        }
        // TODO:
        // NAO PERMITIR QUE A MESMA CASA SEJA JOGADA NOVAMENTE
        // PARA QUE NAO SEJA POSSIVEL PONTUAR SEMPRE NA MESMA CASA
        printf("Acertos: %d\n", points);
        printField(field);

    } while (points != 5);

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