#include<stdio.h>
#include<stdlib.h>

void imprimir(int *, int);

int main()
{
    int v[8], i;

    for(i=0; i<8; i++)
    {
        printf("Digite un valor en v[%d]: ",i);
        scanf("%d",v+i);//scanf("%d",&v[i]);
    }
    imprimir(v,8);
    printf("\n");
    imprimir(v+7,8);
    printf("\n");

    system("PAUSE");
    return 0;
}


void imprimir(int *v, int n)
{
    int i;
    for(i=0; i<n; i++)
        printf("%3d",*(v+i)); //*v+i
}
