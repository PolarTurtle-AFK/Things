#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ESTUDIANTES 5

typedef struct
{
    char nombre[40];
    char cedula[15];
} ESTUDIANTE;

typedef struct
{
    char materia[30];
    char codigo_curso[10];
    int n;
    ESTUDIANTE estudiantes[MAX_ESTUDIANTES];
} CURSO;

CURSO *buscar_curso_por_codigo(CURSO *cursos, int cantidad, char *codigo_buscado);

int main()
{
    CURSO crsos[2] =
    {
        {"Bases de Datos", "BD202", 1, {"Carlos Ruiz", "034050"}},
        {"Algoritmia", "ZTE456", 2, {"Sofia Castillo", "746856", "Edwin Perez", "927512"}}
    };

    CURSO *c = buscar_curso_por_codigo(crsos, 2, "BD202");

    if(c != NULL)
    {
        int i;
        printf("\nDatos en el main:\n");
        printf("Curso encontrado -> Materia: %s | Codigo: %s\n", c->materia, c->codigo_curso);
        for(i = 0; i < c->n; i++)
            printf("  Estudiante %d -> nombre: %s | cedula: %s\n", i+1, c->estudiantes[i].nombre, c->estudiantes[i].cedula);

        free(c);
    }

    return 0;
}

CURSO *buscar_curso_por_codigo(CURSO *cursos, int cantidad, char *codigo_buscado)
{
    printf("Buscando curso %s...\n", codigo_buscado);

    int i, j;
    int encontrado = 1;
    for(i = 0; i < cantidad; i++)
    {
        if(strncmp((cursos+i)->codigo_curso, codigo_buscado, strlen(codigo_buscado)) == 0)
        {
            encontrado = 0;
            break;
        }

    }

    if(encontrado)
    {
        puts("Curso no encontrado.");
        system("pause");
        return NULL;
    }
    else
    {
        CURSO *c = (CURSO *)calloc(1, sizeof(CURSO));

        printf("Curso encontrado -> Materia: %s | Codigo: %s\n", (cursos+i)->materia, (cursos+i)->codigo_curso);
        for(j = 0; j < cursos->n; j++)
            printf("  Estudiante %d -> nombre: %s | cedula: %s\n", j+1, cursos->estudiantes[j].nombre, cursos->estudiantes[j].cedula);

        *c = *(cursos+i);

        return c;
    }
}
