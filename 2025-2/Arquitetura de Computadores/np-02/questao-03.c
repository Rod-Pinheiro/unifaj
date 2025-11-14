#include <stdio.h>

// Cria matriz 3x6 com A/B, transforma em 3x3 e salva em arquivo
int gravar()
{
    int checkLetra = 0;
    char matrix1[3][6];
    char matrix2[3][3];
    // Preencher matriz 3x6 com A ou B
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            char letra;
            do
            {
                printf("Digite A ou B \n");
                scanf(" %c", &letra);
                if (letra == 'A' || letra == 'B')
                {
                    matrix1[i][j] = letra;
                    checkLetra = 1;
                }
                else
                {
                    printf("Letra invalida \n");
                    checkLetra = 0;
                }
            } while (checkLetra == 0);
        }
        // Transformar matriz 3x6 em 3x3
        // se os elementos adjacentes forem iguais, mantem o valor, senao transformar em 'C' ou 'D'
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (matrix1[i][j] == 'A' && matrix1[i][j + 3] == 'A')
                {
                    matrix2[i][j] = matrix1[i][j];
                }
                else if (matrix1[i][j] == 'B' && matrix1[i][j + 3] == 'B')
                {
                    matrix2[i][j] = matrix1[i][j];
                }
                else if( (matrix1[i][j] == 'A' && matrix1[i][j + 3] == 'B'))
                {
                    matrix2[i][j] = 'C';
                } else if( (matrix1[i][j] == 'B' && matrix1[i][j + 3] == 'A'))
                {
                    matrix2[i][j] = 'D'; 
                }
            }
        }
        // Gravar matriz 3x3 em arquivo txt
        FILE *file = fopen("matriz.txt", "w");
        if (file == NULL)
        {
            printf("Erro ao abrir o arquivo \n");
            return 1;
        }
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                fprintf(file, "%c ", matrix2[i][j]);
            }
            fprintf(file, "\n");
        }
        fclose(file);
    }

    return 0;
}

// Le matriz 3x3 do arquivo e transforma de volta em 3x6 entao exibe no console
int ler()
{
    char matrix[3][3];
    char matrix2[3][6];
    FILE *file = fopen("matriz.txt", "r");
    if (file == NULL)
    {
        printf("Erro ao abrir o arquivo \n");
        return 1;
    }
    // Ler matriz 3x3 do arquivo
    // preencher matriz 3x3 com os valores do arquivo
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            fscanf(file, " %c", &matrix[i][j]);
        }
    }
    fclose(file);
    // Transformar matriz 3x3 em 3x6
    // se o elemento for A, duplicar como A A, se for B, duplicar como B B
    // se for C, transformar em A B, se for D, transformar em B A
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (matrix[i][j] == 'A')
            {
                matrix2[i][j] = 'A';
                matrix2[i][j + 3] = 'A';
            }
            else if (matrix[i][j] == 'B')
            {
                matrix2[i][j] = 'B';
                matrix2[i][j + 3] = 'B';
            }
            else if (matrix[i][j] == 'C')
            {
                matrix2[i][j] = 'A';
                matrix2[i][j + 3] = 'B';
            }
            else if (matrix[i][j] == 'D')
            {
                matrix2[i][j] = 'B';
                matrix2[i][j + 3] = 'A';
            }
        }
    }
    // Exibir matriz 3x6 no console
    printf("Matriz 3x6: \n");
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            printf("%c ", matrix2[i][j]);
        }
        printf("\n");
    }
    return 0;
}

// Menu principal para gravar ou ler matriz do arquivo
int main()
{
    int option;
    do
    {
        printf("Escolha uma opcao:\n");
        printf("1) Gravar\n");
        printf("2) Ler\n");
        printf("3) Sair\n");
        scanf("%d", &option);
        switch (option)
        {
        case 1:
            gravar();
            break;
        case 2:
            ler();
            break;
        case 3:
            printf("Saindo... \n");
            break;
        default:
            printf("Opcao invalida \n");
            break;
        }
    } while (option != 3);
    return 0;
}