#include<stdio.h>
#include<stdlib.h>

int sumar(int, int);
int sumar_rec(int, int);
int sumar_rec_2(int, int);

int main()
{
    int n1=26351, n2=5455;

    printf("%d + %d = %d\n",n1,n2,sumar(n1,n2));
    printf("%d + %d = %d\n",n1,n2,sumar_rec(n1,n2));
    printf("%d + %d = %d\n",n1,n2,sumar_rec_2(n1,n2));
    system("PAUSE");
    return 0;
}
/*
Función: sumar_rec
Objetivo: retorna el resultado de sumar dos valores de manera recursiva
Retorna el resultado de dicha suma
*/
int sumar(int n1, int n2)
{
    int i;
    for(i=1; i<=n2; i++)
        n1+=1;

    return n1;
}

int sumar_rec(int n1, int n2)
{
    if(n2==0)
        return n1;

    return sumar_rec(n1+1,n2-1);
}
int sumar_rec_2(int n1, int n2)
{
    if(n1==0)
        return n2;

    return sumar_rec(n1-1,n2+1);
}
