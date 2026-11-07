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
            printf("\nError!\nDigite un valor mayor que uno (1).\n");
            system("PAUSE");
            system("CLS");
        }
    }while(n<2);

    int *num,i; //num[n];

    num = (int *)calloc(n,sizeof(int));

    for(i=0;i<n;i++)
    {
        printf("Digite valor [%d]: ",i);
        scanf("%d",num+i);
    }

    for(i=0;i<n;i++)
        printf("%d\n",*(num+i));

    free(num);
    system("PAUSE");
    return 0;
}
