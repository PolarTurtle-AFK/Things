#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int subcadena_comun (char *a, char *b, int posicion);

int main(){

    char texto1[10]="eleven";
    char texto2[10]="seven";
    int posicion=0;

    int res = subcadena_comun(texto1,texto2,posicion);
    return 0;
}

int subcadena_comun (char *a, char *b, int posicion){
    char *p=a;
    int contaconta=-1;
    int contador=0;
    while(a!='\0'){
        if (strncmp(a,b,strlen(b))==0){
            contador=strlen(b);
            printf("!");
            return 1;
        }else
        if (contador>contaconta){
            contaconta=contador;
        }
        a++;
    }
    printf("%d",contaconta);

    printf("asd");
    return 0;

}








