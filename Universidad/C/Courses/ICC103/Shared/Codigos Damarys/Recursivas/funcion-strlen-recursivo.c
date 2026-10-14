/*
Haga una función recursiva que retorne la longitud de un string
pasado como parámetro.
*/
#include<stdio.h>
#include<stdlib.h>

#define MAX 100

int strlen_recursivo(char *);

int main()
{

    char texto[MAX];

    printf("Digite texto: ");
    gets(texto);

    printf("\nEl texto tiene %d caracteres\n",strlen_recursivo(texto+5));
    system("PAUSE");
    return 0;
}
/*
casa
c --> 1 + (asa)
             1 + (sa)
                   1 + (a)
                         1 + ('\0')
                                0
vuelve hacia atrás sumando 0 + 1 .... hasta llegar al inicio del texto
*/
int strlen_recursivo(char *s)
{
    if(*s=='\0')
        return 0;

    return 1 + strlen_recursivo(s+1);
}
/*
int strlen_recursivo(char *s)
{
    if(*s!='\0')
        return 1 + strlen_recursivo(s+1);

    return 0;
}
*/

