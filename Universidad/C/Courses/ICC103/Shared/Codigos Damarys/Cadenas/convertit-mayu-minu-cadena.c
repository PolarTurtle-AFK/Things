/*
Haga una función que reciba un string de parámetro y convierta a mayúsculas las letras que estén en minúsculas
 y que convierta a minúsculas las que están en mayúsculas. La función debe dejar intactos
  los números y los signos de puntuación que estén contenidos en el string.
*/
#include<stdio.h>
#include<stdlib.h>
#define MAX 100

void convertir(char *);

int main()
{
    char s[MAX];

    printf("Ingrese un texto: ");
    //gets(s);
    fgets(s,MAX,stdin);


    puts(s);

    convertir(s);
    puts(s);
    system("PAUSE");
    return 0;
}
/*
Función: convertir
Objetivo: recibe un texto y convierte las mayúsculas a minúsculas y viceversa
y deja intacto otros caracters como números, signos de puntuación etc.
NO RETORNA
'A' - 'Z' / 'a' - 'z'
65  - 90  / 97  - 122
*/
void convertir(char *s)
{
    int i;
    for(i=0;*(s+i)!='\0';i++)
    {
        //valida si es mayúscula para llevarla a minúscula
        if(*(s+i)>='A' && *(s+i)<='Z')
            *(s+i)+=32; // *(s+i) = *(s+i)+32;
        else if(*(s+i)>='a' && *(s+i)<='z')
            *(s+i)-=32;
    }
}
