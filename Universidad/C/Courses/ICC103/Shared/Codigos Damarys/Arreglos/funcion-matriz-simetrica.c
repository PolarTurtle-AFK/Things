#include<stdio.h>
#include<stdlib.h>
#define MAX 10
int es_simetrica(int, int [][MAX]);

int main()
{
    //Para corrida con valores fijos descomentar esta parte
    //y comentar donde se pide orden de matriz y se llena
   int orden=3, f, c, M[MAX][MAX]={{4,5,6},
                                    {5,1,3},
                                    {6,3,7}};
 /*   int orden, M[MAX][MAX];

    do
    {
        printf("Digite orden de la matriz: ");
        scanf("%d",&orden);

        if(orden<2)
        {
            printf("\nError!\nDigite un valor mayor que uno (1).\n");
            system("PAUSE");
            system("CLS");
        }


    }while(orden<2);

    int f,c;
    for(f=0;f<orden;f++)
    {
        for(c=0;c<orden;c++)
        {
            printf("Digite valor en M[%d][%d]: ",f,c);
            scanf("%d",&M[f][c]);
        }
    }
*/
    for(f=0;f<orden;f++)
    {
        for(c=0;c<orden;c++)
        {
            printf("%4d",M[f][c]);
        }
        printf("\n");
    }
    if(es_simetrica(orden,M))
        printf("\nLa matriz es Sim%ctrica\n",130);
    else
        printf("\nLa matriz NO es Sim%ctrica\n",130);

    system("PAUSE");
    return 0;
}
/*
Función: es_simetrica
Objetivo: determinar si una matriz es simétrica, es decir, si el
valor en la casilla f,c es igual al de la casilla c,f
Retorna 1 si es simétrica 0 si no lo es
*/
int es_simetrica(int orden, int M[][MAX])
{
    int f,c;

    for(f=0;f<orden;f++)
    {
        for(c=0;c<orden;c++)
        {
            if(M[f][c]!=M[c][f])
                return 0; //NO ES SIMETRICA
        }
    }
    return 1; //ES SIMETRICA
}

