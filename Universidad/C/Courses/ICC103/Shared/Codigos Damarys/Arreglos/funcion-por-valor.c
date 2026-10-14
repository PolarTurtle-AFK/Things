#include<stdio.h>
#include<stdlib.h>

void funcion_por_valor(int);

int main()
{
    int x=10;

    printf("Antes de llamar funcion x = %d\n",x);
    funcion_por_valor(x);

    printf("Luego de llamar funcion x = %d\n",x);
    system("PAUSE");
    return 0;

}
void funcion_por_valor(int x)
{
    x= 100;
}
