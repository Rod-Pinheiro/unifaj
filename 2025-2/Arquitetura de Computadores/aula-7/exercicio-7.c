#include <stdio.h>
#include <stdlib.h>

// Exercício 7: Manipulação de bits e ponteiros
// Demonstra operações bitwise e uso de ponteiros

void printBinary(int num) {
    printf("Binário de %d: ", num);
    for (int i = 31; i >= 0; i--) {
        printf("%d", (num >> i) & 1);
        if (i % 8 == 0) printf(" ");
    }
    printf("\n");
}

void swapWithPointers(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    int x = 42;
    int y = 15;

    printf("=== Exercício 7: Manipulação de Bits e Ponteiros ===\n\n");

    // Operações bitwise
    printf("Operações bitwise:\n");
    printBinary(x);
    printBinary(y);
    printBinary(x & y);  // AND
    printBinary(x | y);  // OR
    printBinary(x ^ y);  // XOR
    printBinary(~x);     // NOT
    printBinary(x << 2); // Shift left
    printBinary(y >> 1); // Shift right

    printf("\n");

    // Uso de ponteiros
    printf("Uso de ponteiros:\n");
    printf("Antes da troca: x = %d, y = %d\n", x, y);
    swapWithPointers(&x, &y);
    printf("Após a troca: x = %d, y = %d\n", x, y);

    // Ponteiros e arrays
    int arr[] = {10, 20, 30, 40, 50};
    int *ptr = arr;

    printf("\nAcesso via ponteiros:\n");
    for (int i = 0; i < 5; i++) {
        printf("arr[%d] = %d (via ponteiro: %d)\n", i, arr[i], *(ptr + i));
    }

    return 0;
}