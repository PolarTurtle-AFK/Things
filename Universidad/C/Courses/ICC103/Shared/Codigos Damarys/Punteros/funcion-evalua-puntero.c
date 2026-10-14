/*
Ejercicio No. 4 de EJERCICIOS ARREGLOS Y PUNTEROS

Se tiene los siguientes valores almacenados en un arreglo de enteros llamado X, los mismos
corresponden a los valores de x que se sedean evaluar en la función matemática
F(x) = 5x^4 + x^2 -10
 y llenar el arreglo Y.

*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void evalua(int *, int *, int);
int main()
{
    int x[3], i;
    int y[3];

    for(i = 0; i < 3; i++)
    {
        printf("Digite el numero #%d: ", i + 1);
        scanf("%d",(x+i));
    }
    evalua(x,y,3);
    for(i = 0; i < 3; i++)
        printf("%d\n", *(y+i));

    system("PAUSE");
    return 0;
}
void evalua(int *x, int *y, int n)
{
    int i;
    for(i=0;i<n;i++)
        *(y+i)=5*pow(*(x+i), 4) + pow(*(x+i), 2) - 10;
}
