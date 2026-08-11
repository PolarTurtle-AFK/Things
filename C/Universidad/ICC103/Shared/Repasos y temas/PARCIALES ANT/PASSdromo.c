#include <stdio.h>
#define MAX 50

//funciones
float CalcularPromedio3(int a, int b, int c);
int ContieneCaracter(char cadena[], char c);
int CalcularLongitud(char cadena[]);
int EncontrarElMayor(int arr[10]);
int EncontrarElMenor(int arr[10]);
int ContarEspacios(char cadena[]);
int Palindromo(char cadena[]);

void main()
{
 char S[MAX];
 fprintf(stdout, "escribe una cadena: ");
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

 fprintf(stdout, "\n--- RESULTADOS ---\n");

 fprintf(stdout, "Longitud:          %d\n", CalcularLongitud(S));

 fprintf(stdout, "Espacios:          %d\n", ContarEspacios(S));

 fprintf(stdout, "Contiene '*':      %s\n",ContieneCaracter(S, '*') ? "Si" : "No");

 fprintf(stdout, "Es palindromo:     %s\n", Palindromo(S) ? "Si" : "No");
}

//contenido
float CalcularPromedio3(int a, int b, int c) { return (float)(a+b+c)/3; }
int ContieneCaracter(char cadena[], char c) { int i=0; while(cadena[i]!='\0'){ if(cadena[i]==c) return 1; i++;} return 0; }
int CalcularLongitud(char cadena[]) { int i=0,n=0; while(cadena[i]!='\0'){n++;i++;} return n; }
int EncontrarElMayor(int arr[10]) { int mayor=arr[0]; for(int i=1;i<10;i++) if(arr[i]>mayor) mayor=arr[i]; return mayor; }
int EncontrarElMenor(int arr[10]) { int menor=arr[0]; for(int i=1;i<10;i++) if(arr[i]<menor) menor=arr[i]; return menor; }
int ContarEspacios(char cadena[]) { int i=0,c=0; while(cadena[i]!='\0'){ if(cadena[i]==' ') c++; i++;} return c; }
int Palindromo(char cadena[]){ int n = 0; int i = 0; while(cadena[i] != '\0'){n++; i++;} i = 0; n -= 1; for(i; i<n;i++,n--){if(cadena[i] != cadena[n]){return 0;}} return 1;}
