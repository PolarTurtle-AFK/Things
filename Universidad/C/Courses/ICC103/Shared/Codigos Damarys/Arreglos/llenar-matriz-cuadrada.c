#include<stdio.h>
#include<stdlib.h>
#define MAX 10

void llenar_matriz(int [][MAX], int);
void print_matriz(int [][MAX], int);

int main()
{
    int M[MAX][MAX], dimension;

    //validar tamaño de la dimension
    do
    {
        printf("Digite dimensi%cn de la matriz: ",162);
        scanf("%d",&dimension);

        if(dimension<2)
        {
            printf("\nError\nDigite un valor mayor o igual a dos (2).\n");
            system("PAUSE");
            system("CLS");
        }

    }
    while(dimension<2);

    llenar_matriz(M, dimension);
    print_matriz(M,dimension);
    system("PAUSE");
    return 0;

}
/*
Función: llenar_matriz
Objetivo: recibe una matriz vacía, y el tamaño de la dimensión
para ser llenada por el usuario
NO RETORNA
*/
void llenar_matriz(int M[][MAX], int dim)
{
    int f, c;
    for(f=0; f<dim; f++)
    {
        for(c=0; c<dim; c++)
        {
            printf("Digite un valor para M[%d][%d]: ",f,c);
            scanf("%d",&M[f][c]);
        }
    }
}
/*
Función: print_matriz
Objetivo: recibe una matriz, y el tamaño de la dimensión
y la imprime por pantalla
NO RETORNA
*/
void print_matriz(int M[][MAX], int dim)
{
    int f, c;
    for(f=0; f<dim; f++)
    {
        for(c=0; c<dim; c++)
            printf("%4d",M[f][c]);

        printf("\n");
    }
}

