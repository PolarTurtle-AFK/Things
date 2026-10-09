/*Haga  una  función   elimpal(s,n)  de  manera  que  elimine  la  
n-ésima palagra del string  s. 
Por ejemplo, si s = “El lobo feroz”, elimpal(s,2) hace que 
el valor de s sea “El feroz”.*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void elimpal(char *, int);

int main()
{
    char s[]="El lobo feroz";
    printf("\nAntes: ");
    puts(s);
    elimpal(s,2);
    printf("Despues: ");
    puts(s);
    system("PAUSE");
    return 0;

}

void elimpal(char *s, int n){
     
}