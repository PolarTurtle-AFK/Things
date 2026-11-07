#include<stdio.h>
#include<stdlib.h>

char *mi_gets();

int main()
{
    char *s, c, *s2;
    int i=0;

    printf("Digite texto: ");
    while((c=getchar())!='\n')
    {
        if(i==0) //Es el primer espacio en memoria para el primer caracter leido
            s=(char *)calloc(i+1,sizeof(char));
        else
            s=(char *)realloc(s,(i+1)*sizeof(char));

        *(s+i)=c;
        i++;

    }
    s=(char *)realloc(s,(i+1)*sizeof(char));
    *(s+i) = '\0';

    puts(s);

    printf("Digite otro texto: ");
    s2 = mi_gets();

    puts(s2);

    free(s);

    system("PAUSE");
    return 0;
}
/*
Función: mi_gets
Objetivo: Crea dinámicamente un texto
Retornar puntero a dicho texto
*/
char *mi_gets()
{
    char *s, c;
    int i=0;

    while((c=getchar())!='\n' && c!=EOF)
    {
        if(i==0) //Es el primer espacio en memoria para el primer caracter leido
            s=(char *)calloc(i+1,sizeof(char));
        else
            s=(char *)realloc(s,(i+1)*sizeof(char));

        *(s+i)=c;
        i++;

    }
    s=(char *)realloc(s,(i+1)*sizeof(char));
    *(s+i) = '\0';

    return s;
}
