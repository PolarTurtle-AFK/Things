#include <stdio.h>
#define MAX 100

int ContarEspacios(char cadena[]);

void main()
{
 char S[MAX], caracter;
 printf("escribe: ");
 fgets(S,MAX, stdin);

 printf("\ntiene %d espacios\n", ContarEspacios(S));
}

int ContarEspacios(char cadena[])
{
 int i = 0;
 int c = 0;
 while(cadena[i] != '\0')
    {
     if(cadena[i] == ' ')
        {
         c++;
        }
     i++;
    }
 return c;
}
