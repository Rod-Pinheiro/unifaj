#include <stdio.h>

struct Numbers
{
  float n1;
  float n2;
  float result;
};

void divide(struct Numbers *nums)
{
  if (nums->n2 == 0)
  {
    printf("Erro: Divisao por zero nao e permitida.\n");
    return;
  }
  nums->result = nums->n1 / nums->n2;
  printf("%.2f %% %.2f = %.2f\n", nums->n1, nums->n2, nums->result);
  return;
}

void multiply(struct Numbers *nums)
{
  nums->result = nums->n1 * nums->n2;
  printf("%.2f * %.2f = %.2f\n", nums->n1, nums->n2, nums->result);
  return;
}

void subtract(struct Numbers *nums)
{
  nums->result = nums->n1 - nums->n2;
  printf("%.2f - %.2f = %.2f\n", nums->n1, nums->n2, nums->result);
  return;
}

void sum(struct Numbers *nums)
{
  nums->result = nums->n1 + nums->n2;
  printf("%.2f + %.2f = %.2f\n", nums->n1, nums->n2, nums->result);
  return;
}

void defineNumbers(struct Numbers *nums)
{
  printf("Defina o primeiro valor: \n");
  scanf("%f", &nums->n1);
  printf("Defina o segundo valor: \n");
  scanf("%f", &nums->n2);
}

void calc()
{
  struct Numbers nums;
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
      defineNumbers(&nums);
      sum(&nums);
      option = 5;
      break;
    case 2:
      defineNumbers(&nums);
      subtract(&nums);
      option = 5;
      break;
    case 3:
      defineNumbers(&nums);
      multiply(&nums);
      option = 5;
      break;
    case 4:
      defineNumbers(&nums);
      divide(&nums);
      option = 5;
      break;
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