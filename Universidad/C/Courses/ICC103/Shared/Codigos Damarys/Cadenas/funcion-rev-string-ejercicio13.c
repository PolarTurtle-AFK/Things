/*
Haga una función rev(s) que invierta el string s.
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 100

void rev(char *);

int main()
{
    char s[MAX];

    printf("Digite un texto: ");
    gets(s);

    rev(s);
    puts(s);

    system("PAUSE");
    return 0;
}
/*
Función: rev
Objetivo: Recibe un string y lo invierte
es decir que cambia el contenido de la primera posición
por la última y así sucesivamente
amor --> roma
*/
void rev(char *s)
{
    int i, j, tam_s=strlen(s);
    char temp;

    for(i=0,j=tam_s-1;i<tam_s/2;i++,j--)
    {
        temp = *(s+i);
        *(s+i) = *(s+j);
        *(s+j) = temp;
    }
}
