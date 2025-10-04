#include <stdio.h>

int main()
{
    // Inicializa as 3 variaveis
    int firstInt, secondInt, sum;
    // Define os ponteiros das variaveis
    int *firstPointer = &firstInt;
    int *secondPointer = &secondInt;
    int *sumPointer = &sum;
    // Pede para o usuario digitar o primeiro valor e armazena utilizando o ponteiro
    printf("Digite o primeiro valor: \n");
    scanf("%d", firstPointer);
    // Pede para o usuario digitar o segundo valor e armazena utilizando o ponteiro
    printf("Digite o segundo valor: \n");
    scanf("%d", secondPointer);

    // Faz a somataria dos valores armazenados nos ponteiros e armazena no ponteiro sum 
    *sumPointer = *firstPointer + *secondPointer;

    // imprime a soma no console usando o formato exigido
    printf("%d + %d = %d \n",*firstPointer, *secondPointer, *sumPointer);

    return 0;
}