#include<stdio.h>
#include<stdlib.h>

int main()
{
    int n, *num;

    do
    {
        printf("Digite cantidad de elementos: ");
        scanf("%d",&n);

        if(n<2)
        {
            printf("\a\nError!\nDigite un valor mayor que uno 1.\n");
            system("PAUSE");
            system("CLS");
        }

    }while(n<2);

    //num = (int *)malloc(n*sizeof(int));
    num = (int *)calloc(n,sizeof(int));
    printf("\n%d\n",num); //ver direccion asignada
    int i;
    for(i=0;i<n;i++)
    {
        printf("Digite valor para num[%d]: ",i);
        scanf("%d",num+i);
    }

    for(i=0;i<n;i++)
        printf("%d\t",*(num+i));

    n+=1; //agregar un nuevo elemento
    num = (int *)realloc(num,n*sizeof(int));
    printf("\nDigite nuevo valor a agregar: ");
    scanf("%d",num+i);

    for(i=0;i<n;i++)
        printf("%d\t",*(num+i));

    printf("\n\n");
    free(num);
    system("PAUSE");
    return 0;

}
