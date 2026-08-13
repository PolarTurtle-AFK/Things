#include<stdio.h>
#include<stdlib.h>

int main()
{
    char c, *texto;
    int cont=0;

    //esto es como un gets, que se hace dinámicamente con
    //el getchar, mientras el usuario no digita enter
    printf("Digite texto: ");
    while((c=getchar())!='\n')//while((c=getchar())!=EOF) //EOF les permite leer más de una linea
    {
        if(cont==0) //es el primer caracter a digitar por tanto usamos malloc o calloc
            texto=(char *)malloc(sizeof(char));
        else
            texto=(char *)realloc(texto,cont+1*sizeof(char));
            //acá se usa realloc para ir aumentando el tamaño del texto según
            //se digitan más caractes

        *(texto+cont)=c;
        cont++;
    }
    *(texto+cont)='\0'; //ya se completo el arreglo char o la cadena

    puts(texto);
    free(texto);

    system("PAUSE");
    return 0;
}
