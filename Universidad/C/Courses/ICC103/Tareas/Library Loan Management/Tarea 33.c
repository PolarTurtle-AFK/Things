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
    int cantidad_prestada;
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
int registrar_libros(Libro *catalogo);
void registrar_estudiantes(Estudiante *, Libro *, int );
int total_prestados(Prestamo *, int );
void registrar_prestamos(Estudiante *, Libro *, int );
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
    }
    while (i == 0);   // Se repite si no digitó nada

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
    }
    while (cant_libros < MIN_LIBROS || cant_libros > MAX_LIBROS);

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
    }
    while (cant_estudiantes < MIN_ESTUDIANTES || cant_estudiantes > MAX_ESTUDIANTES);

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

        do
        {
            printf("Ingrese numero de prestamos (max %d): ", MAX_PRESTAMOS);
            cant_prestamos = numerobueno();
            if (cant_prestamos > MAX_PRESTAMOS)
            {
                printf("Cantidad invalida. Debe estar entre 1 y %d.\n", MAX_PRESTAMOS);
            }
        }
        while (cant_prestamos > MAX_PRESTAMOS);
        
        (estudiantes + i)->Cantidad = cant_prestamos;                  
        registrar_prestamos(estudiantes + i, catalogo, cant_libros); 

    }

}

int total_prestados(Prestamo *prestamos, int cantidad)
{
    if (cantidad == 0)
    {
        return 0;
    }
    return (prestamos + cantidad - 1)->cantidad_prestada
           + total_prestados(prestamos, cantidad - 1);
}

void registrar_prestamos(Estudiante *est, Libro *catalogo, int cant_libros)
{
    est->Listado = (Prestamo *)malloc(est->Cantidad * sizeof(Prestamo));
    if (est->Listado == NULL)
    {
        printf("Error: no hay memoria.\n");
        exit(1);
    }

    for (int j = 0; j < est->Cantidad; j++)
    {
        int opcion, cantidad;

        printf("\nCatalogo:\n");
        for (int k = 0; k < cant_libros; k++)
        {
            printf("%d. %s - %s (%d disponibles)\n", k + 1,
                   (catalogo + k)->Titulo, (catalogo + k)->Nombre, (catalogo + k)->Cantidad);
        }

        printf("\n--- Prestamo %d ---\n", j + 1);
        do
        {
            printf("Seleccione el libro: ");
            opcion = numerobueno();
            if (opcion > cant_libros)
            {
                printf("Error: libro invalido.\n");
            }
        }
        while (opcion > cant_libros);

        Libro *libro = catalogo + (opcion - 1);

        do
        {
            printf("Cantidad prestada: ");
            cantidad = numerobueno();
            if (cantidad > libro->Cantidad)
            {
                printf("Error: solo hay %d copias disponibles. Intente de nuevo.\n", libro->Cantidad);
            }
        }
        while (cantidad > libro->Cantidad);

        libro->Cantidad -= cantidad;
        (est->Listado + j)->libro = libro;
        (est->Listado + j)->cantidad_prestada = cantidad;
        printf("Prestamo registrado. Copias restantes: %d\n", libro->Cantidad);
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