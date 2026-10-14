#include<stdio.h>
#include<stdlib.h>
#define MAX 10

void llenar_matriz(int [][MAX], int, int);
void print_matriz(int [][MAX], int, int);

int main()
{
    int M[MAX][MAX], filas, cols;

    //validar cantidad de filas
    do
    {
        printf("Digite cantidad de filas: ");
        scanf("%d",&filas);

        if(filas<2)
        {
            printf("\nError\nDigite un valor mayor o igual a dos (2).\n");
            system("PAUSE");
            system("CLS");
        }

    }
    while(filas<2);

    //validar cantidad de columnas
    do
    {
        printf("Digite cantidad de columnas: ");
        scanf("%d",&cols);

        if(cols<2)
        {
            printf("\nError\nDigite un valor mayor o igual a dos (2).\n");
            system("PAUSE");
            system("CLS");
        }

    }
    while(cols<2);

    llenar_matriz(M, filas, cols);
    print_matriz(M,filas,cols);
    system("PAUSE");
    return 0;

}
/*
Función: llenar_matriz
Objetivo: recibe una matriz vacía, cantidad de filas y de columnas
para ser llenada por el usuario
NO RETORNA
*/
void llenar_matriz(int M[][MAX], int filas, int cols)
{
    int f, c;
    for(f=0; f<filas; f++)
    {
        for(c=0; c<cols; c++)
        {
            printf("Digite un valor para M[%d][%d]: ",f,c);
            scanf("%d",&M[f][c]);
        }
    }
}
/*
Función: print_matriz
Objetivo: recibe una matriz, cantidad de filas y de columnas
y la imprime por pantalla
NO RETORNA
*/
void print_matriz(int M[][MAX], int filas, int cols)
{
    int f, c;
    for(f=0; f<filas; f++)
    {
        for(c=0; c<cols; c++)
        {
            printf("%4d",M[f][c]);
        }
        printf("\n");
    }
}

