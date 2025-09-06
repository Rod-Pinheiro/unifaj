#include <stdio.h>
#include <string.h>

struct Discipline
{
    char name[42];
    float firstScore;
    float secondScore;
    float avg;
};

float computeAvg(float firstScore, float secondScore)
{
    return (firstScore + secondScore) / 2;
}

void compareScores(struct Discipline *firstDiscipline, struct Discipline *secondDiscipline)
{
    if (firstDiscipline->avg == secondDiscipline->avg)
    {
        printf("As medias das duas disciplinas sao iguais \n");
    }
    else if (firstDiscipline->avg > secondDiscipline->avg)
    {
        printf("A disciplina %s tem a maior media \n", firstDiscipline->name);
    }
    else
    {
        printf("A disciplina %s tem a maior media \n", secondDiscipline->name);
    }
}

void insertDisciplines()
{
    struct Discipline firstDiscipline, secondDiscipline;

    // Limpar buffer antes de começar
    while (getchar() != '\n');

    // Primeira disciplina
    printf("Insira o nome da primeira disciplina: ");
    fgets(firstDiscipline.name, 42, stdin);
    // Remove o \n do final da string
    firstDiscipline.name[strcspn(firstDiscipline.name, "\n")] = 0;

    printf("Insira a primeira nota: ");
    scanf("%f", &firstDiscipline.firstScore);

    printf("Insira a segunda nota: ");
    scanf("%f", &firstDiscipline.secondScore);

    firstDiscipline.avg = computeAvg(firstDiscipline.firstScore, firstDiscipline.secondScore);

    // Limpar buffer após scanf
    while(getchar() != '\n');

    // Segunda disciplina
    printf("Insira o nome da segunda disciplina: ");
    fgets(secondDiscipline.name, 42, stdin);
    // Remove o \n do final da string
    secondDiscipline.name[strcspn(secondDiscipline.name, "\n")] = 0;

    printf("Insira a primeira nota: ");
    scanf("%f", &secondDiscipline.firstScore);

    printf("Insira a segunda nota: ");
    scanf("%f", &secondDiscipline.secondScore);

    secondDiscipline.avg = computeAvg(secondDiscipline.firstScore, secondDiscipline.secondScore);

    compareScores(&firstDiscipline, &secondDiscipline);
}

int main()
{
    int option = 0;
    do
    {
        printf("Escolha uma opcao:\n");
        printf("1 - Inserir disciplina\n");
        printf("2 - Sair\n");
        scanf("%d", &option);
        switch (option)
        {
        case 1:
            insertDisciplines();
            break;
        case 2:
            printf("Saindo...\n");
            break;
        default:
            printf("Opcao invalida! Tente novamente.\n");
            break;
        }
    } while (option != 2);

    return 0;
}