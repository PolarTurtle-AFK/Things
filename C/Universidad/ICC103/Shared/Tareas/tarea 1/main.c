//Adrian Artiles ID: 10170038
//Joseph Ureña ID: 10164781
#include <stdio.h>
#include <stdlib.h>

void tam(int *, int *);

void leerint(int *);

int cuadrado(int *, int *);

void sudoku(int *, int *);

int validador(int *, int *, int *);

void mostrar_matriz(int *matriz, int *n);

int main()
{
    int n, k;

    tam(&n, &k);

    int matriz[n][n];

    sudoku(&matriz[0][0], &n);

    mostrar_matriz(&matriz[0][0], &n);

    if(validador(&matriz[0][0], &n, &k))
        printf("\nEl Sudoku es v%clido. Todas las filas, columnas y subcuadros contienen los n%cmeros del 1 al %d sin repetirse.\n", 160, 163, n);
    else
        printf("\nEl Sudoku no es v%clido.\n", 160);

    system("pause");
    return 0;
}

/*
Funcion: tam
Objetivo: recibe los punteros a n y k, luego solicita y valida el tamaño del Sudoku (4, 9 o 16)
y si todo sale bien sale del bucle while y vuelve al main
*/

void tam(int *n, int *k)
{
    while(1)
    {
        printf("Ingrese el tama%co del Sudoku (4, 9 o 16): ", 164);

        leerint(n);

        if(cuadrado(n,k))
        {
            system("cls");
            break;
        }
        else
        {
            printf("\n");
            puts("tiene que ser un numero cuadrado (4, 9, 16, 25...)");
            system("pause");
            system("cls");
        }
    }
}

/*
Funcion: leerint
Objetivo: Recibe un puntero entero a 'n' leyendo la entrada estándar y devuelve el valor que se digito y limpia el buffer
si hay error(como un caracter) y devuelve -1
*/
void leerint(int *n)
{
    if(scanf("%d", n) != 1)
    {
        while(getchar() != '\n');
        *n = -1;
    }
}

/*
Funcion: cuadrado.
Objetivo: Recibe punteros a 'n' y 'k'. Verifica si 'n' es un cuadrado perfecto y guarda su raíz en 'k'
*/
int cuadrado(int *n, int *k)
{
    int i;

    if(*n < 4)
        return 0;

    for(i = 2; i*i <= 16; i++)
    {
        if(*n == i*i)
        {
            *k = i;
            return 1;
        }
    }

    return 0;
}

/*
Funcion: Sudoku
Objetivo: Recibe punteros a la matriz y a 'n'. Solicita y valida los números ingresados por el usuario para llenar el Sudoku
y se va imprimiendo cada que se digita un numero, y en caso de dar error le dice al usuario que tiene que ciertos numeros y lo borra.
*/
void sudoku(int *matriz, int *n)
{
    int i, j, c;

    for(i = 0; i < *n * *n; i++)
    {
        while(1)
        {
            printf("Ingrese el tama%co del Sudoku (4, 9 o 16): %d\n", 164, *n);
            printf("Ingrese los n%cmeros del Sudoku (%dx%d):\n", 163, *n, *n);

            for(j = 0, c = *n; j < i; j++)
            {
                if(*n < 10)
                    printf("%d ", *(matriz+j));
                else
                    printf("%2d ", *(matriz+j));

                if(j+1 == c)
                {
                    printf("\n");
                    c += *n;
                }
            }

            leerint(matriz+i);

            if(*(matriz+i) < 1 || *(matriz+i) > *n)
            {
                printf("el valor debe estar entre 1 y %d\n", *n);
                system("pause");
                system("cls");
            }
            else
            {
                system("cls");
                break;
            }
        }
    }
}

/*
Funcion: validador
Objetivo: Recibe punteros a la matriz, a 'n' y a 'k'. Verifica que no haya números repetidos en filas, columnas y subcuadros
la logica al completo se explica en el documento.
*/
int validador(int *matriz, int *n, int *k)
{
    int i, j, c, r, x, y;

    //horizontal
    for(i = 0; i < *n; i++)
        for(j= 0; j < *n-1; j++)
            for(c = j+1; c < *n; c++)
                if(*(matriz+(i * *n)+j) == *(matriz+(i * *n)+c))
                    return 0;

    //vertical
    for(i = 0; i < *n; i++)
        for(j= 0; j < *n-1; j++)
            for(c = j+1; c < *n; c++)
                if(*(matriz+(j * *n)+i) == *(matriz+(c * *n)+i))
                    return 0;

    //subcuadro
    for(i = 0; i < *n; i += *k)
        for(j = 0; j < *n; j += *k)
            for(r = i; r < i + *k; r++)
                for(c = j; c < j + *k; c++)
                    for(x = r; x < i + *k; x++)
                        for(y = x == r ? c+1 : j; y < j + *k; y++)
                            if(*(matriz + (r * *n) + c) == *(matriz + (x * *n) + y))
                                return 0;

    return 1;
}

/*
Funcion: mostrar_matriz:
Objetivo: Recibe punteros a la matriz y a 'n'. Imprime la matriz en pantalla con un formato alineado.
*/
void mostrar_matriz(int *matriz, int *n)
{
    int f, c;

    printf("Ingrese el tama%co del Sudoku (4, 9 o 16): %d\n", 164, *n);
    printf("Ingrese los n%cmeros del Sudoku (%dx%d):\n", 163, *n, *n);
    for(f = 0; f < *n; f++)
    {
        for(c = 0; c < *n; c++)
        {
            if(*n < 10)
                printf("%d ", *(matriz + (f * *n) + c));
            else
                printf("%2d ", *(matriz + (f * *n) + c));
        }
        printf("\n");
    }
}
