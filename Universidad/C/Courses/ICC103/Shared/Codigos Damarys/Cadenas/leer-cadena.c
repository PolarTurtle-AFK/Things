#include<stdio.h>
#include<stdlib.h>
#define MAX 100

int main()
{
    char texto[]="Hola";
    int i;
    //texto[2]='\0';

    printf("\n%s\n",texto);

    printf("\nUsando For\n");
    for(i=0;*(texto+i);i++)
        printf("%c",*(texto+i));

    printf("\nUsando While\n");
    char *s = texto;
    while(*s!='\0')
    {

        printf("%c",*s);
        s++;
    }

    system("PAUSE");
    return 0;
}
