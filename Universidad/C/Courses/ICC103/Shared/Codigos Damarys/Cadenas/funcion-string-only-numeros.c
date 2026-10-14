/*
Realice una función que determine si una cadana de caracteres
sólo contiene caracteres numéricos.
*/
#include<stdio.h>
#include<stdlib.h>
#define MAX 100

int only_numeros(char *);

int main()
{
    char s[MAX];

    printf("Digite un texto: ");
    gets(s);

    if(only_numeros(s)>0)
        printf("\nEl texto solo contiene numeros\n");
    else
        printf("\nEl texto contiene otros caracteres\n");

    system("PAUSE");
    return 0;
}
/*
Función: only_numeros
Objetivo: recibe un puntero o cadena y determina si solo contiene
caracteres numéricos
Retorna 1 si es así, 0 si no
Ej:
"Hola 123" --> retornar 0
"12333434" --> retornar 1

*/
int only_numeros(char *s)
{
    int i;
    for(i=0;*(s+i)!='\0';i++) //for(i=0;*(s+i);i++)
    {
        printf("%c\n",*(s+i));
        if(*(s+i)<'0' || *(s+i)>'9')
            return 0; //desde que encuentra un caracter no numérico, salir

        /*int cont=0;
        if(*(s+i)>='0' && *(s+i)<='9')
            cont++;

        */
    }
    return 1; //Solo contiene caracteres numéricos

    //Si usamos la otra variante
    /*if(cont==strlen(s)
         return 1;
    */
}
