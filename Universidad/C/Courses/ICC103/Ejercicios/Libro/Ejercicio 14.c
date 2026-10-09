/*Haga una función  strder(s,t), la cual retorne la posición 
de  la  ocurrencia  de   t  en   s  que  esté  más  a  la  derecha.    Por  
ejemplo, si s = “Las ballenas asesinas” y t = “na”, en este caso 
la función retorna 18*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int strder(char *, char *);

int main()
{
    char s[]="las ballenas asesinas mana", p[]="na";
    int res=strder(s,p);

    if(res>=0)
        printf("\nTexto encontrado en posicion %d\n",res);
    else
        printf("\nTexto no encontrado\n");

    system("PAUSE");
    return 0;

}
int strder(char *s, char *p)
{
    int i, sizep=strlen(p);
    int der=-1;

    for(i=0; *(s+i)!='\0'; i++)
    {
        if(strnicmp(s+i,p,sizep)==0)
            der=i;
            
    }
    return der;
}
 