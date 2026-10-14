#include<stdio.h>
#include<stdlib.h>

int main()
{
    int M[4][5];
    int valor, f, c, suma=0;

    for(f=0;f<4;f++)
    {
        for(c=0;c<5;c++)
        {
            printf("Desea ocupar asiento [%d][%d]: ",f,c);
            scanf("%d",&M[f][c]);

            if(M[f][c]==1)
                suma+=1;
        }
    }
    printf("\nTotal de asientos ocupados: %d\n",suma);

    system("PAUSE");
    return 0;
}
