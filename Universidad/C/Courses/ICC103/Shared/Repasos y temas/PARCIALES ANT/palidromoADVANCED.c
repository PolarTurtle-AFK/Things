#include <stdio.h>
#define MAX 50

int Palindromo(char cadena[]);

void main()
{
 char S[MAX];
 printf("escribe: ");
 fgets(S, MAX, stdin);

 for(int i = 0; S[i] != '\0'; i++)
    {
        if(S[i] == '\n')
        {
            S[i] = '\0';
            break;
        }
    }

 if(Palindromo(S))
    {
     printf("es palidromo");
    }
    else
    {
     printf("no es palindromo");
    }
}

int Palindromo(char cadena[])
{
 char temp[MAX];

 for(int i1 = 0; cadena[i1] != '\0'; i1++)
    {
     if(cadena[i1] >= 'a' && cadena[i1] <= 'z')
        {
         cadena[i1] = cadena[i1] - 32;
        }
    }

 int j = 0;
 for(int i2 = 0; cadena[i2] != '\0'; i2++)
    {
     if(cadena[i2] != ' ')
        {
         temp[j] = cadena[i2];
         j++;
        }
    }
 temp[j] = '\0';

 int n = 0;
 int i3 = 0;
 while(temp[i3] != '\0')
    {
     n++;
     i3++;
    }
 i3 = 0;
 n -= 1;
 for(i3; i3<n;i3++,n--)
    {
     if(temp[i3] != temp[n])
        {
         return 0;
        }
    }
 return 1;
}
