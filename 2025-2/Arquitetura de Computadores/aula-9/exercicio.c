#include <stdio.h>

void imprimirInformacoes(int uniArr[5],int biArr[5][5]){
    for(int i = 0; i < 5; i++){
        if(i == 0){
            printf("Array unidimensional: \n");
        }
        printf("%d, ", uniArr[i]);
    }
    printf("\n");
    for(int i = 0; i < 5; i++) {
        if(i == 0){
            printf("Array bidimensional: \n");
        }
        for(int j = 0; j < 5; j++){
            printf("%d, ", biArr[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int uniArr[5];
    int biArr[5][5];
    for(int i = 0; i < 5; i++){
        printf("Digite um numero inteiro: ");
        scanf("%d", &uniArr[i]);
    }
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            if(i == 0){
                biArr[i][j] = uniArr[j];
            } else {
                biArr[i][j] = biArr[0][j] + biArr[i -1][j];
            }
        }
    }
    imprimirInformacoes(uniArr, biArr);
    return 0;
}