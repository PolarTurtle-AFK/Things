/*
Escriba un programa en el se pidan dos matrices de n dimensión y muestra la matriz resultado
de sumar ambas matrices y la de la resta.
*/
#include<stdio.h>
#include<stdlib.h>
#define MAX 10

void llenar_matriz(int [][MAX], int);
void print_matriz(int [][MAX], int);
void sumar_matriz(int [][MAX], int [][MAX], int [][MAX], int);
int matriz_simetrica(int [][MAX], int);


int main()
{
    int M1[MAX][MAX], M2[MAX][MAX], M3[MAX][MAX];
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

    }
    while(dim < 2);

    system("CLS");
    printf("\nMATRICES\n\n");

    llenar_matriz(M1,dim);
    printf("\n\n");

    llenar_matriz(M2,dim);
    print_matriz(M1,dim);

    printf("\n\n");
    print_matriz(M2,dim);

    sumar_matriz(M1,M2,M3,dim);

    printf("\nResultado de la Suma\n\n");
    print_matriz(M3,dim);
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
    for(f=0; f<dim; f++)
    {
        for(c=0; c<dim; c++)
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
    for(f=0; f<dim; f++)
    {
        for(c=0; c<dim; c++)
            printf("%4d", M[f][c]);

        printf("\n");
    }
}
void sumar_matriz(int M1[][MAX], int M2[][MAX], int M3[][MAX], int dim)
{
    int f, c;
    for(f=0; f<dim; f++)
    {
        for(c=0; c<dim; c++)
            M3[f][c] = M1[f][c] + M2[f][c];
    }
}

