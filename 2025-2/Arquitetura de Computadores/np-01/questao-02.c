#include <stdio.h>

int main()
{
    // Declara a variavel de um array de 2 dimensoes
    int array[4][5];
    // Inicia o loop para iterar 10 vezes
    for (int i = 0; i < 10; i++)
    {
        // declara variavel inteira e pede para o usuario digitar o numero que sera armazenado nessa variavel
        int number;
        printf("Digite um numero: \n");
        scanf("%d", &number);
        // Verifica se o i do loop eh menor que 5 para armazenar na primeira "linha" do array
        if(i < 5){
            // Adiciona o valor na posicao da primeira linha e usa o continue para "saltar" a iteracao.
            array[0][i] = number;
            continue;
        }
        // Armazena o valor da variavel na terceira "linha" do array
        array[2][i - 5] = number;
    }

    // Loop responsavel por calcular os valores da segunda e quarta "linhas"
    for(int i; i < 5; i++)
    {
        // Adicionar valor na linha 2 com o dobro do valor da linha 1
        array[1][i] = array[0][i] * 2;
        // Adiciona o valor da linha 4 com a somatoria das linhas  1, 2 e 3
        array[3][i] = array[0][i] + array[1][i] + array[2][i];
    }

    // loop de 2 dimensoes para imprimir os valores do array.
    for (int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 5; j++)
        {
            // Imprime o valor da linha i na posicao j
            printf("%d ", array[i][j]);
        }
        // Salta linha no console
        printf("\n");
    }
    
    
    return 0;
}