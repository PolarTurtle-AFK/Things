#include <stdio.h>
#define MAX 100

int ContieneCaracter(char cadena[], char c);

void main()
{
 char S[MAX], caracter;
 printf("escribe: ");
 fgets(S,MAX, stdin);

 printf("\nescribe el caracter a buscar: ");
 scanf("%c", &caracter);


 if(ContieneCaracter(S, caracter))
    {
     printf("\ncontiene a: %c\n", caracter);
    }
    else
    {
     printf("\nno contiene el caracter  : %c\n", caracter);
    }
}

int ContieneCaracter(char cadena[], char c)
{
 int i = 0;
 while(cadena[i] != '\0')
    {
     if(cadena[i] == c)
        {
         return 1;
        }
        i++;
    }
 return 0;
}
