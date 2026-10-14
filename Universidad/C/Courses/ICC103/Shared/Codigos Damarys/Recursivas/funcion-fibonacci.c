#include<stdio.h>
#include<stdlib.h>

int fibonacci(int);

int main()
{
    int n=10;

    printf("%d\n",fibonacci(n));


    system("PAUSE");
    return 0;
}
int fibonacci(int n)
{
    if(n==0)
        return 0;

    if(n==1)
        return 1;

    return fibonacci(n-1) + fibonacci(n-2);
}
