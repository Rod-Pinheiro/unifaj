#include <stdio.h>

struct Numbers
{
  float n1;
  float n2;
  float result;

};

int divide(int n1, int n2)
{
}

int multiply(int n1, int n2)
{
}

int subtract(int n1, int n2)
{
}

int sum(int n1, int n2)
{
}

void defineNumbers()
{
  printf("Defina o primeiro valor: \n");
}

void calc()
{

  char operation;
  int option;
  do
  {
    printf("Digite uma das opcoes a seguir\n");
    printf("1) Somar \n");
    printf("2) Subtrair\n");
    printf("3) Multiplicar\n");
    printf("4) Dividir\n");
    printf("5) Sair\n");
    scanf("%d", &option);
    switch (option)
    {
    case 1:
      defineNumbers();
    case 2:
      // Operacao de sub
    case 3:
      // Operacao de multiplicacao
    case 4:
      // Operacao de Divisao
    case 5:
      return;
    default:
      printf("Digite uma opcao valida");
    }
  } while (option != 5);
}

int main()
{
  int option = 0;
  do
  {
    printf("Digite uma das opcoes a seguir\n");
    printf("1) Calculadora\n");
    printf("2) Sair\n");
    scanf("%d", &option);
    switch (option)
    {
    case 1:
      calc();
    default:
      printf("Digite uma opcao valida");
    }

  } while (option != 2);
  return 0;
}