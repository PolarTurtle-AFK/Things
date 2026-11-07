/*
 * ============================================================================
 *  PONTIFICIA UNIVERSIDAD CATOLICA MADRE Y MAESTRA
 *  Fundamentos de Programacion (ICC-103-TP) - Asignacion No. 3
 *  Library Loan Management
 * ----------------------------------------------------------------------------
 *  Descripcion:
 *    Registra un catalogo de libros y un grupo de estudiantes con sus
 *    prestamos. Cada prestamo descuenta de inmediato el stock del libro.
 *    Al final muestra un reporte con los prestamos, totales por estudiante
 *    (calculados de forma recursiva), estadisticas e inventario restante.
 *
 *  Notas de diseno:
 *    - Todo el acceso a libros, estudiantes y prestamos usa aritmetica de
 *      punteros: *(ptr + i) o (ptr + i)->miembro (sin indexacion con []).
 *    - Toda la memoria es dinamica (malloc/calloc), se valida que no sea
 *      NULL y se libera con free() asignando NULL a los punteros.
 *    - La lectura de texto es dinamica (getchar + malloc/realloc) y se
 *      detiene ante '\n' o EOF. No se usa gets().
 * ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* ---------------------------------------------------------------------------
 *  Constantes: limites del programa (se validan en toda captura)
 * ------------------------------------------------------------------------- */

#define MIN_LIBROS 2        /* Minimo de libros en el catalogo      */
#define MAX_LIBROS 10       /* Maximo de libros en el catalogo      */
#define MIN_ESTUDIANTES 1   /* Minimo de estudiantes                */
#define MAX_ESTUDIANTES 5   /* Maximo de estudiantes                */
#define MAX_PRESTAMOS 5     /* Maximo de prestamos por estudiante   */

/* ---------------------------------------------------------------------------
 *  Estructuras de datos
 * ------------------------------------------------------------------------- */

/* Libro del catalogo */
typedef struct
{
    char Titulo[50];    /* Titulo del libro                          */
    char Nombre[50];    /* Nombre del autor                          */
    int Cantidad;       /* Copias disponibles en la biblioteca       */
} Libro;

/* Prestamo: un libro + la cantidad de copias prestadas */
typedef struct
{
    Libro *libro;           /* Puntero al libro del catalogo (no es copia) */
    int cantidad_prestada;  /* Copias prestadas en este prestamo           */
} Prestamo;

/* Estudiante con su listado dinamico de prestamos */
typedef struct
{
    char ID[12];            /* Identificador del estudiante              */
    char Nombre[50];        /* Nombre del estudiante                     */
    int Cantidad;           /* Cantidad de prestamos realizados          */
    Prestamo *Listado;      /* Arreglo dinamico de prestamos             */
} Estudiante;

/* ---------------------------------------------------------------------------
 *  Prototipos
 * ------------------------------------------------------------------------- */

/* Lectura y validacion de datos */
char *mi_gets(void);
void leer_texto(char *destino, int tamano);
int numerobueno(void);
int leer_cantidad(const char *mensaje, int minimo, int maximo);
int leer_cantidad_prestada(int stock);

/* Registro de datos */
void registrar_libros(Libro *catalogo, int cant_libros);
void registrar_estudiantes(Estudiante *estudiantes, Libro *catalogo,
                           int cant_libros, int cant_estudiantes);
void registrar_prestamos(Estudiante *est, Libro *catalogo, int cant_libros);

/* Utilidades de inventario */
int hay_stock(Libro *catalogo, int cant_libros);

/* Calculo recursivo */
int total_prestados(Prestamo *prestamos, int cantidad);

/* Salida y limpieza */
void mostrar_reporte(Estudiante *estudiantes, int cant_estudiantes,
                     Libro *catalogo, int cant_libros);
void liberar_memoria(Estudiante **estudiantes, int cant_estudiantes,
                     Libro **catalogo);

/* ---------------------------------------------------------------------------
 *  main: solo coordina el flujo y delega el trabajo a las funciones
 * ------------------------------------------------------------------------- */

int main(void)
{
    Libro *catalogo = NULL;
    Estudiante *estudiantes = NULL;
    int cant_libros, cant_estudiantes;

    /* 1. Catalogo de libros */
    cant_libros = leer_cantidad("\nIngrese la cantidad de libros (min 2, max 10): ",
                                MIN_LIBROS, MAX_LIBROS);

    catalogo = (Libro *)malloc(cant_libros * sizeof(Libro));

    if (catalogo == NULL)
    {
        printf("Error: no hay memoria para los libros.\n");
        return 1;
    }

    registrar_libros(catalogo, cant_libros);

    /* 2. Estudiantes y sus prestamos */
    cant_estudiantes = leer_cantidad("\nIngrese la cantidad de estudiantes (min 1, max 5): ",
                                     MIN_ESTUDIANTES, MAX_ESTUDIANTES);

    /* calloc deja Listado en NULL, lo que hace seguro el free posterior */
    estudiantes = (Estudiante *)calloc(cant_estudiantes, sizeof(Estudiante));

    if (estudiantes == NULL)
    {
        printf("Error: no hay memoria para los estudiantes.\n");
        free(catalogo);
        catalogo = NULL;
        return 1;
    }

    registrar_estudiantes(estudiantes, catalogo, cant_libros, cant_estudiantes);

    /* 3. Reporte final */
    mostrar_reporte(estudiantes, cant_estudiantes, catalogo, cant_libros);

    /* 4. Liberar toda la memoria dinamica */
    liberar_memoria(&estudiantes, cant_estudiantes, &catalogo);

    return 0;
}

/* ---------------------------------------------------------------------------
 *  mi_gets: lee una linea completa de texto de tamano dinamico.
 *
 *  Lee caracter a caracter con getchar() y amplia el bloque con realloc()
 *  (usando un puntero auxiliar para no perder la referencia original).
 *  Se detiene ante '\n' o EOF. Si la linea esta vacia, vuelve a pedirla.
 *
 *  Retorna: cadena dinamica terminada en '\0' (el llamador debe liberarla)
 *           o NULL si se llego a EOF sin leer nada.
 * ------------------------------------------------------------------------- */

char *mi_gets(void)
{
    char *s = NULL;
    char *temp;
    int c, i = 0;

    s = (char *)malloc(sizeof(char));

    if (s == NULL)
    {
        printf("Error: no hay memoria.\n");
        exit(1);
    }

    while ((c = getchar()) != '\n' && c != EOF)
    {
        /* Espacio para el caracter nuevo y el '\0' final */
        temp = (char *)realloc(s, (i + 2) * sizeof(char));

        if (temp == NULL)
        {
            free(s);
            printf("Error: no hay memoria.\n");
            exit(1);
        }

        s = temp;
        *(s + i) = (char)c;
        i++;
    }

    /* EOF sin haber leido nada: no hay mas entrada */
    if (c == EOF && i == 0)
    {
        free(s);
        return NULL;
    }

    *(s + i) = '\0';

    /* No se permiten campos vacios */
    if (i == 0)
    {
        printf("El campo no puede estar vacio. Intente de nuevo: ");
        free(s);
        return mi_gets();
    }

    return s;
}

/* ---------------------------------------------------------------------------
 *  leer_texto: lee texto con mi_gets() y lo copia en un arreglo de tamano
 *  fijo sin excederlo, garantizando el terminador '\0'.
 *
 *  Parametros: destino - arreglo donde se copia el texto
 *              tamano  - tamano total de destino (incluye el '\0')
 * ------------------------------------------------------------------------- */

void leer_texto(char *destino, int tamano)
{
    char *texto = mi_gets();

    if (texto == NULL)
    {
        printf("\nFin de la entrada.\n");
        exit(1);
    }

    strncpy(destino, texto, tamano - 1);
    *(destino + tamano - 1) = '\0';

    free(texto);
    texto = NULL;
}

/* ---------------------------------------------------------------------------
 *  numerobueno: lee un numero entero positivo (> 0).
 *
 *  Repite la lectura hasta que el usuario escriba un valor valido y limpia
 *  el buffer del teclado (incluido el '\n' que deja scanf).
 * ------------------------------------------------------------------------- */

int numerobueno(void)
{
    int numero, resultado, c;

    while (1)
    {
        resultado = scanf("%d", &numero);

        if (resultado == EOF)
        {
            printf("\nFin de la entrada.\n");
            exit(1);
        }

        if (resultado == 1 && numero > 0)
        {
            /* Limpiar lo que quede en la linea */
            while ((c = getchar()) != '\n' && c != EOF)
                ;
            return numero;
        }

        printf("Debe introducir un numero entero positivo: ");

        /* Descartar la entrada invalida */
        while ((c = getchar()) != '\n' && c != EOF)
            ;

        if (c == EOF)
        {
            printf("\nFin de la entrada.\n");
            exit(1);
        }
    }
}

/* ---------------------------------------------------------------------------
 *  leer_cantidad: pide un entero dentro de [minimo, maximo].
 *
 *  Parametros: mensaje - texto que se muestra al usuario
 *              minimo, maximo - limites inclusivos permitidos
 *  Retorna: valor validado dentro del rango
 * ------------------------------------------------------------------------- */

int leer_cantidad(const char *mensaje, int minimo, int maximo)
{
    int cantidad;

    do
    {
        printf("%s", mensaje);
        cantidad = numerobueno();

        if (cantidad < minimo || cantidad > maximo)
        {
            printf("Cantidad invalida. Debe estar entre %d y %d.\n", minimo, maximo);
        }
    } while (cantidad < minimo || cantidad > maximo);

    return cantidad;
}

/* ---------------------------------------------------------------------------
 *  leer_cantidad_prestada: pide la cantidad de copias a prestar (> 0) y
 *  verifica que no exceda el stock actual del libro.
 *
 *  Parametros: stock - copias disponibles del libro (debe ser > 0)
 *  Retorna: cantidad valida, entre 1 y stock
 * ------------------------------------------------------------------------- */

int leer_cantidad_prestada(int stock)
{
    int cantidad;

    printf("Cantidad prestada: ");
    cantidad = numerobueno();

    while (cantidad > stock)
    {
        printf("Error: solo hay %d copias disponibles. Intente de nuevo.\n", stock);
        printf("Cantidad prestada: ");
        cantidad = numerobueno();
    }

    return cantidad;
}

/* ---------------------------------------------------------------------------
 *  registrar_libros: captura titulo, autor y copias de cada libro.
 *
 *  Parametros: catalogo - arreglo dinamico de libros ya reservado
 *              cant_libros - cantidad de libros a registrar
 * ------------------------------------------------------------------------- */

void registrar_libros(Libro *catalogo, int cant_libros)
{
    for (int i = 0; i < cant_libros; i++)
    {
        printf("\n--- Libro %d ---\n", i + 1);

        printf("Titulo: ");
        leer_texto((catalogo + i)->Titulo, 50);

        printf("Autor: ");
        leer_texto((catalogo + i)->Nombre, 50);

        printf("Copias disponibles: ");
        (catalogo + i)->Cantidad = numerobueno();   /* siempre > 0 */
    }
}

/* ---------------------------------------------------------------------------
 *  registrar_estudiantes: captura ID, nombre y cantidad de prestamos de cada
 *  estudiante, y luego delega el registro de sus prestamos.
 * ------------------------------------------------------------------------- */

void registrar_estudiantes(Estudiante *estudiantes, Libro *catalogo,
                           int cant_libros, int cant_estudiantes)
{
    for (int i = 0; i < cant_estudiantes; i++)
    {
        printf("\n--- Estudiante %d ---\n", i + 1);

        printf("ID: ");
        leer_texto((estudiantes + i)->ID, 12);

        printf("Nombre: ");
        leer_texto((estudiantes + i)->Nombre, 50);

        (estudiantes + i)->Cantidad =
            leer_cantidad("Ingrese numero de prestamos (max 5): ", 1, MAX_PRESTAMOS);

        registrar_prestamos(estudiantes + i, catalogo, cant_libros);
    }
}

/* ---------------------------------------------------------------------------
 *  hay_stock: indica si queda al menos un libro con copias disponibles.
 *
 *  Retorna: 1 si hay stock en algun libro, 0 si todos estan agotados
 * ------------------------------------------------------------------------- */

int hay_stock(Libro *catalogo, int cant_libros)
{
    for (int k = 0; k < cant_libros; k++)
    {
        if ((catalogo + k)->Cantidad > 0)
        {
            return 1;
        }
    }

    return 0;
}

/* ---------------------------------------------------------------------------
 *  registrar_prestamos: reserva el listado de prestamos de un estudiante y
 *  captura cada uno, descontando de inmediato el stock del catalogo.
 *
 *  - Muestra el catalogo con el stock actual antes de cada prestamo.
 *  - No permite elegir libros agotados ni prestar mas de lo disponible.
 *  - Si el catalogo se agota, termina los prestamos y ajusta la cantidad
 *    real de prestamos registrados (evita ciclos infinitos con stock 0).
 * ------------------------------------------------------------------------- */

void registrar_prestamos(Estudiante *est, Libro *catalogo, int cant_libros)
{
    est->Listado = (Prestamo *)malloc(est->Cantidad * sizeof(Prestamo));

    if (est->Listado == NULL)
    {
        printf("Error: no hay memoria para los prestamos.\n");
        exit(1);
    }

    for (int j = 0; j < est->Cantidad; j++)
    {
        int opcion, cantidad;
        Libro *libro;

        /* Si ya no queda nada que prestar, se cierran los prestamos */
        if (!hay_stock(catalogo, cant_libros))
        {
            printf("\nNo quedan copias disponibles. Prestamos registrados: %d.\n", j);
            est->Cantidad = j;
            break;
        }

        /* Mostrar catalogo con el stock actual */
        printf("\nCatalogo:\n");

        for (int k = 0; k < cant_libros; k++)
        {
            printf("%d. %s - %s (%d disponibles)\n",
                   k + 1,
                   (catalogo + k)->Titulo,
                   (catalogo + k)->Nombre,
                   (catalogo + k)->Cantidad);
        }

        printf("\n--- Prestamo %d ---\n", j + 1);

        /* Elegir un libro que tenga copias disponibles */
        do
        {
            opcion = leer_cantidad("Seleccione el libro: ", 1, cant_libros);
            libro = catalogo + (opcion - 1);

            if (libro->Cantidad == 0)
            {
                printf("Error: ese libro no tiene copias disponibles.\n");
            }
        } while (libro->Cantidad == 0);

        cantidad = leer_cantidad_prestada(libro->Cantidad);

        /* Descontar del stock en el momento del prestamo */
        libro->Cantidad -= cantidad;

        /* Guardar el prestamo apuntando al libro del catalogo (sin copiarlo) */
        (est->Listado + j)->libro = libro;
        (est->Listado + j)->cantidad_prestada = cantidad;

        printf("Prestamo registrado. Copias restantes: %d\n", libro->Cantidad);
    }
}

/* ---------------------------------------------------------------------------
 *  total_prestados: calcula de forma RECURSIVA el total de copias prestadas.
 *
 *  Procesa los prestamos de forma decreciente: suma el ultimo prestamo y se
 *  llama con una cantidad menor. Sin ciclos.
 *
 *  Caso base: cantidad == 0  ->  retorna 0
 *
 *  Parametros: prestamos - arreglo de prestamos del estudiante
 *              cantidad  - cuantos prestamos quedan por sumar
 * ------------------------------------------------------------------------- */

int total_prestados(Prestamo *prestamos, int cantidad)
{
    if (cantidad == 0)
    {
        return 0;
    }

    return (prestamos + cantidad - 1)->cantidad_prestada
           + total_prestados(prestamos, cantidad - 1);
}

/* ---------------------------------------------------------------------------
 *  mostrar_reporte: imprime el reporte final.
 *
 *  Incluye: prestamos y total por estudiante (recursivo), estudiantes con
 *  mas y menos libros prestados, libro mas prestado (en empate, el primero
 *  del catalogo) e inventario final.
 * ------------------------------------------------------------------------- */

void mostrar_reporte(Estudiante *estudiantes, int cant_estudiantes,
                     Libro *catalogo, int cant_libros)
{
    int *totales_libros;    /* Copias prestadas acumuladas por cada libro */
    int total, max_est = 0, min_est = 0;
    int max_libro = 0;

    totales_libros = (int *)calloc(cant_libros, sizeof(int));

    if (totales_libros == NULL)
    {
        printf("Error: no hay memoria para las estadisticas.\n");
        return;
    }

    printf("\n===== REPORTE DE PRESTAMOS =====\n");

    /* Detalle por estudiante + acumulado por libro + maximo y minimo */
    for (int i = 0; i < cant_estudiantes; i++)
    {
        printf("\nID: %s\n", (estudiantes + i)->ID);
        printf("Nombre: %s\n", (estudiantes + i)->Nombre);
        printf("Prestamos:\n");

        for (int j = 0; j < (estudiantes + i)->Cantidad; j++)
        {
            Prestamo *prestamo = (estudiantes + i)->Listado + j;
            Libro *libro = prestamo->libro;

            printf("  Prestamo %d: %s - %s, Cantidad: %d\n",
                   j + 1, libro->Titulo, libro->Nombre,
                   prestamo->cantidad_prestada);

            /* La resta de punteros da la posicion del libro en el catalogo */
            *(totales_libros + (libro - catalogo)) += prestamo->cantidad_prestada;
        }

        total = total_prestados((estudiantes + i)->Listado, (estudiantes + i)->Cantidad);

        printf("Total libros prestados: %d\n", total);

        if (i == 0)
        {
            max_est = min_est = total;
        }
        else
        {
            if (total > max_est)
            {
                max_est = total;
            }

            if (total < min_est)
            {
                min_est = total;
            }
        }
    }

    /* Estudiante(s) con mas libros prestados (se listan todos los empatados) */
    printf("\nEstudiante(s) con mas libros prestados (%d):\n", max_est);

    for (int i = 0; i < cant_estudiantes; i++)
    {
        total = total_prestados((estudiantes + i)->Listado, (estudiantes + i)->Cantidad);

        if (total == max_est)
        {
            printf("%s - %s\n", (estudiantes + i)->ID, (estudiantes + i)->Nombre);
        }
    }

    /* Estudiante(s) con menos libros prestados */
    printf("Estudiante(s) con menos libros prestados (%d):\n", min_est);

    for (int i = 0; i < cant_estudiantes; i++)
    {
        total = total_prestados((estudiantes + i)->Listado, (estudiantes + i)->Cantidad);

        if (total == min_est)
        {
            printf("%s - %s\n", (estudiantes + i)->ID, (estudiantes + i)->Nombre);
        }
    }

    /* Libro mas prestado: el ">" estricto conserva el primero en caso de empate */
    for (int i = 1; i < cant_libros; i++)
    {
        if (*(totales_libros + i) > *(totales_libros + max_libro))
        {
            max_libro = i;
        }
    }

    printf("\nLibro mas prestado (%d copias): %s - %s\n",
           *(totales_libros + max_libro),
           (catalogo + max_libro)->Titulo,
           (catalogo + max_libro)->Nombre);

    /* Inventario final */
    printf("\n===== INVENTARIO FINAL =====\n");

    for (int i = 0; i < cant_libros; i++)
    {
        printf("%s - %s: %d copias restantes\n",
               (catalogo + i)->Titulo,
               (catalogo + i)->Nombre,
               (catalogo + i)->Cantidad);
    }

    free(totales_libros);
    totales_libros = NULL;
}

/* ---------------------------------------------------------------------------
 *  liberar_memoria: libera toda la memoria dinamica.
 *
 *  Orden: primero el listado de prestamos de cada estudiante, luego el
 *  arreglo de estudiantes y por ultimo el catalogo. Recibe dobles punteros
 *  para dejar en NULL los punteros originales de main.
 * ------------------------------------------------------------------------- */

void liberar_memoria(Estudiante **estudiantes, int cant_estudiantes,
                     Libro **catalogo)
{
    for (int i = 0; i < cant_estudiantes; i++)
    {
        free((*estudiantes + i)->Listado);
        (*estudiantes + i)->Listado = NULL;
    }

    free(*estudiantes);
    *estudiantes = NULL;

    free(*catalogo);
    *catalogo = NULL;
}