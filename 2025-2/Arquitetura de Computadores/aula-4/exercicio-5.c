#include <stdio.h>

void printField(char (*p)[4])
{
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            printf("%c", *(*(p + i) + j));
            printf(" ");
        }
        printf("\n");
    }
}

void playerAction(char (*p)[4], int *line, int *column, int *plays)
{

    if (*(*(p + (*line -1)) + (*column -1)) == '_')
    {
        *(*(p + (*line -1)) + (*column -1)) = *plays % 2 == 0 ? 'X' : 'O';
        *plays -= 1;
    }
    else
    {
        printf("Posicao ja foi escolhida, tente outra vez. \n");
    }
}

void pointersGame()
{
    int plays = 16;
    int *playsPointer = &plays;
    char field[4][4] = {{'_', '_', '_', '_'},
                        {'_', '_', '_', '_'},
                        {'_', '_', '_', '_'},
                        {'_', '_', '_', '_'}};
    printField(field);
    do
    {
        int line, column;
        int *linePointer = &line;
        int *columnPointer = &column;
        printf("Digite o valor de linha e coluna \n");
        scanf("%i"
              "%i",
              linePointer, columnPointer);
        playerAction(field, linePointer, columnPointer, playsPointer);
        printField(field);

    } while (*playsPointer != 0);

    return;
}

int main()
{
    printf("teste");
    int option = 0;
    int *optionPointer = &option;
    do
    {
        printf("Digite uma opcao: \n");
        printf("1 - Jogar \n");
        printf("2 - Sair \n");
        scanf("%d", optionPointer);
        switch (*optionPointer)
        {
        case 1:
            pointersGame();
            *optionPointer = 0;
            break;
        case 2:
            printf("Saindo...\n");
            break;
        default:
            break;
        }
    } while (*optionPointer != 2);
    return 0;
}