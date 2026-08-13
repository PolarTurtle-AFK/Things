#include <string.h>
#include <stdio.h>
#include <stdlib.h>

void clear(char *);
void existe(char *, char *);
int palabraLinea(FILE *, char *);
int comienzaCon(char *, char *);
void print_Factores_Primos_Rec(int, int);
int main()
{
    char s[]="1E2L3i4a5n";
    clear(s);
    puts(s);
    char s1[]= "HOLA COMO ESTAN";
    char s2[]="COMO";
    existe(s1,s2);

    FILE *arch = fopen("txt.txt","w");
    if(arch == NULL)
    {
        printf("Error abriendo archivo");
        return -1;
    }

    fprintf(arch,"buena suerte en el parcial\n");
    fprintf(arch,"buena suerte en el parcial\n");
    fprintf(arch,"buena suerte en el parcial\n");
    fprintf(arch,"buena suerte en el parcial\n");
    fprintf(arch,"buena  en el parcial");
    fclose(arch);

    arch=fopen("txt.txt","r");
    int c = palabraLinea(arch,"suerte");
    printf("\nLa palabra se repite %d %s.",c,c == 1? "vez" : "veces");
    fclose(arch);

    return 0;
}

void clear(char *s)
{
    if(*(s)=='\0')
        return;

    if(*(s) < '0' || *(s) > '9')
    {
        strcpy(s,s+1);
        clear(s);
    }

    clear(s+1);
}

int comienzaCon(char *s1, char *s2)
{
    if (*s2 == '\0')
    {
        return 1;
    }

    if (*s1 == '\0')
    {
        return 0;
    }

    if (*s1 != *s2)
    {
        return 0;
    }

    return comienzaCon(s1 + 1, s2 + 1);
}

void existe(char *s1, char *s2)
{
    if (*s2 == '\0')
    {
        printf("\nESTA");
        return;
    }

    if (*s1 == '\0')
    {
        printf("\nNO ESTA");
        return;
    }

    if (comienzaCon(s1, s2))
    {
        printf("\nESTA");
        return;
    }

    existe(s1 + 1, s2);
}

int palabraLinea(FILE *arch, char *s)
{
    int c=0;
    char *txt;
    txt=(char *)malloc(100*sizeof(char));

    while(fgets(txt,100,arch))
    {
        if(strstr(txt,s)!= NULL)
        {
            c++;
        }
    }
    free(txt);
    return c;
}

void print_Factores_Primos_Rec (int n, int divisor)
{
        if(n==1)
        return;

    if(n%divisor==0)
    {
        if((n/divisor)% divisor != 0)
        {
            printf("%d, ",divisor);
        }
        print_Factores_Primos_Rec(n / divisor, divisor);

    }
    else
    {
        print_Factores_Primos_Rec(n,divisor+1);
    }

}

