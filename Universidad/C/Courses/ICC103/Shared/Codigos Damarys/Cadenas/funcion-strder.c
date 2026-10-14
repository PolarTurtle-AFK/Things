/*
Haga una función strder(s,t), la cual retorne la posición
de la ocurrencia de t en s que esté más a la derecha. Por
ejemplo, si s = “Las ballenas asesinas” y t = “na”, en este caso
la función retorna 18.

*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 100

int strder_izq(char *, char*);
int strder_der(char *, char*);

int main()
{
    char s[MAX], t[MAX];

    printf("Digite un texto: ");
    gets(s);

    printf("Digite otro texto: ");
    gets(t);

    int retorno=strder_der(s,t);
    if(retorno>=0)
        printf("\n La ocurrencia mas a la derecha de \"%s\" en el primer texto es %d\n\n",t,retorno);
    else
        printf("\nEl texto \"%s\" no esta en el primer texto\n",t);

    retorno=strder_izq(s,t);
    if(retorno>=0)
        printf("\n La ocurrencia mas a la derecha de \"%s\" en el primer texto es %d\n\n",t,retorno);
    else
        printf("\nEl texto \"%s\" no esta en el primer texto\n",t);

    system("PAUSE");
    return 0;

}
int strder_izq(char *s, char *t)
{
    int i, pos=-1, len_t=strlen(t);
    for(i=0; *(s+i); i++)
    {
        if(strnicmp(s+i,t,len_t)==0)
            pos=i;
    }
    return pos; //No encontró el texto de t en s
}

int strder_der(char *s, char *t)
{
    int i, len_t=strlen(t);
    for(i=strlen(s)-1; i>=0; i--)
    {
        if(strnicmp(s+i,t,len_t)==0)
            return i;
    }
    return -1; //No encontró el texto de t en s
}
