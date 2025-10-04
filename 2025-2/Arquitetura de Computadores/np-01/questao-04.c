#include <stdio.h>

int main()
{
    // Declara o struct e inicializa o struct data usuario
    struct DataNascimento
    {
        int dia, mes, ano, hora, minuto;
    } dataUsuario;
    // Imprime um pedido para o usuario digitar valores para todas as variaveis do struct
    printf("Digite o dia do nascimento: \n");
    scanf("%d", &dataUsuario.dia);
    printf("Digite o mes do nascimento: \n");
    scanf("%d", &dataUsuario.mes);
    printf("Digite o ano do nascimento: \n");
    scanf("%d", &dataUsuario.ano);
    printf("Digite a hora do nascimento: \n");
    scanf("%d", &dataUsuario.hora);
    printf("Digite os minutos do nascimento: \n");
    scanf("%d", &dataUsuario.minuto);

    // Imprime no console os valores na estrutura exigida na questao
    printf("%d/%d/%d %d:%d \n", dataUsuario.dia, dataUsuario.mes, dataUsuario.ano, dataUsuario.hora, dataUsuario.minuto);
    return 0;
}