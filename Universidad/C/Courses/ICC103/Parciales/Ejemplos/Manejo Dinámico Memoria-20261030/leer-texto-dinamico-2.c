#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char* mi_gets();

int main()
{
    char *s, *c;
    int i=0;

    printf("Digite texto: ");
    s = mi_gets();
    puts(s);

    printf("Digite otro texto: ");
    c = mi_gets();
    puts(c);

    printf("\nEl texto tiene %d caracteres\n",strlen(c));

    if(strcmp(s,c)==0)
        printf("\nAmbos textos son iguales\n");

    free(s);
    free(c);

    system("PAUSE");
    return 0;
}
char* mi_gets()
{
    char c, *s;

    int i=0;
    while((c=getchar())!='\n')
    {
        if(i==0)
            s=(char *)calloc(i+1,sizeof(char));
        else
            s=(char *)realloc(s,(i+1)*sizeof(char));

        *(s+i)=c;
        i++;
    }
    s=(char *)realloc(s,(i+1)*sizeof(char));
    *(s+i)='\0';

    return s;
}
