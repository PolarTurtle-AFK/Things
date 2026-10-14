#include<stdio.h>
#include<stdlib.h>

int main()
{
    FILE *archivo1, archivo2;
    char *texto;

    texto = (char *)calloc(20,sizeof(char));

    archivo1=fopen("ejemplo.txt","r");
    if(archivo1 == NULL)
        printf("\nEl archivo no se pudo abrir\n");
    else
    {
        printf("\nArchivo existe\n");
        fgets(texto,20,archivo1);
        puts(texto);
    }

    fclose(archivo1);
    free(texto);
    system("PAUSE");
    return 0;
}
