#include<stdio.h>
#include<stdlib.h>

void print_valores(int *, int);
int main()
{
    int *num, i=0, temp;

    do
    {
        printf("Digite un valor: ");
        scanf("%d",&temp);

        if(i==0)
            num=(int *)calloc(1,sizeof(int)); //num=(int *)malloc(sizeof(int));
        else
            num=(int *)realloc(num,(i+1)*sizeof(int));

        *(num+i) = temp;

        i++;
    }while(temp!=0);

    print_valores(num,i);

    free(num);
    system("PAUSE");
    return 0;
}
void print_valores(int *num, int n)
{
    int i;
    for(i=0;i<n;i++)
        printf("%d\t",*(num+i));

    printf("\n");
}
