#include<stdio.h>
#include<stdlib.h>

int main()
{
    int n;

    do
    {
        printf("Digite cantidad de elementos: ");
        scanf("%d",&n);

        if(n<2)
        {
            printf("\nError!\nDigite un valor mayor que uno (1)\n");
            system("PAUSE");
            system("CLS");
        }
    }while(n<2);
    int *valores, i;
    float prom=0;

    valores = (int *)malloc(n*sizeof(int)); // (int *)calloc(n,sizeof(int));
    for(i=0; i<n; i++)
    {
        printf("Digite un valor [%d]: ",i);
        scanf("%d",valores+i);

        prom+=*(valores+i);
    }
    for(i=0; i<n; i++)
        printf("%4d",*(valores+i));

    printf("\nEl promedio de los valores es: %.2f\n",prom/n);

    free(valores);
    system("PAUSE");
    return 0;
}
