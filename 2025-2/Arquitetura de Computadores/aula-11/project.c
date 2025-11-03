#include <stdio.h>


int printStudents()
{
    // TODO: print students in alphabetical order
    return 0;
}

int createStudent()
{
    // Should aks for Nome, Data de nascimento, Curso, Ano de ingresso
    // Telefone e Endereco
    // Should add an unique id to the student
    // Add information to a txt file using the initial char of the name.
    return 0;
}

int studentsMenu()
{   
    int option = 0;
    do
    {
        printf("1) Consultar alunos\n");
        printf("2) Cadastrar alunos\n");
        printf("3) Editar alunos\n");
        printf("4) Voltar ao menu inicial\n");
        scanf("%d", &option);
        switch (option)
        {
        case 1:
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            printf("Voltando ao menu principal...\n");
        default:
            break;
        }
    } while (option != 4);
    return 0;
}

int disciplineMenu()
{
      int option = 0;
    do
    {
        printf("1) Consultar disciplina\n");
        printf("2) Consultar disciplina\n");
        printf("3) Editar disciplina\n");
        printf("4) Voltar ao menu inicial\n");
        scanf("%d", &option);
        switch (option)
        {
        case 1:
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            printf("Voltando ao menu principal...\n");
        default:
            break;
        }
    } while (option != 4);
    return 0;
}

int scoreMenu(){
      int option = 0;
    do
    {
        printf("1) Consultar notas");
        printf("2) Cadastrar notas");
        printf("3) Excluir nota");
        printf("4) Voltar ao menu inicial");
        scanf("%d", &option);
        switch (option)
        {
        case 1:
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            printf("Voltando ao menu principal...");
        default:
            break;
        }
    } while (option != 4);
    return 0;
}

int main(){

    int option = 0;
    do
    {
        printf("1) Gerenciar alunos");
        printf("2) Gerenciar disciplinas");
        printf("3) Gerenciar notas");
        printf("4) Autores");
        printf("5) Sair");
        scanf("%d", &option);
        switch (option)
        {
        case 1:
            studentsMenu();
            break;
        case 2:
            disciplineMenu();
            break;
        case 3:
            break;
        case 4:
            break;
        case 5:
            break;
        default:
            break;
        }
    } while (option != 5);
    

    return 0;
}