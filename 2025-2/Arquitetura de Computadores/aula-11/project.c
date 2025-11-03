#include <stdio.h>
#include <string.h>

struct Student
{
    int id;
    char nome[42];
    char dataNascimento[11];
    char curso[42];
    int anoIngresso;
    char telefone[15];
    char endereco[100];
};

int saveStudent(struct Student student)
{
    char filename[5] = "";
    filename[0] = student.nome[0];
    strcat(filename, ".txt");
    FILE *file = fopen(filename, "a");
    if (file == NULL)
    {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }
    fprintf(file, "%d,%s,%s,%s,%d,%s,%s\n", student.id, student.nome, student.dataNascimento, student.curso, student.anoIngresso, student.telefone, student.endereco);
    fclose(file);
    return 0;
}

int printStudents()
{
    char filename[100] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";

    for (int i = 0; i < 20; i++)
    {
        char line[200];
        char currentFilename[5] = "";
        currentFilename[0] = filename[i];
        strcat(currentFilename, ".txt");
        FILE *file = fopen(currentFilename, "r");
        if (file == NULL)
        {
            continue;
        }
        while (fgets(line, sizeof(line), file))
        {
            printf("%s", line);
        }
        fclose(file);
    }

    return 0;
}

int editStudent()
{
    char firstLetter;
    char filename[5] = "";
    char lines[100][200];
    int lineCount = 0;
    int id;
    int option;
    int found = 0;
    
    printf("Digite a letra inicial do nome do aluno: ");
    getchar();
    scanf("%c", &firstLetter);
    filename[0] = firstLetter;
    strcat(filename, ".txt");
    FILE *file = fopen(filename, "r");
    if (file == NULL)
    {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }
    while (fgets(lines[lineCount], sizeof(lines[lineCount]), file))
    {
        printf("%s", lines[lineCount]);
        lineCount++;
    }
    fclose(file);
    
    printf("Digite o ID do aluno que deseja editar: ");
    getchar();
    scanf("%d", &id);

    
    for (int i = 0; i < lineCount; i++)
    {
        struct Student student;
        sscanf(lines[i], "%d,%[^,],%[^,],%[^,],%d,%[^,],%[^\n]", &student.id, student.nome, student.dataNascimento, student.curso, &student.anoIngresso, student.telefone, student.endereco);
        if (student.id == id)
        {
            found = 1;
            printf("Digite a opcao que deseja editar: \n");
            printf("1) Data de Nascimento\n");
            printf("2) Curso\n");
            printf("3) Ano de Ingresso\n");
            printf("4) Telefone\n");
            printf("5) Endereco\n");
            scanf("%d", &option);
            switch (option)
            {
            case 1:
                printf("Digite a nova data de nascimento: ");
                scanf("%s", student.dataNascimento);
                break;
            case 2:
                printf("Digite o novo curso: ");
                scanf("%s", student.curso);
                break;
            case 3:
                printf("Digite o novo ano de ingresso: ");
                scanf("%d", &student.anoIngresso);
                break;
            case 4:
                printf("Digite o novo telefone: ");
                scanf("%s", student.telefone);
                break;
            case 5:
                printf("Digite o novo endereco: ");
                scanf("%s", student.endereco);
                break;
            default:
                printf("Opcao invalida.\n");
                break;
            }
            sprintf(lines[i], "%d,%s,%s,%s,%d,%s,%s\n", student.id, student.nome, student.dataNascimento, student.curso, student.anoIngresso, student.telefone, student.endereco);
            break;
        }
    }
    if (!found)
    {
        printf("Aluno com ID %d nao encontrado.\n", id);
        return 1;
    }
    file = fopen(filename, "w");
    for (int i = 0; i < lineCount; i++)
    {
        fprintf(file, "%s", lines[i]);
    }
    fclose(file);
    printf("Aluno com ID %d editado com sucesso.\n", id);
    return 0;
}

int createStudent()
{
    struct Student student;
    printf("Digite o nome do aluno: ");
    scanf("%s", student.nome);
    printf("Digite a data de nascimento do aluno (DD/MM/AAAA): ");
    scanf("%s", student.dataNascimento);
    printf("Digite o curso do aluno: ");
    scanf("%s", student.curso);
    printf("Digite o ano de ingresso do aluno: ");
    scanf("%d", &student.anoIngresso);
    printf("Digite o telefone do aluno: ");
    scanf("%s", student.telefone);
    printf("Digite o endereco do aluno: ");
    scanf("%s", student.endereco);

    fopen("next_student_id.txt", "r");
    FILE *idFile = fopen("next_student_id.txt", "r");
    if (idFile == NULL)
    {
        student.id = 1;
    }
    else
    {
        fscanf(idFile, "%d", &student.id);
        fclose(idFile);
    }
    idFile = fopen("next_student_id.txt", "w");
    fprintf(idFile, "%d", student.id + 1);
    fclose(idFile);

    saveStudent(student);

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
            printStudents();
            break;
        case 2:
            createStudent();
            break;
        case 3:
            editStudent();
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

int scoreMenu()
{
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

int main()
{
    int option = 0;
    do
    {
        printf("1) Gerenciar alunos \n");
        printf("2) Gerenciar disciplinas\n");
        printf("3) Gerenciar notas\n");
        printf("4) Autores\n");
        printf("5) Sair\n");
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