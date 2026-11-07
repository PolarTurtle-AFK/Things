#include <stdio.h>
#include <stdlib.h>

int potencia_rec(int, int);

int main()
{
    int num1, num2, mult, multrec;

    printf("Digite la base: ");
    scanf("%d",&num1);

    printf("Digite el exponente: ");
    scanf("%d",&num2);

    printf("\n%d ^ %d = %d\n",num1,num2,potencia_rec(num1,num2));

    system("PAUSE");
    return 0;
}
/*
Función: potencia_rec
Objetivo: determinar el resultado de elevar la base 'a' a la potencia 'b',
mediante multiplicación sucesivas
Devuelve el resultado  a^b.
*/
int potencia_rec(int a, int b)
{
    if(b<=0)
       return 1;

    return a * potencia_rec(a,b-1);
}
