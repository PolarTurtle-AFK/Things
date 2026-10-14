#include<stdio.h>
#include<stdlib.h>

int matriz_numerica(char *, int, int);
int matriz_numerica_otra(char *, int, int);

int main()
{
    char M[3][2] =
    {
        {'h', '6'},
        {'5', 'j'},
        {'7', '3'}
    };
    /*
    {
        {'1', '6'},
        {'5', '0'},
        {'7', '3'}
      };
    */

    if(matriz_numerica(&M[0][0],3,2))
        printf("\nMatriz ES num%crica\n",130);
    else
        printf("\nMatriz NO es num%crica\n",130);

    if(matriz_numerica_otra(&M[0][0],3,2))
        printf("\nMatriz ES num%crica\n",130);
    else
        printf("\nMatriz NO es num%crica\n",130);

    system("PAUSE");
    return 0;
}
/*
Función: matriz_numerica
Objetivo: recibe un puntero de una matriz y cantidad de filas y columnas
para determinar si dicha matriz solo contiene caracteres numéricos
Retorna 1 si es cierto, 0 si no lo es.
*/
int matriz_numerica(char *M, int filas, int columnas)
{
    int f,c, cont=0;
    for(f=0; f<filas; f++)
    {
        for(c=0; c<columnas; c++)
        {
            if(*(M + f * columnas + c) < '0' || *(M + f * columnas + c) > '9')
                return 0;

        }
    }

    return 1;


}
int matriz_numerica_otra(char *M, int filas, int columnas)
{
    int f,c, cont=0;
    for(f=0; f<filas; f++)
    {
        for(c=0; c<columnas; c++)
        {
            /* if(*(M + f * columnas + c) < '0' || *(M + f * columnas + c) > '9')
                 return 0;*/
            if(*(M + f * columnas + c) >= '0' && *(M + f * columnas + c) <= '9')
                cont++;
        }
    }
    if(cont == filas*columnas)
        return 1;
    else
        return 0;

}
