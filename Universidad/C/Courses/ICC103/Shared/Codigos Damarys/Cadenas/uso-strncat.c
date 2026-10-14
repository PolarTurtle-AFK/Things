#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 100

int main()
{
    char s1[MAX], s2[MAX], s3[MAX];

    printf("Digite un texto 1: ");
    gets(s1);
    //fgets(s1,MAX,stdin);

    printf("Digite un texto 2: ");
    gets(s2);
    //fgets(s2,MAX,stdin);

    printf("Digite un texto 3: ");
    gets(s3);

    printf("\nCantidad de caracteres %d\n",strlen(s1));

    puts(s1);
    puts(s2);
    puts(s3);
    strncat(s2,s1,5);

    printf("\nLuego del STRNCAT\n");

    puts(s1);
    puts(s2);
    puts(s3);
    strncat(s3,s1+3,5);

    printf("\nLuego del STRNCAT\n");

    puts(s1);
    puts(s2);
    puts(s3);

    system("PAUSE");
    return 0;
}

