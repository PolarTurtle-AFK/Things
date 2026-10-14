#include<stdio.h>
#include<stdlib.h>

char *llenar_cadena();

int main()
{
    int i=0;
    char c, *s;

    printf("Digite texto: ");
    while((c=getchar())!='\n')
    {
        if(i==0)
            s=(char *)calloc(1,sizeof(char)); //s=(char *)malloc(sizeof(char));
        else
            s=(char *)realloc(s,(i+1)*sizeof(char));

        *(s+i) = c;
        i++;
    };
    s=(char *)realloc(s,(i+1)*sizeof(char));
    *(s+i) ='\0';

    puts(s);

    char *s2;

    s2= llenar_cadena();

    puts(s2);

    free(s);
    free(s2);
    system("PAUSE");
    return 0;
}
char *llenar_cadena()
{
    int i=0;
    char c, *s;
    printf("Digite texto: ");
    while((c=getchar())!='\n')
    {
        if(i==0)
            s=(char *)calloc(1,sizeof(char)); //s=(char *)malloc(sizeof(char));
        else
            s=(char *)realloc(s,(i+1)*sizeof(char));

        *(s+i) = c;
        i++;
    };
    s=(char *)realloc(s,(i+1)*sizeof(char));
    *(s+i) ='\0';

    return s;
}

