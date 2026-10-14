#include<stdio.h>
#include<stdlib.h>

int factorial(int);
int factorial_rec(int);

int main()
{
    int n;

    printf("Digite un n%cmero: ",163);
    scanf("%d",&n);

    printf("%d! = %d\n\n",n,factorial(n));
    printf("%d! = %d\n\n",n,factorial_rec(n));

    system("PAUSE");
    return 0;
}
//1 * 2 * 3 * 4 * 5

int factorial(int n)
{
    int fact=1;

    while(n!=1) //for(i=1 ; i<=n; i++)
    {
        fact*=n; //fact = fact *n;
        n--;
    }
    return fact;
}
int factorial_rec(int n)
{
    if(n<=1)
        return 1; //Termina acá la interacción recursiva

    return n * factorial_rec(n-1);
}
