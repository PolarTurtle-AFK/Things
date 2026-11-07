/*
Algoritmos Fundamentales
1.	Realizar la función recursivamente cdig_rec(), cuyo prototipo es: int cdig_rec(int n,int d).
Se desea que dicha función retorne las veces que el dígito d está contenido en el número n. 
Ej.: 
cdig(1241,1)= 2,
cdig(28858,8)=3, 
cdig(890,4) = 0.


*/
#include<stdio.h>
#include<stdlib.h>

int cdig_rec(int, int);

int main()
{
    int num, cant, numbus;
    
    printf("\nDigite un valor: ");
    scanf("%d",&num);
    
    printf("\nDigite un digito a contar: ");
    scanf("%d",&numbus);
    
    cant = cdig_rec(num, numbus);
    
    printf("\nEl %d est%c en %d, %d veces.\n",numbus,160,num,cant);
    
    system("PAUSE");
    return 0;
}

int cdig_rec(int n, int d)
{
    if(n==0)
        return 0;
    else if(d==n%10)    
        return 1 + cdig_rec(n/10,d);   
    else
        return 0 + cdig_rec(n/10,d);   
}
