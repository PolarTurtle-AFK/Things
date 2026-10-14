/*
Haga una función contarc(s,c), de manera que retorne
cuántas veces se repite el caracter c en el string s.
La función estaría declarada de la siguiente manera:
int contar(s,c)
char s[], c;
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 100

int contarc(char *, char);

int main()
{
    char s[]="anita lava la tina", c='a';
    /*
    char s[MAX], c;

    printf("Digite un texto: ");
    gets(s);

    printf("Digite caracter a contar: ");
    scanf("%c",&c);*/
    int retorno = contarc(s,c);

    if(retorno>0)
        printf("\n%c est%c en %s %d veces\n",c,160,s,retorno);
    else
        printf("\n%c NO est%c en %s\n",c,160,s);

    system("PAUSE");
    return 0;
}
/*
Función: contarc
Objetivo: Recibe un texto en s y un caracter en c y cuenta cuántas veces está c en s
Retorna cantidad de veces encontrada el caracter en c en s
*/

int contarc(char *s, char c)
{
    int i, cont=0;
    for(i=0; *(s+i); i++) //for(i=0; *(s+i)!='\0'; i++)
    {
        if(*(s+i)== c)
            cont++;
    }
    return cont;
    /*int i = 0;
    while(*(s+i))
    {
        if(*(s+i)== c)
            cont++;

        i++;
    }*/
}
