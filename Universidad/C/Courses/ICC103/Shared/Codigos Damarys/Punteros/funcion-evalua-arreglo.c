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

void evalua(int[], int[]);
int main()
{
    int arrayX[8] = {4,5,3,2,8,12,11,6}, arrayY[8];

    evalua(arrayX,arrayY);

    for(int i = 0; i < 8;i++)
    {
        printf("5(%d)^4 + %d^2 - 10 = %d",arrayX[i], arrayX[i],arrayY[i]);
        printf("\n");

    }

    system("PAUSE");
    return 0;

}
void evalua(int x[8], int y[8])
{
    for(int i = 0; i < 8;i++)
        y[i] = 5 * pow(x[i],4) + pow(x[i], 2) - 10;
}
