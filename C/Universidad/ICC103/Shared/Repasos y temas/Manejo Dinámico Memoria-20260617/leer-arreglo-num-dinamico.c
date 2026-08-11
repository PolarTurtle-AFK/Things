#include<stdio.h>
#include<stdlib.h>

void print_valores(int *, int);

int main()
{
    int n, *num;

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

    num = (int *)calloc(n,sizeof(int));
    int i;

    for(i=0; i<n; i++)
    {
        printf("Digite valor para %d: ",i);
        scanf("%d",(num+i));
    }
    print_valores(num,n);
    free(num); //Liberar espacio en memoria del puntero
    system("PAUSE");
    return 0;
}
void print_valores(int *num, int n)
{
    int i;
    printf("\nValores del arreglo:\n");
    for(i=0;i<n;i++)
        printf("%d\t",*(num+i));

    printf("\n\n");
}
