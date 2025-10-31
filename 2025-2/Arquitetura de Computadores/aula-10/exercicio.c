#include <stdio.h>

int insertEven(int *n2)
{
    do
    {
        printf("Digite um numero par: ");
        scanf("%d", n2);
        if (*n2 % 2 == 0)
        {
            FILE *file = fopen("par.txt", "a");
            if (file == NULL)
            {
                printf("Erro ao  abrir par.txt \n");
                return 1;
            }
            printf("Escrevendo %d no arquivo \n", *n2);
            fprintf(file, "%d\n", *n2);
            fclose(file);
        }
    } while (*n2 % 2 != 0);
    return 0;
}

int insertOdd(int *n1)
{
    do
    {
        printf("Digite um numero impar: ");
        scanf("%d", n1);
        if (*n1 % 2 != 0)
        {
            FILE *file = fopen("impar.txt", "a");
            if (file == NULL)
            {
                printf("Erro ao  abrir impar.txt \n");
                return 1;
            }
            printf("Escrevendo %d no arquivo \n", *n1);
            fprintf(file, "%d\n", *n1);
            fclose(file);
        }
    } while (*n1 % 2 == 0);
    return 0;
}

int insert()
{
    int n1, n2;
    do{
        
        insertOdd(&n1);
        insertEven(&n2);
    
    }while(!(n1 == 99 && n2 == 100));
    return 0;
}

int printEven()
{
    char line[50];
    FILE *file = fopen("par.txt", "r");
    if (file == NULL)
    {
        printf("Erro ao  abrir par.txt \n");
        return 1;
    }
    while (fgets(line, sizeof(line), file))
    {
        printf("%s", line);
    }
    fclose(file);
    return 0;
}

int printOdd()
{
    char line[50];
    FILE *file = fopen("impar.txt", "r");
    if (file == NULL)
    {
        printf("Erro ao  abrir impar.txt \n");
        return 1;
    }
    while (fgets(line, sizeof(line), file))
    {
        printf("%s", line);
    }
    fclose(file);
    return 0;
}

int printAnalysis()
{
    printf("Analise: \n");
    FILE *odd = fopen("impar.txt", "r");
    FILE *even = fopen("par.txt", "r");

    if (odd == NULL || even == NULL)
    {
        printf("Erro ao abrir arquivos.txt \n");
        return 1;
    }
    int n1,n2;
    while (fscanf(odd, "%d", &n1) == 1 && fscanf(even, "%d", &n2) == 1)
    {
        if (n1 > n2)
            printf("%d é maior que %d\n", n1, n2);
        else if (n2 > n1)
            printf("%d é maior que %d\n", n2, n1);
        else
            printf("%d e %d são iguais\n", n1, n2);
    }

    fclose(odd);
    fclose(even);
}

int readMenu()
{
    int option = 0;
    do
    {
        printf("1) Imprimir arquivo impar.txt\n");
        printf("2) Imprimir arquivo par.txt\n");
        printf("3) Imprimir análise\n");
        printf("4) Sair\n");
        scanf("%d", &option);
        switch (option)
        {
        case 1:
            printOdd();
            break;
        case 2:
            printEven();
            break;
        case 3:
            printAnalysis();
            break;

        default:
            break;
        }
    } while (option != 4);
    return 0;
}

int main()
{
    int option = 0;
    do
    {
        printf("Digite uma das opcoes a seguir\n");
        printf("1) Inserir informações\n");
        printf("2) Ler informações\n");
        printf("3) Sair\n");
        scanf("%d", &option);
        switch (option)
        {
        case 1:
            insert();
            break;
        case 2:
            readMenu();
            break;
        case 3:
            printf("Saindo...");
        default:
            printf("Digite uma opcao valida");
        }

    } while (option != 3);
    return 0;
}