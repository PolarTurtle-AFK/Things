/*
2. Memoria dinámica: cadena
Un editor de texto necesita normalizar frases. Realice una función char *normalizar(char *frase) que retorne una nueva cadena donde:

se eliminan los espacios al inicio y al final,
varios espacios seguidos quedan como uno solo,
la primera letra de cada palabra queda en mayúscula y las demás en minúscula.

La memoria debe ajustarse al tamaño exacto y la frase original no se modifica. 
Si la frase solo tiene espacios o está vacía, retorna una cadena vacía (no NULL).

Original:   "   hOLA    mUNDO  cruel "   Normalizada: "Hola Mundo Cruel"
Original:   "ya"                          Normalizada: "Ya"
Original:   "      "                      Normalizada: ""
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *normalizar(char *frase);

int main(){

    char *frase;
    frase = (char *)malloc(50*sizeof(char));
    strcpy(frase," HOLA  MUNDO ");
    char *palabra = normalizar(frase);
    printf("%s",palabra);
    free(palabra);
    free(frase);
    return 0;
}

char *normalizar(char *frase){

    int longitud = strlen(frase);
    char *resultado = malloc((longitud+1)*sizeof(char));

    if (resultado == NULL){
        return NULL;
    }

    strcpy(resultado,frase);

    for(int i = 0; *(resultado+i)!= '\0'; i++){
        if ((*(resultado+i) == ' ' && i==0) ||
            (*(resultado+i) == ' ' && *(resultado+i+1) == ' ') ||
            (*(resultado+i) == ' ' && *(resultado+i+1) == '\0')){
            strcpy(resultado+i,resultado+i+1);
            i--;
        }      
    }

   

    char *temp = realloc(resultado, (strlen(resultado)+1) * sizeof(char));
    if (temp != NULL){
        resultado = temp;
    }
    return resultado;
}