#include<stdio.h>
#include<stdlib.h>
#define MAX 50

int main()
{
    FILE *archivo;
    char texto[MAX];

    archivo = fopen("ejemplo2.txt","r");
    if(archivo==NULL)
    {
        printf("\nError\nNo se encuentra el archivo.\n");
        fclose(archivo);
        archivo = fopen("ejemplo2.txt","w");
        if(archivo!=NULL)
            printf("\nArchivo creado\n");
    }
    else
    {
        fgets(texto,MAX,archivo);
        puts(texto);
    }
    fclose(archivo);

    system("PAUSE");
    return 0;
}
