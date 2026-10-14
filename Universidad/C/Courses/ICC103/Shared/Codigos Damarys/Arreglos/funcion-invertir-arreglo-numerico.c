/*
Realice un programa que invierta los valores de un arreglo. En un vector de n-elementos
donde la posición i_ésima se reemplaza con el elemento que ocupa la posición n-i_ésima y
viceversa.
Ej: si el arreglo numeros tiene los siguientes valores:
25 3 8 9 -45


Al ejecutar el programa en la corrida se imprime el arreglo: así:
-45 9 8 3 25


-45 9 8 3 25 6
6 9 8 3 25 -45
6 25 8 3 9 -45
6 25 3 8 9 -45 i=2  j = 3

i=3 j=2
6 25 3 8
6 25 8 3 9 -45
6 9 8 3 25 -45
-45 9 8 3 25 6

*/

#include<stdlib.h>
#include<stdio.h>
#define MAX 100

void invertir_arreglo(int, int []);

int main()
{

    int n;

    do
    {
        printf("Digite cantidad de elementos: ");
        scanf("%d",&n);

        if(n<2)
        {
            printf("\aError!\nDigite un valor mayor que uno (1).\n");
            system("PAUSE");
            system("CLS");
        }
    }while(n<2);

    int numeros[n],i;

    //Llenar los valores del arreglo
    for(i=0;i<n;i++)
    {
        printf("Digite valor en numeros[%d]: ",i);
        scanf("%d",&numeros[i]);
    }
    invertir_arreglo(n,numeros); //invertir_arreglo(n,&numeros[0]);
    //imprimir valores
    for(i=0;i<n;i++)
        printf("%d\t",numeros[i]);

    printf("\n\n");
    system("PAUSE");
    return 0;
}
/*
Función: invertir_arreglo
Objetivo: Recibe un arreglo entero e invierte sus valores
En un vector de n-elemento donde la posición i_ésima
se reemplaza con el elemento que ocupa la posición n-i_ésima y
viceversa.
NO retorna
*/
void invertir_arreglo(int n, int numeros[n])
{
    int i, j, temp;

    for(i=0,j=n-1;i<n/2;i++,j--)
    {
        temp=numeros[i];
        numeros[i]=numeros[j];
        numeros[j]=temp;
    }
}
