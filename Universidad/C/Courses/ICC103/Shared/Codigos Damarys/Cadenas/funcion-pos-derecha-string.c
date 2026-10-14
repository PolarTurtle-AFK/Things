/*
Realice una función int pos_derecha_texto(char *s, char *p) la cual retorna la
posición de la ocurrencia de palabra en texto que esté más a la derecha.
Por ejemplo, si s = “La nina más bonita”, y palabra = “ni” en este caso la función retorna
14.
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 100

int pos_derecha_texto(char *, char *);
int pos_derecha_texto_mas_simple(char *, char *);

int main()
{
    char s[]="Las ballenas asesinas";
    char p[]="na";

    puts(s);
    puts(p);

    int retorno = pos_derecha_texto(s,p);

    if(retorno>=0)
        printf("\nLa posicion mas a la derecha de %s es %d\n",p,retorno);

    retorno = pos_derecha_texto_mas_simple(s,p);
    if(retorno>=0)
        printf("\nLa posicion mas a la derecha de %s es %d\n",p,retorno);

    system("PAUSE");
    return 0;

}
int pos_derecha_texto(char *s, char *p)
{
    int i, size_p = strlen(p), pos=-1;

    for(i=0; *(s+i)!='\0'; i++)
    {
        if(strnicmp(s+i,p,size_p)==0)
            pos=i;
    }
    return pos;
}
int pos_derecha_texto_mas_simple(char *s, char *p)
{
    int i, size_p = strlen(p);

    for(i=strlen(s)-1; i>=0; i--)
    {
        if(strnicmp(s+i,p,size_p)==0)
            return i;
    }
    return -1;
}

