#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
    Constantes
*/

#define MIN_LIBROS 2      // Mínimo de libros en el catálogo
#define MAX_LIBROS 10     // Máximo de libros en el catálogo
#define MIN_ESTUDIANTES 1 // Mínimo de estudiantes
#define MAX_ESTUDIANTES 5 // Máximo de estudiantes
#define MAX_PRESTAMOS 5   // Máximo de préstamos por estudiante

/*
    Estructuras
*/

typedef struct
{
    char Titulo[50];
    char Nombre[50];
    int Cantidad;
} Libro;

typedef struct
{
    Libro *libro;
    int cant_prestamos;
} Prestamo;

typedef struct
{
    char ID[12];
    char Nombre[50];
    int Cantidad;
    Prestamo *Listado;
} Estudiante;

/*
    Prototipo Funciones
*/

char *mi_gets();
int validar(int cant_libros);
// Registrar libros:
int registrar_libros(Libro *catalogo);
// Registrar estudiantes:
void registrar_estudiantes(Estudiante *estudiantes, Libro *catalogo, int cant_libros);
// Función recursiva:
// Mostrar un reporte final que incluya
// int total_prestados(Prestamo *prestamos, int cantidad);

int numerobueno();
/*
    Main
*/
int main()
{
    Libro catalogo[MAX_LIBROS];
    int cant_libros = registrar_libros(catalogo);
    registrar_libros(catalogo);
    Estudiante estudiantes[MAX_ESTUDIANTES];
    registrar_estudiantes(estudiantes, catalogo, cant_libros);
    // registrar_prestamos();
    // mostrar_reporte();

    return 0;
}

/*
    Funciones
*/

char *mi_gets()
{
    char *s = NULL;
    char c;
    int i;

    do
    {
        i = 0;
        while ((c = getchar()) != '\n' && c != EOF)
        {
            if (i == 0)
            {
                s = (char *)calloc(i + 1, sizeof(char));
            }
            else
            {
                s = (char *)realloc(s, (i + 1) * sizeof(char));
            }
            *(s + i) = c;
            i++;
        }

        // Si i == 0 ignifsica que presionó Enter sin escribir nada
        if (i == 0)
        {
            printf("El campo no puede estar vacio. Intente de nuevo: ");
        }
    } while (i == 0); // Se repite si no digitó nada

    s = (char *)realloc(s, (i + 1) * sizeof(char));
    *(s + i) = '\0';
    return s;
}

int validar(int cant_libros)
{
    if (cant_libros < MIN_LIBROS)
    {
        return -1;
    }
    else if (cant_libros > MAX_LIBROS)
    {
        return -2;
    }

    return 1;
}

int numerobueno()
{
    int numero;
    while (scanf("%d", &numero) != 1 || numero <= 0)
    {
        printf("Debe introducir un valor num%crico!!\n", 130);
        while (getchar() != '\n');
        
    }
    while (getchar() != '\n');
    return numero;
}

int registrar_libros(Libro *catalogo)
{

    int cant_libros;
    do
    {
        printf("\nIngrese la cantidad de libros (min %d, max %d): ", MIN_LIBROS, MAX_LIBROS);
        cant_libros = numerobueno();
        if (cant_libros < MIN_LIBROS || cant_libros > MAX_LIBROS)
        {
            printf("Cantidad invalida. Debe estar entre %d y %d.\n", MIN_LIBROS, MAX_LIBROS);
        }
    } while (cant_libros < MIN_LIBROS || cant_libros > MAX_LIBROS);

    for (int i = 0; i < cant_libros; i++)
    {
        char *titulo;
        char *autor;
        int copias;

        printf("\n--- Libro %d ---\n", i + 1);

        printf("Titulo: ");
        titulo = mi_gets();
        strcpy((catalogo + i)->Titulo, titulo);
        free(titulo);

        printf("Autor: ");
        autor = mi_gets();
        strcpy((catalogo + i)->Nombre, autor);
        free(autor);

        printf("Copias disponibles: ");
        copias = numerobueno();
        (catalogo + i)->Cantidad = copias;
    }
    return cant_libros;
}

void registrar_estudiantes(Estudiante *estudiantes, Libro *catalogo, int cant_libros)
{
    int cant_estudiantes;
    do
    {
        printf("\nIngrese la cantidad de estudiantes (min %d, max %d): ", MIN_ESTUDIANTES, MAX_ESTUDIANTES);
        cant_estudiantes = numerobueno();
        if (cant_estudiantes < MIN_ESTUDIANTES || cant_estudiantes > MAX_ESTUDIANTES)
        {
            printf("Cantidad invalida. Debe estar entre %d y %d.\n", MIN_ESTUDIANTES, MAX_ESTUDIANTES);
        }
    } while (cant_estudiantes < MIN_ESTUDIANTES || cant_estudiantes > MAX_ESTUDIANTES);

    for (int i = 0; i < cant_estudiantes; i++)
    {
        char *ID;
        char *nombre;
        int cant_prestamos;

        printf("\n--- Estudiante %d ---\n", i + 1);

        printf("ID: ");
        ID = mi_gets();
        strcpy((estudiantes + i)->ID, ID);
        free(ID);

        printf("Nombre: ");
        nombre = mi_gets();
        strcpy((estudiantes + i)->Nombre, nombre);
        free(nombre);
        
        printf("Ingrese numero de prestamos (max 5): ");
        cant_prestamos = numerobueno();
        (estudiantes + i)->Cantidad = cant_prestamos;


        printf("\nCatalogo\n");
        // catalogo->Titulo, catalogo->Nombre, catalogo->Cantidad

        // Catalogo:
        // 1. Programacion C - Dennis Ritchie (6 disponibles)
        // 2. Python - Mark Lutz (5 disponibles)
        // 3. Basics C - Robert C (5 disponibles)

        for (int j = 0; j < cant_libros; j++)
        {
            printf("%d. %s - %s (%d disponibles)\n", j + 1, (catalogo + j)->Titulo, (catalogo + j)->Nombre, (catalogo + j)->Cantidad);
        }

        //////////////// PRESTAMOS FUNCION
        (estudiantes + i)->Listado = (Prestamo *)malloc(cant_prestamos * sizeof(Prestamo))  ;
    }

}



/*
3
Programacion C
Dennis Ritchie
6
Python
Mark Lutz
5
Basics C
Robert C
5
2
2025-0001
Alicia Perez
2
1
1
2
1
2025-0002
Ramon Cruz
3
1
7
2
3
1
2
1

*/