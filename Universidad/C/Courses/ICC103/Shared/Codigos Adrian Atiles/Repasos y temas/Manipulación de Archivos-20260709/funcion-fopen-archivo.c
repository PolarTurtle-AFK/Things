#include<stdio.h>
#include<stdlib.h>

int main()
{
    FILE *archivo;

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
        printf("\nEl archivo existe\n");
        //archivo = fopen("ejemplo.txt","w"); aun si el archivo existe
        //esto lo crea nuevamente y se pierden los datos salvados
    }
    fclose(archivo);

    system("PAUSE");
    return 0;
}
