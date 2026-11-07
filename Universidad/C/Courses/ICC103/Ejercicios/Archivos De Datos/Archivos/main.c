#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define NULL 0


/*
int main()
{
    FILE *arch;
    char nombarch[] = "datos.txt", *s;

    s=(char*)malloc(20*sizeof(char));

    arch=fopen(nombarch,"r");
    if (arch == NULL){
        printf("\nError: No se pudo abrir el archivo");
    }else
    {
        printf("sixseven");
        //fputs("SixSeven",arch);
        fgets(s,20,arch);
        printf("\nTexto: %s\nLongitud: %d\n",s,strlen(s));
        fclose(arch);
    }
    return 0;
}
*/

#define MAX 121
#define MIN 30

int main(){
    FILE *arch1, *arch2;
    char *s;
    s=(char*)calloc(MAX,sizeof(char));

    arch1 = fopen("entrada.txt", "r");
    arch2 = fopen("salida.txt","a+");

    if(arch1==NULL || arch2==NULL){
        printf("No hay archivos");
    }else{
        while(fgets(s,MAX,arch1)){
            if(strlen(s)>MIN){
                fputs(s,arch2);
            }else{
                printf("\n%s",s);
            }
        }
    }
}


