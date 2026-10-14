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

    printf("\nANTES DEL STRNCPY\n");
    puts(s1);
    puts(s2);
    puts(s3);

    strncpy(s1,s2,10);

    printf("\nLUEGO DEL STRNCPY\n");
    puts(s1);
    puts(s2);
    puts(s3);

    /*
        strncpy(s3,s2+4,5);

        printf("\nLUEGO DEL 2do STRCPY\n");
        puts(s1);
        puts(s2);
        puts(s3);

        */
    strncpy(s3+3,s2+4,5);

    printf("\nLUEGO DEL 2do STRNCPY\n");
    puts(s1);
    puts(s2);
    puts(s3);

    system("PAUSE");
    return 0;
}
