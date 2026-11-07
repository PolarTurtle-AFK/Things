#include<stdio.h>
#include<stdlib.h>

void inverso();

int main()
{
    printf("Digite un texto: ");
    inverso();

    printf("\n");
    system("PAUSE");
    return 0;
}
void inverso()
{
    char c;
    if((c=getchar())!='\n')
    {
        putchar(c); //para que prueben como se guarda en memoria
        inverso();
    }


    putchar(c);
    return; //retorna y vuelve atrás a recoger lo que dejó en memoria
            //desde el último char digitado antes de \n hasta el primero
}
