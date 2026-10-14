/*
La función elimstr() está declarada como sigue:
elimstr(st, pos, numcar)
char st;
int pos, numcar;
Esta función debe eliminar en el string st tantos caracteres
como lo indique numcar a partir de la posición pos. Por
ejemplo, si st = “La Bilirrubina”, entonces, luego de ejecutar
elimstr(st, 1,10), el contenido de st sería “Lina”.
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 100

//"Alicia", 0,2 --> ali

void elimstr(char *, int, int);

int main()
{
    char s[]="Alicia en el pais";
    int pos=9, numcar=3;
   /* char s[MAX];
    int pos, numcar;

    printf("Digite un texto: ");
    gets(s);

    printf("Digite a partir de que posici%cn desea eliminar: ",162);
    scanf("%d",&pos);

    printf("Digite cantidad de caracteres a eliminar: ",162);
    scanf("%d",&numcar);*/

    printf("\nTexto Original: \"%s\"\n",s);
    elimstr(s,pos,numcar);
    printf("\nTexto Modificado: \"%s\"\n",s);

    system("PAUSE");
    return 0;
}

void elimstr(char *s, int pos, int numcar)
{
    strcpy(s+pos,s+pos+numcar);
}
