#include <stdio.h>



int main() {

    int number;
    char character = 'A';
    float pi = 3.14;
    double euler = 2.718281828459045;
    const int constantValue = 100;
    #define PI 3.14159
    
    printf("Hello, World!\n");
    printf("Enter a number: ");
    scanf("%d", &number);
    
    
    if (number % 2 == 0) {
        printf("The number is even.\n");
    } else {
        printf("The number is odd.\n");
    }

    number % 2 == 0 ? printf("The number is even.\n") : printf("The number is odd.\n"); 
    
    switch (number) {
    case 50:
        printf("The number is 50\n");
        break;
    case 90:
        printf("The number is 90.\n");
        break;
    
    default:
        break;
    }
    
    
    printf("The number is %d\n", number);

    return 0;
}


/*



*/