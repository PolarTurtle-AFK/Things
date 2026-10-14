#include<stdio.h>
#include<stdlib.h>
#define MAX 10

void llenar_matriz(int [][MAX], int, int);
void print_matriz(int [][MAX], int, int);

int main()
{
    int M[MAX][MAX];
    int fil, cols;

    //validar cantidad de filas sea al menos 2
    do
    {
        printf("Digite cantidad de filas: ");
        scanf("%d",&fil);

        if(fil < 2)
        {
            printf("\nError\nDigita una cantidad mayor o igual que dos (2).\n");
            system("PAUSE");
            system("CLS");
        }

    }while(fil < 2);

     //validar cantidad de columnas sea al menos 2
    do
    {
        printf("Digite cantidad de columnas: ");
        scanf("%d",&cols);

        if(cols < 2)
        {
            printf("\nError\nDigita una cantidad mayor o igual que dos (2).\n");
            system("PAUSE");
            system("CLS");
        }

    }while(cols < 2);


    llenar_matriz(M,fil,cols);
    print_matriz(M,fil,cols);

    system("PAUSE");
    return 0;

}
/*
Función: llenar_matriz
Objetivo: Recibe una matriz en blanco y cantidad de filas 'fil' y cantidad de columnas 'cols'
para ser llenada
NO RETORNA
*/
void llenar_matriz(int M[][MAX], int fil, int cols)
{
    int f, c;
    for(f=0;f<fil;f++)
    {
        for(c=0;c<cols;c++)
        {
            printf("Digite valor M[%d][%d]: ",f,c);
            scanf("%d",&M[f][c]);
        }
    }
}
/*
Función: print_matriz
Objetivo: Recibe una matriz, cantidad de filas 'fil' y cantidad de columnas 'cols'
para ser impresa en pantalla
NO RETORNA
*/
void print_matriz(int M[][MAX], int fil, int cols)
{
    int f, c;
    for(f=0;f<fil;f++)
    {
        for(c=0;c<cols;c++)
            printf("%4d", M[f][c]);

        printf("\n");
    }
}

