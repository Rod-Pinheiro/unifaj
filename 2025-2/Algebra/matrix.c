#include <stdio.h>

void printMatrix()
{
    int matrix[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}};

    printf("Matrix 3x3:\n");
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void multiplyMatrix()
{
    int matrixA[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}};

    int matrixB[3][3] = {
        {9, 8, 7},
        {6, 5, 4},
        {3, 2, 1}};

    int matrixC[3][3] = {0};

    for (size_t i = 0; i < 3; i++)
    {
        for (size_t j = 0; j < 3; j++)
        {
            for (size_t k = 0; k < 3; k++)
            {
                matrixC[i][j] += matrixA[i][k] * matrixB[k][j];
            }
        }
    }

    for (size_t i = 0; i < 3; i++)
    {
        for (size_t j = 0; j < 3; j++)
        {
            printf("%d ", matrixC[i][j]);
        }
        printf("\n");
    }
}

void identityMatrix()
{
    int matrix[3][3] = {0};

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (i == j)
            {
                matrix[i][j] = 1;
            }
            else
            {
                matrix[i][j] = 0;
            }
        }
    }
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    int option;
    do
    {
        printf("Escolha uma opcao:\n");
        printf("1 -Imprimir matriz\n");
        printf("2 - Multiplicar matriz\n");
        printf("3 - Gerar matriz identidade");
        printf("9 - Sair\n");
        scanf("%d", &option);
        switch (option)
        {
        case 1:
            printMatrix();
            option = 0;
            break;
        case 2:
            multiplyMatrix();
            option = 0;
            break;

        case 3:
            identityMatrix();
            option = 0;
            break;

        default:
            break;
        }

    } while (option != 9);
}