/*
Haga una función numpal(s), la cual retorne el número de
palabras que contiene el string s. Considerar que las palabras
pueden estar separadas por más de un espacio en blanco. Por
ejemplo, si s = “Las mil y una noches “, la función debe
retornar 5.
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int numpal(char *);

int main()
{
    char s[]="Las mil y una noches";

    int cantpal= numpal(s);

    printf("\n\"%s\" tiene %d palabras.\n",s,cantpal);

    system("PAUSE");
    return 0;
}
/*Función: numpal
Objetivo: Determinar cantidad de palabras de un texto
Retorna la cantidad correspondiente*/
int numpal(char *s)
{
    int i, cont = 0;

    for(i=0; *(s+i)!='\0'; i++)
    {
        if(*(s+i)!=' ' && *(s+i+1)==' ' || *(s+i+1)==' ')
            cont++;
    }
    return cont;
}
