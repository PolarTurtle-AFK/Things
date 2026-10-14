/*
Realice una función recursiva int multiplicacion_rec(int a, int b) que devuelva el resultado de
multiplicar a * b. (Multiplicación sucesiva).
Ej: 2 * 3 = 2 + 2 + 2 = 6
*/
#include<stdio.h>
#include<stdlib.h>

int multiplicacion_rec(int, int);
int multiplicacion(int, int);

int main()
{
    int num1, num2, mult, multrec;

    printf("Digite el multiplicando: ");
    scanf("%d",&num1);

    printf("Digite el multiplicador: ");
    scanf("%d",&num2);

    mult=multiplicacion(num1, num2);
    printf("\n%d * %d = %d\n\n",num1,num2,mult);

    multrec=multiplicacion_rec(num1, num2);
    printf("\n%d * %d = %d\n\n",num1,num2,multrec);

    system("PAUSE");
    return 0;
}
/*
    3*4 = 12
    3 + 3 + 3 + 3
    3 - 2 - 1 - 0
    4 + 4 + 4


*/
/*
Función: multiplicacion
Objetivo: determinar el resultado de multiplicar n1 * n2, mediante
sumas sucesivas
Devuelve el resultado de multiplicar n1*n2.
*/
int multiplicacion(int n1, int n2)
{
    int mult=0;

    while(n1>=1)
    {
        mult+=n2;
        n1--;
    }
    /*
    while(n2>=1)
    {
        mult+=n1;
        n2--;
    }
    */
    return mult;
}
/*
Función: multiplicacion_rec
Objetivo: determinar el resultado de multiplicar n1 * n2, mediante
sumas sucesivas recursivamente
Devuelve el resultado de multiplicar n1*n2.
*/
int multiplicacion_rec(int n1, int n2)
{
    if(n1==1)
        return n2;

    return n2 + multiplicacion_rec(n1-1,n2);
}
