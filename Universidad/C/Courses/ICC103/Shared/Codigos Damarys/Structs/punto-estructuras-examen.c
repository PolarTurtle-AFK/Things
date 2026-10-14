#include<stdio.h>
#include<stdlib.h>
#define MAX_EXAMENES 5
#define MAX_CANDIDATOS 2

typedef struct
{
    char idExamen[4];
    char nombreExamen[30];
    float puntuacion;
    char aprobado; // 'A' 'F'
} EXAMEN;

typedef struct
{
    char id[9];
    char nombre[50];
    int edad;
    char puestoTrabajo[30];
    EXAMEN examenes[MAX_EXAMENES];
    int cantEx;
} CANDIDATO;


void imprimir_candidatos(CANDIDATO [], int);
void imprimir_mejor_candidato(CANDIDATO [], int);

int main()
{
    int i;

    CANDIDATO candidatos[MAX_CANDIDATOS] =
    {
        {
            "20250001",
            "Juan Perez",
            25,
            "Analista",
            {
                {"EX1", "Matemeticas", 85.0, 'A'},
                {"EX2", "Logica", 90.0, 'A'},
                {"EX3", "Programacion", 80.0, 'A'}
            },
            3
        },
        {
            "20250002",
            "Ana Lopez",
            27,
            "Desarrolladora",
            {
                {"EX1", "Matematicas", 95.0, 'A'},
                {"EX2", "Logica", 95.0, 'A'},
                {"EX3", "Programacion", 95.0, 'A'}
            },
            3
        }
    };
    // Imprimir todos los candidatos antes de calcular el mejor
    imprimir_candidatos(candidatos, MAX_CANDIDATOS);

    imprimir_mejor_candidato(candidatos, MAX_CANDIDATOS);

    system("PAUSE");
    return 0;
}
// Función que imprime todos los candidatos y sus exámenes
void imprimir_candidatos(CANDIDATO c[], int n)
{
    int i, j;
    printf("\n=== Lista de Candidatos ===\n");
    for (i = 0; i < n; i++)
    {
        printf("\nID: %s\n", c[i].id);
        printf("Nombre: %s\n", c[i].nombre);
        printf("Edad: %d\n", c[i].edad);
        printf("Puesto: %s\n", c[i].puestoTrabajo);
        printf("Ex%cmenes:\n",160);
        for (j = 0; j < c[i].cantEx; j++)
        {
            printf("  ID: %s | Nombre: %s | Nota: %.2f | Aprobado: %c\n",
                   c[i].examenes[j].idExamen,
                   c[i].examenes[j].nombreExamen,
                   c[i].examenes[j].puntuacion,
                   c[i].examenes[j].aprobado);
        }
    }
}

// Desarrollo de la función
void imprimir_mejor_candidato(CANDIDATO c[], int n)
{
    int i, j;
    int indiceMejor = -1;
    float suma, promedio, mayorPromedio = -1;

    for (i = 0; i < n; i++)
    {
        suma = 0;
        for (j = 0; j < c[i].cantEx; j++)
        {
            suma += c[i].examenes[j].puntuacion;
        }

        promedio = suma / c[i].cantEx;

        if (promedio > mayorPromedio)
        {
            mayorPromedio = promedio;
            indiceMejor = i;
        }
    }

    if (indiceMejor != -1)
    {
        printf("\n=== Mejor Candidato ===\n");
        printf("ID: %s\n", c[indiceMejor].id);
        printf("Nombre: %s\n", c[indiceMejor].nombre);
        printf("Edad: %d\n", c[indiceMejor].edad);
        printf("Puesto: %s\n", c[indiceMejor].puestoTrabajo);
        printf("Promedio: %.2f\n", mayorPromedio);
        printf("Ex%cmenes:\n",160);

        for (j = 0; j < c[indiceMejor].cantEx; j++)
        {
            printf("  ID: %s | Nombre: %s | Nota: %.2f | Aprobado: %c\n",
                   c[indiceMejor].examenes[j].idExamen,
                   c[indiceMejor].examenes[j].nombreExamen,
                   c[indiceMejor].examenes[j].puntuacion,
                   c[indiceMejor].examenes[j].aprobado);
        }
    }
    else
    {
        printf("No hay candidatos registrados.\n");
    }
}
