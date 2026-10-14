#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 100

int main()
{
    char s[MAX];

    printf("Digite un texto: ");
    gets(s);
    //fgets(s,MAX,stdin);

    /*
    int tam;
    tam = strlen(s);
    */

    printf("\nEl texto tiene %d caracteres\n",strlen(s));
    system("PAUSE");
    return 0;
}
