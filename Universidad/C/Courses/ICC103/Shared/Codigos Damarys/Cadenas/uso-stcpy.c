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

    puts(s1);
    puts(s2);
    puts(s3);
    strcpy(s1,s2);

    printf("\nLuego del STRCPY\n");
    puts(s1);
    puts(s2);
    puts(s3);

    strcpy(s3+5,s2+3);

    printf("\nLuego del STRCPY\n");
    puts(s1);
    puts(s2);
    puts(s3);

    system("PAUSE");
    return 0;
}

