#include <stdio.h>
#define MAX 100

int CalcularLongitud(char cadena[]);

void main()
{
 char S[MAX];

 printf("escribe: ");
 fgets(S,MAX, stdin);

 printf("\nla cadena tiene una logintud de: %d\n", CalcularLongitud(S));
}

int CalcularLongitud(char cadena[])
{
 int i = 0;
 int n = 0;
 while(cadena [i] != '\0')
    {
     n++;
     i++;
    }
 return n;
}
