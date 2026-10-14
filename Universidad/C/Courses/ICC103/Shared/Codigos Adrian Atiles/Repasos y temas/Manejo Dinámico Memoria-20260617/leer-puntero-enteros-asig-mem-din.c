#include<stdio.h>
#include<stdlib.h>

void print_num(int *, int);

int main()
{
    int *num, n;

    do
    {
        printf("Digite cantidad de elementos: ");
        scanf("%d",&n);

        if(n<2)
        {
            printf("\aError!!!\nDigite un valor mayor a uno (1).\n");
            system("PAUSE");
            system("CLS");
        }
    }while(n<2);

    //Asignar dinámicamente espacios para el arreglo de valores
    //es decir el puntero num
    num=(int *)malloc(n*sizeof(int)); //Devolver la dirección en memoria
                                      //del primer espacio en memoria de num
                                      //o sea, dirección de memoria de num[0]
    //num=(int *)calloc(n*sizeof(int));
    int i;
    /*for(i=0;i<n;i++)
    {
        printf("Digite valor %d: ",i+1);
        scanf("%d",(num+i));
    }
*/
    print_num(num,n);
    free(num);
    system("PAUSE");
    return 0;

}
void print_num(int *num, int n)
{
    int i;
    for(i=0;i<n;i++)
        printf("%4d",*(num+i));

    printf("\n");
}
