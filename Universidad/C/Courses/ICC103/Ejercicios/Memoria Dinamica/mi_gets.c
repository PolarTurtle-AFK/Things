#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char *mi_gets(void);

int main()
{
    char *s2;
    s2 = mi_gets();
    puts(s2);
    free(s2);
    return 0;
}

/*
Funcion: mi_gets
Objetivo: Crea dinamicamente un texto
Retornar: puntero a dicho texto
*/
char *mi_gets(){

    char *s,c;
    int i=0;

    printf("Digite un texto: ");
    while((c=getchar())!='\n'){

        if(i==0){ // es el primer espacio en memoria para el primer caracter leido
            s=(char*)calloc(i+1,sizeof(char));
        }else{
            s=(char *)realloc(s,(i+1)*sizeof(char));
        }
        *(s+i)=c;
        i++;
    }
    s =(char *)realloc(s,(i+1)*sizeof(char));
    *(s+i) = '\0';
    return s;
}
