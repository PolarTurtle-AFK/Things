#include <stdio.h>
#define MAX 50

int Palindromo(char cadena[]);

void main()
{
 char S[MAX];
 printf("escribe: ");
 fgets(S, MAX, stdin);

 int j = 0;
 while(S[j] != '\0')
    {
     if(S[j] == '\n')
        {
         S[j] = '\0';
         break;
        }
     j++;
    }

 if(Palindromo(S))
    {
     printf("\nEs palindromo\n");
    }
    else
    {
     printf("\nNo es palindromo\n");
    }
}

int Palindromo(char cadena[])
{
 int n = 0;
 int i = 0;
 while(cadena[i] != '\0')
    {
     n++;
     i++;
    }
 i = 0;
 n -= 1;
 for(i; i<n;i++,n--)
    {
     if(cadena[i] != cadena[n])
        {
         return 0;
        }
    }
 return 1;
}
