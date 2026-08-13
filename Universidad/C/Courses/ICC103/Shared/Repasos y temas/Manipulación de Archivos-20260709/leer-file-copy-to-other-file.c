#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 100
#define MIN 30

int main()
{
    FILE *file_source, *file_dest;
    char *texto;

    texto = (char *)malloc(MAX*sizeof(char));

    file_source = fopen("source.txt","r");
    file_dest = fopen("dest.txt","a+");

    if(file_source == NULL)
    {
        printf("\nError\nNo se pudo abrir el archivo.\n");
    }
    else
    {
        //leer el contenido del source para copiarlo en el destino
        while(fgets(texto,MAX,file_source))
        {
            if(strlen(texto) > MIN)
                fputs(texto,file_dest); //mando a escribir el texto en el archivo destino

            else
                puts(texto);  //se muestra en la pantalla de la corrida

        }
    }
    rewind(file_dest);
    fputs("PROBANDO",file_dest);

    fclose(file_source);
    fclose(file_dest);
    free(texto);

    system("PAUSE");
    return 0;
}
