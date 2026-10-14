#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 100

int main()
{
    char s1[MAX], s2[MAX];

    printf("Digite un texto 1: ");
    gets(s1);
    //fgets(s1,MAX,stdin);

    printf("Digite un texto 2: ");
    gets(s2);

    printf("ANTES DEL STRCAT\n");
    puts(s1);
    puts(s2);

    strcat(s1,s2); //unir al final de s1 el texto de s2
    //strcat(s2,"probando");

    printf("LUEGO DEL STRCAT\n");
    puts(s1);
    puts(s2);

    system("PAUSE");
    return 0;
}
