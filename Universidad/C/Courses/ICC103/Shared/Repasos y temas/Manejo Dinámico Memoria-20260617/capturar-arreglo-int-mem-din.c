#include<stdio.h>
#include<stdlib.h>

void print_arreglo(int *, int);

int main()
{
    int i=0, num, *numeros;

    do
    {
        //si es el primer elemento del arreglo
        //reservo un espacio de memoria
        if(i==0)
            numeros = (int *)malloc(sizeof(int));

        //aumento el espacio de memoria
        else
            numeros = (int *)realloc(numeros,i+1*sizeof(int));

        printf("Digite un valor: ");
        scanf("%d",&num);

        *(numeros+i)=num;
        i++;

    }while(num!=0);
    printf("\nValores digitados\n\n");
    print_arreglo(numeros,i);
    printf("\n\n");

    free(numeros);
    system("PAUSE");
    return 0;
}
void print_arreglo(int *num, int n)
{
    int i;
    for(i=0; i<n; i++)
        printf("%d\t",*(num+i));
}
