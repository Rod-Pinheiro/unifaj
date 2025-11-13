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

struct Discipline
{
    int id;
    char nome[42];
    char professor[42];
    char semestre[10];
    char curso[42];
};

struct Score
{
    int id;
    int studentId;
    char studentName[42];
    int disciplineId;
    char disciplineName[42];
    float avgScore;
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

int printStudents(char *filter)
{
    if (filter != NULL)
    {
        char filename[5] = "";
        filename[0] = filter[0];
        strcat(filename, ".txt");
        FILE *file = fopen(filename, "r");
        if (file == NULL)
        {
            printf("Erro ao abrir o arquivo.\n");
            return 1;
        }
        char line[200];
        while (fgets(line, sizeof(line), file))
        {
            printf("%s", line);
        }
        fclose(file);
        return 0;
    }

    char filename[100] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";

    for (int i = 0; i < 52; i++)
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

int saveDiscipline(struct Discipline discipline)
{
    FILE *file = fopen("disciplines.txt", "a");
    if (file == NULL)
    {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }
    fprintf(file, "%d,%s,%s,%s,%s\n", discipline.id, discipline.nome, discipline.professor, discipline.semestre, discipline.curso);
    fclose(file);
    return 0;
}

int createDiscipline()
{
    struct Discipline discipline;
    printf("Digite o nome da disciplina: ");
    scanf("%s", discipline.nome);
    printf("Digite o nome do professor: ");
    scanf("%s", discipline.professor);
    printf("Digite o semestre da disciplina: ");
    scanf("%s", discipline.semestre);
    printf("Digite o curso da disciplina: ");
    scanf("%s", discipline.curso);

    fopen("next_discipline_id.txt", "r");
    FILE *idFile = fopen("next_discipline_id.txt", "r");
    if (idFile == NULL)
    {
        discipline.id = 1;
    }
    else
    {
        fscanf(idFile, "%d", &discipline.id);
        fclose(idFile);
    }
    idFile = fopen("next_discipline_id.txt", "w");
    fprintf(idFile, "%d", discipline.id + 1);
    fclose(idFile);

    saveDiscipline(discipline);

    return 0;
}

int printDisciplines(int *idFilter)
{
    if (idFilter != NULL)
    {
        char line[200];
        FILE *file = fopen("disciplines.txt", "r");
        if (file == NULL)
        {
            printf("Erro ao abrir o arquivo.\n");
            return 1;
        }
        while (fgets(line, sizeof(line), file))
        {
            struct Discipline discipline;
            sscanf(line, "%d,%[^,],%[^,],%[^,],%[^\n]", &discipline.id, discipline.nome, discipline.professor, discipline.semestre, discipline.curso);
            if (discipline.id == *idFilter)
            {
                printf("%s", line);
            }
        }
        fclose(file);
        return 0;
    }
    char line[200];
    FILE *file = fopen("disciplines.txt", "r");
    if (file == NULL)
    {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }
    while (fgets(line, sizeof(line), file))
    {
        printf("%s", line);
    }
    fclose(file);
    return 0;
}

int editDiscipline()
{
    char lines[100][200];
    int id;
    int option;
    int found = 0;
    FILE *file = fopen("disciplines.txt", "r");
    if (file == NULL)
    {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }
    int lineCount = 0;
    while (fgets(lines[lineCount], sizeof(lines[lineCount]), file))
    {
        printf("%s", lines[lineCount]);
        lineCount++;
    }
    fclose(file);
    printf("Digite o ID da disciplina que deseja editar: ");
    getchar();
    scanf("%d", &id);
    for (int i = 0; i < lineCount; i++)
    {
        struct Discipline discipline;
        sscanf(lines[i], "%d,%[^,],%[^,],%[^,],%[^\n]", &discipline.id, discipline.nome, discipline.professor, discipline.semestre, discipline.curso);
        if (discipline.id == id)
        {
            found = 1;
            printf("Digite a opcao que deseja editar: \n");
            printf("1) Professor\n");
            printf("2) Semestre\n");
            printf("3) Curso\n");
            scanf("%d", &option);
            switch (option)
            {
            case 1:
                printf("Digite o novo professor: ");
                scanf("%s", discipline.professor);
                break;
            case 2:
                printf("Digite o novo semestre: ");
                scanf("%s", discipline.semestre);
                break;
            case 3:
                printf("Digite o novo curso: ");
                scanf("%s", discipline.curso);
                break;
            default:
                printf("Opcao invalida.\n");
                break;
            }
            sprintf(lines[i], "%d,%s,%s,%s,%s\n", discipline.id, discipline.nome, discipline.professor, discipline.semestre, discipline.curso);
            break;
        }
    }
    if (!found)
    {
        printf("Disciplina com ID %d nao encontrada.\n", id);
        return 1;
    }
    file = fopen("disciplines.txt", "w");
    for (int i = 0; i < lineCount; i++)
    {
        fprintf(file, "%s", lines[i]);
    }
    fclose(file);
    printf("Disciplina com ID %d editada com sucesso.\n", id);
    return 0;
}

int printScores(int *studentId, int *disciplineId)
{       
    char line[200];
    struct Score score;
    FILE *file = fopen("scores.txt", "r");
    if (file == NULL)
    {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

    while (fgets(line, sizeof(line), file))
    {
        sscanf(line, "%d,%d,%[^,],%d,%[^,],%f", &score.id, &score.studentId, score.studentName, &score.disciplineId, score.disciplineName, &score.avgScore);
        printf("Aluno: %s | Disciplina: %s | Media: %.2f\n", score.studentName, score.disciplineName, score.avgScore);
    }
    fclose(file);
    return 0;
}

int createScore()
{
    // TODO: Validar se o aluno e a disciplina existem antes de criar a nota
    char firstLetter;
    char filename[5] = "";
    char line[200];
    float firstBimester;
    float secondBimester;
    struct Score score;

    printf("Digite a primeira letra do nome do aluno: ");
    scanf(" %c", &firstLetter);
    // Bug: Quando a letra digitada não tem alunos cadastrados, o programa falha ao tentar abrir o arquivo. 
    // Mas a funcao continua para o proximo passo, que tambem falha ao tentar encontrar o aluno.
    printStudents(&firstLetter);

    printf("Digite o ID do aluno: ");
    scanf("%d", &score.studentId);

    // Find student name
    char studentFilename[5] = "";
    studentFilename[0] = firstLetter;
    strcat(studentFilename, ".txt");
    FILE *studentFile = fopen(studentFilename, "r");
    if (studentFile != NULL)
    {
        while (fgets(line, sizeof(line), studentFile))
        {
            struct Student s;
            sscanf(line, "%d,%[^,],%[^,],%[^,],%d,%[^,],%[^\n]", &s.id, s.nome, s.dataNascimento, s.curso, &s.anoIngresso, s.telefone, s.endereco);
            if (s.id == score.studentId)
            {
                strcpy(score.studentName, s.nome);
                break;
            }
        }
        fclose(studentFile);
    }

    printDisciplines(NULL);
    printf("Digite o ID da disciplina: ");
    scanf("%d", &score.disciplineId);

    // Find discipline name
    FILE *disciplineFile = fopen("disciplines.txt", "r");
    if (disciplineFile != NULL)
    {
        while (fgets(line, sizeof(line), disciplineFile))
        {
            struct Discipline d;
            sscanf(line, "%d,%[^,],%[^,],%[^,],%[^\n]", &d.id, d.nome, d.professor, d.semestre, d.curso);
            if (d.id == score.disciplineId)
            {
                strcpy(score.disciplineName, d.nome);
                break;
            }
        }
        fclose(disciplineFile);
    }




    printf("Digite a nota do primeiro bimestre: ");
    scanf("%f", &firstBimester);
    printf("Digite a nota do segundo bimestre: ");
    scanf("%f", &secondBimester);

    score.avgScore = (firstBimester + secondBimester) / 2.0;

    // Set score id
    FILE *idFile = fopen("next_score_id.txt", "r");
    if (idFile == NULL)
    {
        score.id = 1;
    }
    else
    {
        fscanf(idFile, "%d", &score.id);
        fclose(idFile);
    }
    idFile = fopen("next_score_id.txt", "w");
    fprintf(idFile, "%d", score.id + 1);
    fclose(idFile);

    FILE *file = fopen("scores.txt", "a");
    if (file == NULL)
    {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }
    fprintf(file, "%d,%d,%s,%d,%s,%.2f\n", score.id, score.studentId, score.studentName, score.disciplineId, score.disciplineName, score.avgScore);
    fclose(file);

    return 0;
}

int deleteScore()
{
    char firstLetter;
    char filename[5] = "";
    char line[200];
    int studentId;
    int disciplineId;
    int found = 0;
    char lines[100][200];
    int lineCount = 0;

    printf("Digite a primeira letra do nome do aluno: ");
    scanf(" %c", &firstLetter);
    
    // Verificar se existem alunos com a letra inicial
    char studentFilename[5] = "";
    studentFilename[0] = firstLetter;
    strcat(studentFilename, ".txt");
    FILE *studentFile = fopen(studentFilename, "r");
    if (studentFile == NULL)
    {
        printf("Nao existem alunos cadastrados com a letra '%c'.\n", firstLetter);
        return 1;
    }
    
    printStudents(&firstLetter);

    printf("Digite o ID do aluno: ");
    scanf("%d", &studentId);

    // Verificar se o aluno existe
    rewind(studentFile);
    int studentFound = 0;
    char studentName[42] = "";
    while (fgets(line, sizeof(line), studentFile))
    {
        struct Student s;
        sscanf(line, "%d,%[^,],%[^,],%[^,],%d,%[^,],%[^\n]", &s.id, s.nome, s.dataNascimento, s.curso, &s.anoIngresso, s.telefone, s.endereco);
        if (s.id == studentId)
        {
            strcpy(studentName, s.nome);
            studentFound = 1;
            break;
        }
    }
    fclose(studentFile);
    
    if (!studentFound)
    {
        printf("Aluno com ID %d nao encontrado.\n", studentId);
        return 1;
    }

    // Mostrar disciplinas que o aluno tem notas
    FILE *scoresFile = fopen("scores.txt", "r");
    if (scoresFile == NULL)
    {
        printf("Erro ao abrir arquivo de notas.\n");
        return 1;
    }
    
    printf("Disciplinas do aluno %s:\n", studentName);
    while (fgets(line, sizeof(line), scoresFile))
    {
        struct Score score;
        sscanf(line, "%d,%d,%[^,],%d,%[^,],%f", &score.id, &score.studentId, score.studentName, &score.disciplineId, score.disciplineName, &score.avgScore);
        if (score.studentId == studentId)
        {
            printf("ID: %d - %s\n", score.disciplineId, score.disciplineName);
        }
    }
    fclose(scoresFile);

    printf("Digite o ID da disciplina: ");
    scanf("%d", &disciplineId);

    // Ler todas as notas para o array
    scoresFile = fopen("scores.txt", "r");
    if (scoresFile == NULL)
    {
        printf("Erro ao abrir arquivo de notas.\n");
        return 1;
    }
    
    while (fgets(lines[lineCount], sizeof(lines[lineCount]), scoresFile))
    {
        lineCount++;
    }
    fclose(scoresFile);

    // Procurar e remover a nota
    for (int i = 0; i < lineCount; i++)
    {
        struct Score score;
        sscanf(lines[i], "%d,%d,%[^,],%d,%[^,],%f", &score.id, &score.studentId, score.studentName, &score.disciplineId, score.disciplineName, &score.avgScore);
        if (score.studentId == studentId && score.disciplineId == disciplineId)
        {
            found = 1;
            // Remover a linha movendo as próximas para cima
            for (int j = i; j < lineCount - 1; j++)
            {
                strcpy(lines[j], lines[j + 1]);
            }
            lineCount--;
            break;
        }
    }

    if (!found)
    {
        printf("Nao existe nota cadastrada para o aluno %s na disciplina selecionada.\n", studentName);
        return 1;
    }

    // Reescrever o arquivo sem a nota removida
    scoresFile = fopen("scores.txt", "w");
    for (int i = 0; i < lineCount; i++)
    {
        fprintf(scoresFile, "%s", lines[i]);
    }
    fclose(scoresFile);
    
    printf("Nota do aluno %s excluida com sucesso.\n", studentName);
    
    return 0;
}
// MENUS
int disciplineMenu()
{
    int option = 0;
    do
    {
        printf("1) Consultar disciplina\n");
        printf("2) Cadastrar disciplina\n");
        printf("3) Editar disciplina\n");
        printf("4) Voltar ao menu inicial\n");
        scanf("%d", &option);
        switch (option)
        {
        case 1:
            printDisciplines(NULL);
            break;
        case 2:
            createDiscipline();
            break;
        case 3:
            editDiscipline();
            break;
        case 4:
            printf("Voltando ao menu principal...\n");
        default:
            break;
        }
    } while (option != 4);
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
            printStudents(NULL);
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

int scoreMenu()
{
    int option = 0;
    do
    {
        printf("1) Consultar notas\n");
        printf("2) Cadastrar notas\n");
        printf("3) Excluir nota\n");
        printf("4) Voltar ao menu inicial\n");
        scanf("%d", &option);
        switch (option)
        {
        case 1:
            printScores(NULL, NULL);
            break;
        case 2:
            createScore();
            break;
        case 3:
            deleteScore();
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
            scoreMenu();
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