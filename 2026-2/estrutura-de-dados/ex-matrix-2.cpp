#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

int main()
{
    srand(time(NULL));
    int dim;

    cout << "digite a dimensao da matriz quadrada: ";
    cin >> dim;

    int mat[dim][dim];
    // Cria matriz
    for (int i = 0; i < dim; i++)
    {
        for (int j = 0; j < dim; j++)
        {
            mat[i][j] = rand() % 9;
            cout << mat[i][j] << " ";
        }
        cout << "\n";
    }

    cout << "diagonal principal \n";
    for (int i = 0; i < dim; i++)
    {
        cout << mat[i][i] << " ";
    }
    cout << "\n";

    cout << "soma dos elementos acima da diagonal principal \n";
    int acc = 0;
    for (int i = 0; i < dim; i++)
    {
        for (int j = 0; j < dim; j++)
        {
            if (i > j)
            {
                acc += mat[i][j];
            }
        }
    }
    cout << acc;
    cout << "\n";

    cout << "soma dos elementos abaixo da diagonal principal \n";
    acc = 0;
    for (int i = 0; i < dim; i++)
    {
        for (int j = 0; j < dim; j++)
        {
            if (i < j)
            {
                acc += mat[i][j];
            }
        }
    }
    cout << acc;
    cout << "\n";

    cout << "diagonal secundaria \n";
    for (int i = 0; i < dim; i++)
    {
        cout << mat[i][(dim - 1) - i] << " ";
    }
    cout << "\n";

    cout << "Elemento central da  matriz (se existir) \n";
    if (dim % 2 == 0)
    {
        cout << "Nao existe elemento central";
    }
    else
    {
        int central_pos = (dim - 1) / 2;
        cout << mat[central_pos][central_pos];
    }
    cout << "\n";
}
