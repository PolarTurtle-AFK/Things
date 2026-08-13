#include<stdio.h>
#include<stdlib.h>

int main()
{
    char c, *s;
    int i=0;

    printf("Digite texto: ");
    while((c=getchar())!='\n')
    {
        if(i==0)
            s = (char *)malloc(sizeof(char));
        else
            s = (char *)realloc(s,(i+1)*sizeof(char));

        *(s+i)=c;
        i++;
    }
    s = (char *)realloc(s,(i+1)*sizeof(char)); //espacio en memoria para el '\0'
    *(s+i)='\0'; //cerrar la cadena, toda cadena en el caracter nulo '\0'

    puts(s);
    free(s);
    system("PAUSE");
    return 0;
}
