#include<stdio.h>
#include<stdlib.h>
#define MAX 150
#define MIN 50

int main()
{
    char *nombre_ent="entrada.txt";
    char *nombre_sal="salida.txt";
    char *texto;


    FILE *archi_ent=fopen(nombre_ent,"r");
    FILE *archi_sal=fopen(nombre_sal,"a+"); //si no existe inicialmente
    //lo crea y agrega el texto al final, si existe simplemente agrega
    //el nuevo texto al final
    if(archi_ent == NULL || archi_sal == NULL )
        printf("\nNo se pudo abrir uno de los archivos\n");

    else
    {
        texto = (char *)calloc(MAX,sizeof(char));
        //Leo MAX cantidad de caracteres del archivo entrada
        while(fgets(texto,MAX,archi_ent))
        {
            //Si leí más del mínimo (MIN) de caracteres
            //lo muestro en pantalla
            if(strlen(texto)>MIN)
                puts(texto);

            //sino escribe en el archivo
            else
                fputs(texto,archi_sal);
        }
    }

    fclose(archi_ent);
    fclose(archi_sal);
    system("PAUSE");
    return 0;
}
