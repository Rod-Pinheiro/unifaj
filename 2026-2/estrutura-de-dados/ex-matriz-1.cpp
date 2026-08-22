#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

int main () {
    int lin, col;
    srand(time(NULL));

    cout << "informe qnt de linhas: ";
    cin >> lin;

    cout << "informe qnt de colunas: ";
    cin >> col;

    int mat[lin][col];

    int even[lin * col];
    int odd[lin * col];

    int count_even, count_odd = 0;

    for (int i = 0; i < lin; i++)
    {
        for (int j = 0; j < col; j++)
        {
            mat[i][j] = rand()%30;
            if (mat[i][j] % 2 == 0){
                even[count_even] = mat[i][j];
                count_even++;
            } else {
                odd[count_odd] = mat[i][j];
                count_odd++;
            }
        }
    }
    cout << "numeros pares : ";
    for ( int i = 0; i < count_even; i++)
    {
        cout << even[i] << ", ";
    }
    cout << "\n";

    cout << "numeros impares : ";
    for ( int i = 0; i < count_odd; i++)
    {
        cout << odd[i] << ", ";
    }
    cout << "\n";
    
    
}