#include<stdio.h>
#include<stdlib.h>
#define MAX 100

int main()
{
    char s[MAX];

    printf("Digite un texto: ");
    gets(s);

    printf("El texto es \"%s\"\n",s);
    puts(s);

    system("PAUSE");
    return 0;
}
