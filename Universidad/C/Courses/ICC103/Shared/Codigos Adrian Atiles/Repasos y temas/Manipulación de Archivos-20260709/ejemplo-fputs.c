#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
    FILE *archivo2;
    char *texto;

    texto = (char *)calloc(20,sizeof(char));

    strcpy(texto,"Otra Hola mundo");

    archivo2=fopen("ejemplo2.txt","a+");
    if(archivo2 == NULL)
        printf("\nEl archivo no se pudo abrir\n");
    else
    {
        printf("\nArchivo existe\n");
        fputs(texto,archivo2);
    }

    fclose(archivo2);
    free(texto);
    system("PAUSE");
    return 0;
}
