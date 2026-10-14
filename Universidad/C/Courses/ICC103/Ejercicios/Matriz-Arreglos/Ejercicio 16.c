/*La función elimstr() está declarada como sigue: 
elimstr(st, pos, numcar) 
char st; 
int pos, numcar; 
Esta  función  debe  eliminar  en  el  string   st  tantos  caracteres  
como  lo  indique   numcar  a  partir  de  la  posición   pos.    Por  
ejemplo,  si   st  =  “La  Bilirrubina”,  entonces,  luego de ejecutar 
elimstr(st, 1,10), el contenido de st sería “Lina”.*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void elimstr(char *, int, int);

int main()
{
    char s[]="La Bilirrubina";
    printf("\nAntes: ");
    puts(s);
    elimstr(s,1,10);
    printf("Despues: ");
    puts(s);
    system("PAUSE");
    return 0;

}

void elimstr(char *str, int pos, int cant){
    strcpy(str+pos, str+pos+cant);
}
 