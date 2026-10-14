#include<stdio.h>
#include<stdlib.h>
#define NOM "C:\\Users\\DRE001754\\Documents\\Me\\My Classes\\prueba2.txt"
int main()
{
    char *nombre="prueba.txt";

    //FILE *archivo=fopen(NOM,"r+");
    FILE *archivo=fopen(nombre,"a+");
    if(archivo== NULL)
    {
        printf("\nNo se pudo abrir el archivo\n");
        fclose(archivo);

        //Si no se abrió modo lectura probablemente el archivo no exista
        //y entonces lo creo
        archivo=fopen(nombre,"w");
        if(archivo == NULL)
            printf("\nNo se pudo crear el archivo\n");
        else
            printf("\nEl archivo ha sido creado\n");
        fclose(archivo);
    }

    else
    {
        fputc('a',archivo);
        fputs(" Hola a todos",archivo);
        printf("\nArchivo modificado\n");
    }

    fclose(archivo);
    char *s;
    s=(char *)malloc(50*sizeof(char));
    archivo=fopen(nombre,"r");
    fgets(s,50,archivo);
    puts(s);
    system("PAUSE");
    return 0;
}
