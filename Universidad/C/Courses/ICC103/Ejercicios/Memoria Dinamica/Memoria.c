#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    /* Funcion free(*puntero)
    free(*puntero)  */
    //ejemplo:
    int *ad;
    ad = (int *)malloc(sizeof(int));
    char *abc;
    abc = (char *)malloc(sizeof(char));
    //liberar:
    free(ad);
    free(abc);

    /* Funcion Malloc (Parametro)
    tipo *puntero;
    puntero = (tipo *)malloc(numero de bytes)   */

    char cad[121], *ptr;
    int longitud;

    puts("\nIntroduce una linea de texto: ");
    gets(cad);

    longitud=strlen(cad);
    ptr=(char*)malloc((longitud+1)*sizeof(char));

    strcpy(ptr,cad);
    printf("ptr = %s \n\n", ptr);
    free(ptr);

    system("PAUSE");

    /* Funcion Calloc (Parametro)
    tipo *puntero;
    puntero = (tipo*)calloc(#elementos,tamaño de cada elemento en bytes)    */

    char *c, B[121];
    puts("\nIntroduce linea de caracteres");
    gets(B);
    c=(char*)calloc(strlen(B)+1,sizeof(char)); //+1 para el '\0'
    strcpy(c,B);

    /* Funcion realloc (Parametro)
    tipo *puntero;
    puntero = (tipo*)realloc(puntero a bloque, tamaño de nuevo bloque expresado en bytes)   */

    char *cadena;
    int tam;
    tam = (strlen("Primavera")+1)*sizeof(char);
    cadena=(char*)malloc(tam);
    strcpy(cadena,"Primavera");

    /*Ampliar*/
    tam += (strlen(" en Constanza \n")+1) * sizeof(char);
    cadena = (char*)realloc(cadena,tam);
    strcat(cadena," en Constanza \n");
    puts(cadena);
    free(cadena);

    system("PAUSE");



    return 0;
}
