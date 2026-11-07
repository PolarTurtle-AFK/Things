#include<stdio.h>
#include<stdlib.h>
#define MAX 50

int main()
{
    FILE *archivo;
    char texto[MAX];

    archivo = fopen("ejemplo.txt","r");
    if(archivo==NULL)
    {
        printf("\nError\nNo se encuentra el archivo.\n");
        fclose(archivo);
        archivo = fopen("ejemplo.txt","w");
        if(archivo!=NULL)
            printf("\nArchivo creado\n");
    }
    else
    {
        fclose(archivo);
        archivo = fopen("ejemplo.txt","a+");
        if(archivo!=NULL)
        {
            printf("Digite un texto a salvar: ");
            gets(texto);

            fputs(texto,archivo);
        }
        fclose(archivo);
    }


    system("PAUSE");
    return 0;
}
