#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 100

int main()
{
    char s1[MAX], s2[MAX], s3[MAX];

    printf("Digite un texto 1: ");
    gets(s1);

    printf("Digite un texto 2: ");
    gets(s2);

    printf("Digite un texto 3: ");
    gets(s3);

    if(strncmp(s1,s2,3)==0)
        printf("Son iguales\n");
    else
        printf("\nSon diferentes\n");

    if(strncmp(s1+2,s2+2,3)==0)
        printf("Son iguales\n");
    else
        printf("\nSon diferentes\n");

    system("PAUSE");
    return 0;
}

