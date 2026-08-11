#include <stdio.h>
#define MAX 50

//funciones
float CalcularPromedio3(int a, int b, int c);
int ContieneCaracter(char cadena[], char c);
int CalcularLongitud(char cadena[]);
int EncontrarElMayor(int arr[10]);
int EncontrarElMenor(int arr[10]);
int ContarEspacios(char cadena[]);

int PasswordEsValido(char clave[MAX]);

void main()
{
 char S[MAX];
 printf("escribe: ");
 fgets(S, MAX, stdin);

 if(PasswordEsValido(S))
    {
     printf("\nes valido\n");
    }
    else
    {
     printf("\nno es valido\n");
    }
}

int PasswordEsValido(char clave[MAX])
{
 if(CalcularLongitud(clave) < 8)
    {
     return 0;
    }

 if(ContarEspacios(clave) > 0)
    {
     return 0;
    }

 if(ContieneCaracter(clave, '*'))
    {
     return 0;
    }
 return 1;
}

//contenido
float CalcularPromedio3(int a, int b, int c) { return (float)(a+b+c)/3; }
int ContieneCaracter(char cadena[], char c) { int i=0; while(cadena[i]!='\0'){ if(cadena[i]==c) return 1; i++;} return 0; }
int CalcularLongitud(char cadena[]) { int i=0,n=0; while(cadena[i]!='\0'){n++;i++;} return n; }
int EncontrarElMayor(int arr[10]) { int mayor=arr[0]; for(int i=1;i<10;i++) if(arr[i]>mayor) mayor=arr[i]; return mayor; }
int EncontrarElMenor(int arr[10]) { int menor=arr[0]; for(int i=1;i<10;i++) if(arr[i]<menor) menor=arr[i]; return menor; }
int ContarEspacios(char cadena[]) { int i=0,c=0; while(cadena[i]!='\0'){ if(cadena[i]==' ') c++; i++;} return c; }
