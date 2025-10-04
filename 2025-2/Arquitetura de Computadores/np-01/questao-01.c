#include <stdio.h>

int main()
{
    //Declara array e inicia um loop que vai iterar 20 vezes 
    int evenNumbers[20];

    for (int i = 0; i < 20;)
    {
        //Imprime texto na tela e pede pro usuario digitar um numero
        printf("Digite um numero par \n");
        scanf("%d", &evenNumbers[i]);
        //Verifica se o numero NAO eh par
        if (evenNumbers[i] % 2 != 0)
        {
            // Imprime texto na tela e usa o continue para saltar para a proxima iteracao
            printf("Numero digitado nao eh par. \n");
            continue;
        }
        // Adicionar 1 na variavel do loop. 
        i++;
    }
    //Declara variavel
    int avg;
    // Loop com 20 iteracoes
    for (int i = 0; i < 20; i++)
    {
        //soma o valor digitado pelo usuario a variavel avg
        avg += evenNumbers[i];
    }
    // divide a variavel por 20 para obter a media
    avg = avg / 20;
    // Imprime o valor da media no console.
    printf("A media dos numeros digitados eh: %d", avg);
    return 0;
}