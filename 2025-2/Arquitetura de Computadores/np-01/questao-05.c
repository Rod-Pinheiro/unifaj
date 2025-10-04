#include <stdio.h>
#include <string.h>


// Define o struct NomeCompleto
struct NomeCompleto
{
    char nome[50], sobrenome[100];
};
// Define o struct DataNascimento
struct DataNascimento
{
    int dia, mes, ano, hora, minuto;
};
// Define o struct Pessoa que possui variaveis dos structs anteriores
struct Pessoa
{
    struct DataNascimento dataUsuario;
    struct NomeCompleto nomeUsuario;
};

// Funcao queremove o \n do fgets
void removeEnter(char *str)
{
    str[strcspn(str, "\n")] = 0;
}

int main()
{
    // Declara array do tipo Pessoa
    struct Pessoa arr[5];
    // Inicializa o loop com 5 iteracoes
    for (int i = 0; i < 5; i++)
    {
        // Pede os valores de string usando o fgets
        printf("Digite o nome: \n");
        fgets(arr[i].nomeUsuario.nome, 50, stdin);
        // Chama a funcao removeEnter para remover o \n do fgets
        removeEnter(arr[i].nomeUsuario.nome);
        // Pede os valores de string usando o fgets
        printf("Digite o sobrenome: \n");
        fgets(arr[i].nomeUsuario.sobrenome, 100, stdin);
        // Chama a funcao removeEnter para remover o \n do fgets
        removeEnter(arr[i].nomeUsuario.sobrenome);
        // Aqui vai pedir os valores de data de nascimento usando o scanf
        printf("Digite o dia de nascimento: \n");
        scanf("%d", &arr[i].dataUsuario.dia);
        printf("Digite o mes de nascimento: \n");
        scanf("%d", &arr[i].dataUsuario.mes);
        printf("Digite o ano de nascimento: \n");
        scanf("%d", &arr[i].dataUsuario.ano);
        printf("Digite a hora de nascimento: \n");
        scanf("%d", &arr[i].dataUsuario.hora);
        printf("Digite os minutos de nascimento: \n");
        scanf("%d", &arr[i].dataUsuario.minuto);
        // Funcao para limpar o enter do scanf
        getchar();
    }
    // Loop para iterar o array e imprimir os valores como exigido na questao
    for (int i = 0; i < 5; i++)
    {
        printf("Pessoa %d \n", i + 1);// Aqui estou usanndo o i + 1 para atender o requisito da questao
        printf("Nome: %s \n", arr[i].nomeUsuario.nome);
        printf("Sobrenome: %s \n", arr[i].nomeUsuario.sobrenome);
        printf("Data de Nascimento: %d/%d/%d %d:%d \n", arr[i].dataUsuario.dia, arr[i].dataUsuario.mes, arr[i].dataUsuario.ano, arr[i].dataUsuario.hora, arr[i].dataUsuario.minuto);
    }
    return 0;
}