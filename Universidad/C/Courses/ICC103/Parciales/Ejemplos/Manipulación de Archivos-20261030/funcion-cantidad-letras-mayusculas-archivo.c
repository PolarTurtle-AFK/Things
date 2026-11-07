#include <stdio.h>
#include <stdlib.h>

//funciones
int cantidad_letras_mayusculas(char *nom_arch);

int main()
{
//Nombre de archivo
    char *nomArch = "mayusculas.txt";

    int cantMayus = cantidad_letras_mayusculas(nomArch);

    printf("Cantidad de mayusculas: %d\n", cantMayus);

    return 0;

}

/*
Nombre: cantidad_letras_mayusculas
Objetivo: contar la cantidad de letras mayusculas en un archivo de texto
Retorna cantMayus (Cantidad de letras mayusculas)
*/
int cantidad_letras_mayusculas(char *nom_arch)
{

    int cantMayus=0;
    FILE *archivo;
    char c;

    //validar creacion de archivo
    if((archivo=fopen(nom_arch, "r"))==NULL)
    {
        printf("Archivo no existe, creado ahora\n");
        archivo = fopen(nom_arch, "w");
        return 0;
    }

    fclose(archivo);
    archivo = fopen(nom_arch, "r");

    //contar cantidad de mayusculas en el archivo de texto
    while((c=getc(archivo))!=EOF)
    {
        if(c >= 'A' && c <= 'Z')
        {
            cantMayus++;
        }
    }

    fclose(archivo);
    return cantMayus;

}
