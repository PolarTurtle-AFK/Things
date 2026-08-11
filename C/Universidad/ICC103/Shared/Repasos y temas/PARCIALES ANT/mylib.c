#include "ADLIB.h"

float CalcularPromedio3(int a, int b, int c)
{
    return (float)(a+b+c)/3;
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

int EncontrarElMayor(int arr[10])
{
 int i = 0;
 int mayor = arr[i];
 for(i; i < 10; i++)
    {
     if(arr[i] > mayor)
        {
         mayor = arr[i];
        }
    }
 return mayor;
}

int EncontrarElMenor(int arr[10])
{
 int i = 0;
 int menor = arr[i];
 for(i; i < 10; i++)
    {
     if(arr[i] < menor)
        {
         menor = arr[i];
        }
    }
 return menor;
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
