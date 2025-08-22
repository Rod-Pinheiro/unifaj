#include <iostream>
using namespace std;

void printMatrix()
{
    int matrix[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}};

    cout << "Matrix 3x3:" << endl;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
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
            cout << matrixC[i][j] << " ";
        }
        cout << endl;
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
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    int option;
    do
    {
        cout << "Escolha uma opcao:" << endl;
        cout << "1 -Imprimir matriz" << endl;
        cout << "2 - Multiplicar matriz" << endl;
        cout << "3 - Gerar matriz identidade";
        cout << "9 - Sair" << endl;
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