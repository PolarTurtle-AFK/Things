#include<stdio.h>
#include<stdlib.h>
char* leer_texto();

int main()
{
    char c, *texto;
    int cont=0;

    printf("Digite texto: ");
    texto=leer_texto();
    puts(texto);


    free(texto);
    system("PAUSE");
    return 0;
}

char* leer_texto()
{
    char c, *texto;
    int contador = 0;
    while((c=getchar()) != '\n')
    {
        if(contador == 0)
            texto = (char *)malloc(sizeof(char));
        else
            texto = (char *)realloc(texto,contador+1*sizeof(char));

        *(texto+contador) = c;
        contador++;
    }
    *(texto+contador) = '\0';

    return texto;
}
