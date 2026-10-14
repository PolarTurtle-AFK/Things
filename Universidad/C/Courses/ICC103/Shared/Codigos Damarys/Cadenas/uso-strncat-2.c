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

    printf("\nANTES DEL STRNCAT\n");
    puts(s1);
    puts(s2);
    puts(s3);

    strncat(s1,s2,5); //se une al final de s1 5 caracteres de s2

    printf("\nLUEGO DEL STRNCAT\n");
    puts(s1);
    puts(s2);
    puts(s3);

    strncat(s3,s2+4,2);

    printf("\nLUEGO DEL 2do STRNCAT\n");
    puts(s1);
    puts(s2);
    puts(s3);


    system("PAUSE");
    return 0;
}
