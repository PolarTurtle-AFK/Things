#include<stdio.h>
#include<stdlib.h>

int sustituir_repeticiones(int *, int, int);
int mostrar_matriz(int *, int, int);
int main()
{
    int cant;
    int M[3][3] =
    {
        {5, 3, 0},
        {8, 4, 2},
        {3, 2, 5}
    };

    mostrar_matriz(&M[0][0],3,3);
    printf("\n\nMatriz sustituta\n\n");
    cant= sustituir_repeticiones(&M[0][0],3,3);
    mostrar_matriz(&M[0][0],3,3);
    printf("\nCantidad de sustituciones: %d\n\n",cant);
    system("PAUSE");
    return 0;
}
/*Nombre: sustituir_repeticiones
Objetivo: sustituye por –1 todos los números diferentes de –1 que tengan más de una ocurrencia en una
matriz dada.
Retorna la cantidad de números que cumplieron esta condición.
*/
int sustituir_repeticiones(int *M, int filas, int columnas)
{
    int f, c, valoractual, cont, f2, c2, contsust=0;

    for(f=0; f<filas; f++)
    {
        for(c=0; c<columnas; c++)
        {
            valoractual = *(M+f*columnas+c);

            //Si el valor es distinto de menos -1,
            //entonces contar las ocurrencias o cuántas veces
            //se busca ese valor en el resto de la matriz
            if(valoractual != -1)
            {
                cont=0;
                for(f2=0; f2<filas; f2++)
                {
                    for(c2=0; c2<columnas; c2++)
                    {
                        if(valoractual == *(M+f2*columnas+c2))
                            cont++;
                    }
                }
                //si ese valor se repite más de una vez
                if(cont>1)
                {
                    //vamos a sustituir por -1
                    for(f2=0; f2<filas; f2++)
                    {
                        for(c2=0; c2<columnas; c2++)
                        {
                            if(valoractual == *(M+f2*columnas+c2))
                                *(M+f2*columnas+c2) = -1;
                        }
                    }
                    //cuento cuál valor se sustituyó
                    contsust++;
                }
            }
        }
    }
    return contsust;
}
int mostrar_matriz(int *M, int filas, int columnas)
{
    int f, c;
    for(f=0; f<filas; f++)
    {
        for(c=0; c<columnas; c++)
        {
            printf("%4d",*(M+f*columnas+c));
        }
        printf("\n");
    }
}
