#include<stdio.h>
#include<stdlib.h>
#define MAX 50

int main()
{
    char s[MAX], *ps;

    printf("Digite un texto: ");
    gets(s);

    printf("\"%s\"\n",s);
    puts(s);

    ps = s; //&s[0]
    while(*ps!='\0')
    {
        printf("%c",*ps);
        ps++;
    }
    int i;
    printf("\n");
    for(i=0;*(s+i);i++)//for(i=0;*(s+i)!='\0';i++)
        printf("%c",*(s+i));

    system("PAUSE");
    return 0;
}
