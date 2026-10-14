#include<stdio.h>
#include<stdlib.h>

void print_adyacentes(int, int []);

int main()
{
    int n;

    printf("Digite cantidad de elementos: ");
    scanf("%d",&n);

    int numeros[n], i;

    for(i=0;i<n;i++)
    {
        printf("Digite valor [%d]: ",i);
        scanf("%d",&numeros[i]);
    }

    print_adyacentes(n,numeros); //&numeros[0]
    system("PAUSE");
    return 0;

}
/*
Función: print_adyacentes
Objetivo: Imprimir grupos de 3 adyacentes, ej: 4,5,6, 7,8,9, etc
NO RETORNA

4 5 6 7 9 10 11 14
0 1 2 3 4  5  6  7
n=8

*/
void print_adyacentes(int n, int numeros[n])
{
    int i;
    for(i=0;i<n;i++)
    {
        if(numeros[i]==numeros[i+1]-1 && numeros[i]==numeros[i+2]-2)
            printf("%d, %d, %d\n",numeros[i],numeros[i+1],numeros[i+2]);

        if(numeros[i]+1==numeros[i+1] && numeros[i]+2 == numeros[i+2])
            printf("%d, %d, %d\n",numeros[i],numeros[i+1],numeros[i+2]);
    }
}
