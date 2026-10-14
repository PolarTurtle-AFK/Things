#include<stdio.h>
#include<stdlib.h>
#define MAX 10

void print_matriz(int *, int, int);


int main()
{
    int filas=2, cols=3, M[2][3] = {
                                        {2,4,6},
                                        {1,3,5}
                                    };

    /*int *p;
    p = &M[0][0]; */
    print_matriz(&M[0][0],filas, cols); //Enviamos dirección en memoria de la primera posición de la matriz
    system("PAUSE");
    return 0;
}
void print_matriz(int *M, int filas, int cols)
{
    int f, c;
    for(f=0;f<filas;f++)
    {
        for(c=0;c<cols;c++)
            printf("%4d", *(M+f*cols+c));

        printf("\n");
    }
}
