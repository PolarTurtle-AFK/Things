#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int postring(char *, char *);

int main()
{
    char s[]="manana sera bonito", p[]="la";
    int res=postring(s,p);

    if(res>=0)
        printf("\nTexto encontrado en posicion %d\n",res);
    else
        printf("\nTexto no encontrado\n");

    system("PAUSE");
    return 0;

}
int postring(char *s, char *p)
{
    int i, sizep=strlen(p);

    for(i=0; *(s+i)!='\0'; i++)
    {
        if(strnicmp(s+i,p,sizep)==0)
            return i;
    }
    return -1;
}
 