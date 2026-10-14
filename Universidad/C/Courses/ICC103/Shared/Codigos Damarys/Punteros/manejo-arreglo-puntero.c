#include<stdio.h>
#include<stdlib.h>

#define MAX 10

void llenar_puntero(int *, int);
void mostrar_puntero(int *, int);
int mayor_puntero(int *, int);

int main()
{
    int n;

    do
    {
        printf("Digite cantidad de elementos: ");
        scanf("%d",&n);

        if(n<2)
        {
            printf("\aError!\nDigite un valor mayor que uno (1).\n\n");
            system("PAUSE");
            system("CLS");
        }
    }
    while(n<2);

    int nums[n];
    //llenar_puntero(&nums[0],n);
    llenar_puntero(nums,n);
    mostrar_puntero(nums,n);

    printf("\n\n\n");
    //imprimir valores a partir de la 3ra posición
    //mostrar_puntero(nums+2,2);

    printf("\nEl valor m%cs grande es: %d\n\n",160,mayor_puntero(nums,n));
    printf("\nEl valor m%cs grande es: %d\n\n",160,mayor_puntero(nums+2,2));
    printf("\n\n\n");
    system("PAUSE");
    return 0;

}
/*
Función: llenar_puntero
Objetivo: recibe un grupo de valores enteros (*nums)
y la cantidad de elementos n para capturar sus valores
NO RETORNA
*/
void llenar_puntero(int *nums, int n)
{
    int i;
    for(i=0; i<n; i++)
    {
        printf("Digite valor en [%d]: ",i);
        scanf("%d",nums+i); //scanf("%d",&nums[i]);
    }
}
/*
Función: mostrar_puntero
Objetivo: recibe un grupo de valores enteros (*nums)
y la cantidad de elementos n y los imprime por pantalla
NO RETORNA
*/
void mostrar_puntero(int *nums, int n)
{
    int i;
    for(i=0; i<n; i++)
    {
        printf("%4d",*(nums+i)); //NO ES LO MISMO *num+i
    }
    /*
    printf("\nSi no agrupo en ()\n");
    for(i=0;i<n;i++)
    {
        printf("%4d",*nums+i);
    }*/
}
/*
Función: mayor_puntero
Objetivo: recibe un grupo de valores enteros (*nums)
y la cantidad de elementos n, para determinar cual es
el valor más grande de dicho grupo
Retorna el valor más grande o mayor encontrado
*/
int mayor_puntero(int *nums, int n)
{
    int i, mayor=*nums; //asigno el valor de la primera posición
    for(i=0;i<n;i++)
    {
        if(*(nums+i) > mayor) //if(nums[i] > mayor)
            mayor=*(nums+i);
    }
    return mayor;
}
