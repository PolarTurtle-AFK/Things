#include<stdio.h>
#include<stdlib.h>
#define MAX 10

void llenar_matriz(int [][MAX], int);
void print_matriz(int [][MAX], int);

int main()
{
    int M[MAX][MAX];
    int dim;

    //validar la dimensión de la matriz sea de al menos 2x2
    do
    {
        printf("Digite dimensi%cn: ",162);
        scanf("%d",&dim);

        if(dim < 2)
        {
            printf("\nError\nDigita una cantidad mayor o igual que dos (2).\n");
            system("PAUSE");
            system("CLS");
        }

    }while(dim < 2);

    llenar_matriz(M,dim);
    print_matriz(M,dim);

    system("PAUSE");
    return 0;

}
/*
Función: llenar_matriz
Objetivo: Recibe una matriz en blanco y la dimensión de esta
para ser llenada
NO RETORNA
*/
void llenar_matriz(int M[][MAX], int dim)
{
    int f, c;
    for(f=0;f<dim;f++)
    {
        for(c=0;c<dim;c++)
        {
            printf("Digite valor M[%d][%d]: ",f,c);
            scanf("%d",&M[f][c]);
        }
    }
}
/*
Función: print_matriz
Objetivo: Recibe una matriz  y la dimensión de esta
para ser impresa en pantalla
NO RETORNA
*/
void print_matriz(int M[][MAX], int dim)
{
    int f, c;
    for(f=0;f<dim;f++)
    {
        for(c=0;c<dim;c++)
            printf("%4d", M[f][c]);

        printf("\n");
    }
}

