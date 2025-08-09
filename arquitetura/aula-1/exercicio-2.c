#include <stdio.h>
#include <time.h>

int calculateAge()
{
    int day, month, year;
    int currentDay, currentMonth, currentYear;
    int age = currentYear - year;

    printf("Digite sua data de nascimento (DD MM AAAA): ");
    scanf("%d %d %d", &day, &month, &year);

    printf("Digite a data atual (DD MM AAAA): ");
    scanf("%d %d %d", &currentDay, &currentMonth, &currentYear);

    if (currentMonth < month || (currentMonth == month && currentDay < day))
    {
        age--;
        printf("Voce tem %d anos.\n", age);
    }
    else
    {
        printf("Voce tem %d anos.\n", age);
    }
    return 0;
}

int calculateDaysToBirthday()
{
    int day, month, year;
    int currentDay, currentMonth, currentYear;
    int daysToBirthday = 0;

    printf("Digite sua data de nascimento (DD MM AAAA): ");
    scanf("%d %d %d", &day, &month, &year);


    printf("Digite a data atual (DD MM AAAA): ");
    scanf("%d %d %d", &currentDay, &currentMonth, &currentYear);

    if (currentMonth < month || (currentMonth == month && currentDay < day))
    {
        daysToBirthday = (month - currentMonth) * 30 + (day - currentDay);
    }
    else
    {
        daysToBirthday = (12 - currentMonth + month) * 30 + (day - currentDay);
    }

    printf("Faltam %d dias para o seu aniversario.\n", daysToBirthday);
    return 0;
}

int main()
{
    int option = 0;
    do
    {
        printf("Escolha uma opcao:\n");
        printf("1. Calcular idade\n");
        printf("2. Calcular dias para o aniversario \n");
        printf("3. Sair\n");

        scanf("%d", &option);

        switch (option)
        {
        case 1:
            calculateAge();
            option = 0;
            break;
        case 2:
            calculateDaysToBirthday();
            option = 0;
            break;
        default:
            printf("Opcao invalida. Tente novamente.\n");
            break;
        }
    } while (option != 3);
}
