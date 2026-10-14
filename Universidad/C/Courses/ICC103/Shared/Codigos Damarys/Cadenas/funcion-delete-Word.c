
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void delete_Word(char *, char *);

int main(void)
{
    char cadena[]= "La casa amarilla es LA la mas linda y tambien tiene color blanco";
    char palabra[]="la";
    int numpal;


    delete_Word(cadena,palabra);
    puts(cadena);

    system("pause");
    return 0;
}

void delete_Word(char *s, char *w)
{
    int i,tamw=strlen(w),pospal=0;

    for(i=0;*(s+i)!='\0';i++)
    {
        if(*(s+i)!=' '&& (*(s+i+1)==' '|| *(s+i+1)=='\0')) //Si hay una palabra
        {
            if(strnicmp(s+pospal,w,tamw)==0)
            {
                strcpy(s+pospal,s+i+1);
                i-=1; //por si la palabra se repite luego de la que se eliminó
            }
        }
        if(*(s+i)==' ')
            pospal=i+1;//tomo la posición siguiente para saber que desde ahi empieza la otra palabra
    }
}

