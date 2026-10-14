#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 100

int main()
{
    char s1[MAX], s2[MAX];

    printf("Digite un texto 1: ");
    gets(s1);

    printf("Digite un texto 2: ");
    gets(s2);

    if(strnicmp(s1,s2,4)==0)
        printf("\nAmbos textos son exactamente iguales\n");
    else
        printf("\nNo son iguales\n");
/*
    if(strnicmp(s1+2,s2+4,3)==0)
        printf("\nAmbos textos son exactamente iguales\n");
    else
        printf("\nNo son iguales\n");
*/
    system("PAUSE");
    return 0;
}
