#include <stdio.h>
#include <stdlib.h>

int main()
{

    FILE *archivo;

    archivo = fopen("archivoleer.txt","r");

    if (archivo == NULL){
        printf("Archivo no encontrado\n");
    }else{
    fgets("asd",99,archivo)
    }


    fclose(archivo);
    return 0;
}
