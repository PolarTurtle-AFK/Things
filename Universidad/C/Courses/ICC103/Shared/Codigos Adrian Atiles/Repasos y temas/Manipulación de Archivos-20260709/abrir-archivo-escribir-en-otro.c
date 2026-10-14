#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
    FILE *arch1, *arch2;
    char *texto;
    int cant=0;

    texto = (char *)malloc(100*sizeof(char));

    arch1 = fopen("archivo1.txt","r");
    arch2 = fopen("archivo2.txt","a+");

    if(arch1 == NULL || arch2 == NULL)
        printf("\nHubo un problema abriendo los archivos\n");
    else
    {
        //leer del archivo 1 y copiar en el archivo 2
        while(fgets(texto,50,arch1))
        {
            fputs(texto,arch2);
            printf("\nstrlen actual: %d\n",strlen(texto));
            cant+=strlen(texto);
        }
        float nota=95.878;

        fprintf(arch2,"\nLa calificacion obtenida es %.2f\n",nota); //imprime en el archivo2.txt
        printf("\nLa calificacion obtenida es %.2f\n",nota); //imprime en la pantalla
        fclose(arch1);
        fclose(arch2);
        printf("\nTotal de caracteres del archivo 1: %d\n\n",cant);
    }
    system("PAUSE");
    return 0;

}
