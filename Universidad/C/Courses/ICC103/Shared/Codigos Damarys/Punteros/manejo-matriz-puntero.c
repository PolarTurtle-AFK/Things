#include<stdio.h>
#include<stdlib.h>

#define MAX 10

void print_matriz(int *, int);

int main()
{
    int dim=3, M[dim][dim],  f, c, *pmat;

    printf("\nDigite valores matriz: \n");
    for(f=0;f<dim;f++)
    {
        for(c=0;c<dim;c++)
        {
            scanf("%d",&M[f][c]);
        }
    }
    pmat = &M[0][0];
    print_matriz(pmat,dim);

    system("PAUSE");
    return 0;

}
/*
 M --> apunta a &M[0][0]
 f * dim --> salta filas completas
 + c --> avanza columna
 * --> obtiene el valor

 int M[3][3] = {
   {10, 11, 12},
   {20, 21, 22},
   {30, 31, 32}};

Dirección -->  M[0][0]  M[0][1]  M[0][2]  M[1][0]  M[1][1]  M[1][2]  M[2][0]  M[2][1]  M[2][2]
Valor     -->    10       11       12       20       21       22       30       31       32
Índice    -->     0        1        2        3        4        5        6        7        8

int *p = &M[0][0];
p apunta al primer elemento de toda la matriz.

*(p + f * dim + c)

f * dim --> salto de filas

Fila 0 --> 0 * 3 = 0

Fila 1 --> 1 * 3 = 3

Fila 2 --> 2 * 3 = 6

Esto mueve el puntero al inicio de la fila deseada.

 + c --> moverse dentro de la fila

Columna 0 --> no se mueve

Columna 1 --> avanza 1 posición

Columna 2 --> avanza 2 posiciones

Ej:

f = 0, c = 2
*(p + 0*3 + 2) --> *(p + 2) → 12

f = 1, c = 0
*(p + 1*3 + 0) --> *(p + 3) → 20

f = 2, c = 1
*(p + 2*3 + 1) --> *(p + 7) → 31

*/
void print_matriz(int *M, int dim)
{
    int f, c;
    for(f=0;f<dim;f++)
    {
        for(c=0;c<dim;c++)
        {
            printf("%4d", *(M + f * dim +c));
        }
        printf("\n");
    }
}
