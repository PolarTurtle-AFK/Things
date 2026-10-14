#include <stdio.h>

float CalcularPromedio(int a, int b, int c);

void main()
{
 int a, b, c;

 printf("ingresa tu primer numero: \n");
 scanf("%d", &a);

 printf("ingresa tu segundo numero: \n");
 scanf("%d", &b);

 printf("ingresa tu tercer numero: \n");
 scanf("%d", &c);

 printf("el promedio es: %.2f", CalcularPromedio(a, b, c));
}

float CalcularPromedio(int a, int b, int c)
{
    return (float)(a+b+c)/3;
}
