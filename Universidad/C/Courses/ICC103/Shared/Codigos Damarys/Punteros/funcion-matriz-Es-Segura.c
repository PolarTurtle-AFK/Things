#include <stdio.h>
#include <stdlib.h>

int matriz_Es_Segura(int *, int);
void mostrarMatriz(int *, int);

int main()
{
    int M1[3][3] =
    {
        {4, 3, 5},
        {12, 6, 5},
        {10, 12, 8}
    };
    int M2[3][3] =
    {
        {4, 3, 7},
        {12, 5, 9},
        {13, 14, 6}
    };

    mostrarMatriz(&M1[0][0], 3);
    if (matriz_Es_Segura(&M1[0][0], 3))
        printf("La matriz es segura\n\n");
    else
        printf("La matriz NO es segura\n\n");

    mostrarMatriz(&M2[0][0], 3);
    if (matriz_Es_Segura(&M2[0][0], 3))
        printf("La matriz es segura\n\n");
    else
        printf("La matriz NO es segura\n\n");

    system("PAUSE");
    return 0;
}

int matriz_Es_Segura(int *m, int orden)
{
    int f, c;
    float promedio;

    // Diagonal principal: todos pares, y se acumula para el promedio
    for (f = 0; f < orden; f++)
    {
        if (*(m + f * orden + f) % 2 != 0)
            return 0;
        promedio += *(m + f * orden + f);
    }
    promedio /= orden;

    // Fuera de la diagonal: por encima en [0, promedio], por debajo en [promedio, 2*promedio]
    for (f = 0; f < orden; f++)
    {
        for (c = 0; c < orden; c++)
        {
            if (c > f)
            {
                if (*(m + f * orden + c) < 0 || *(m + f * orden + c) > promedio)
                    return 0;
            }
            else if (c < f)
            {
                if (*(m + f * orden + c) < promedio || *(m + f * orden + c) > 2 * promedio)
                    return 0;
            }
        }
    }

    return 1;
}

void mostrarMatriz(int *M, int n)
{
    int f, c;

    for (f = 0; f < n; f++)
    {
        for (c = 0; c < n; c++)
        {
            printf("%4d", *(M + f * n + c));
        }
        printf("\n");
    }
}
