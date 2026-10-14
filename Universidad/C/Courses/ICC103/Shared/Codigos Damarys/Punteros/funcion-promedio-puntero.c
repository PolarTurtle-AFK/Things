/*
Promedio de un puntero numérico
*/
#include<stdio.h>
#include<stdlib.h>

float promedio(int *, int);

int main()
{
    int n;

    do
    {
        printf("Digite cantidad de elementos: ");
        scanf("%d",&n);

        if(n<2)
        {
            printf("\nError!!!\a\nDigite un valor mayor que uno (1).\n");
            system("PAUSE");
            system("CLS");
        }

    }while(n<2);

    int num[n], i;

    for(i=0;i<n;i++)
    {
        printf("Digite valor para num[%d]: ",i);
        scanf("%d",(num+i));
    }

    printf("\nEl promedio de los valores es %.2f\n",promedio(num,n));

    system("PAUSE");
    return 0;
}
/*
Función: promedio
Objetivo: recibe un grupo de valores y determina el promedio de estos
Retorna el promedio calculado
*/
float promedio(int *num, int n)
{
    int i;
    float suma=0;

    for(i=0;i<n;i++)
        suma+= *(num+i);


    return suma/n;
}
