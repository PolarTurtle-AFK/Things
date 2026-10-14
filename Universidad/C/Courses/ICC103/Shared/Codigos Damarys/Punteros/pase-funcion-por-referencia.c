#include<stdio.h>
#include<stdlib.h>
void funcion_por_referencia(int *);

int main()
{
    int num;

    printf("Digite un valor: ");
    scanf("%d",&num);

    printf("\nValor Antes de llamada funci%cn: %d\n",162,num);
    funcion_por_referencia(&num);
    printf("\nValor Despu%cs de llamada funci%cn: %d\n",130,162,num);
    system("PAUSE");
    return 0;
}
void funcion_por_referencia(int *x)
{
    *x=45;
    printf("\nValor dentro de funci%cn: %d\n",162,*x);
}
