#include <stdio.h>
#include <stdlib.h>
#define MAX 100

int EsEspejoVertical(int *, int);

int main()
{
    int f, c;

    // Matriz 4x4 VÁLIDA para espejo vertical
    // Columna 0 es igual a Columna 3, Columna 1 es igual a Columna 2
    int M4[MAX][MAX] =
    {
        {1, 2, 2, 1},
        {5, 6, 6, 5},
        {9, 0, 0, 9},
        {3, 4, 4, 3}
    };
    int n4 = 4;

    // Matriz 5x5 INVÁLIDA para espejo vertical
    int M5[MAX][MAX] =
    {
        {1, 2, 3, 4, 5},
        {6, 7, 8, 9, 0},
        {3, 2, 1, 4, 6},
        {6, 7, 8, 9, 3},
        {1, 2, 3, 4, 5}
    };
    int n5 = 5;

    int *p;

    p = &M4[0][0];
    printf("Matriz 4x4:\n");
    for (f = 0; f < n4; f++)
    {
        for (c = 0; c < n4; c++)
            printf("%4d", *(p + f * MAX + c));
        printf("\n");
    }
    if (EsEspejoVertical(p, n4))
        printf("La matriz ES espejo vertical.\n\n");
    else
        printf("La matriz NO es espejo vertical.\n\n");

    p = &M5[0][0];
    printf("Matriz 5x5:\n");
    for (f = 0; f < n5; f++)
    {
        for (c = 0; c < n5; c++)
            printf("%4d", *(p + f * MAX + c));
        printf("\n");
    }
    if (EsEspejoVertical(p, n5))
        printf("La matriz ES espejo vertical.\n\n");
    else
        printf("La matriz NO es espejo vertical.\n\n");

    system("PAUSE");
    return 0;
}

int EsEspejoVertical(int *M, int n)
{
    int f, c;
    // Recorremos todas las filas, pero solo hasta la mitad de las columnas (n / 2)
    for (f = 0; f < n; f++)
        for (c = 0; c < n / 2; c++)
            // Compara la columna 'c' con su simétrica 'n - 1 - c' en la misma fila (f * MAX)
            if (*(M + f * n + c) != *(M + f * n + (n - 1 - c)))
                return 0;
    return 1;
}
