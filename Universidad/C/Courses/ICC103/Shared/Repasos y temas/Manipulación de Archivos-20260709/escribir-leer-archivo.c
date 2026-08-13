/*
Fundamentos
Ejemplo de uso de funciones de archivo:

*/
#include <stdio.h>
#include <stdlib.h>
typedef struct
{
    char nombre[20];
    char apellido[20];
    char telefono[15];
    char email[50];
} PERSONA;

void mi_fflush();

int main()
{
    PERSONA *p;
    p = (PERSONA *)malloc(sizeof(PERSONA));
    // p = (PERSONA *)calloc(1,sizeof(PERSONA));
    char *nom="prueba2.dat";
    FILE *pp;
    if ((pp=fopen(nom,"a+b")) == NULL)
    {
        puts("\n Error abriendo archivo");
        return 0;
    }

    printf("Digite Nombre: ");
    gets(p->nombre);
    printf("Digite Apellido: ");
    gets(p->apellido);
    printf("Digite Telefono: ");
    gets(p->telefono);
    printf("Digite Email: ");
    gets(p->email);


    //escribir los datos almacenados en la estructura p en el archivo
    fwrite(p,sizeof(PERSONA),1,pp);

    fclose(pp);

    int cont=0;
    //se abre nuevamente el archivo solo modo lectura
    if ((pp=fopen(nom,"rb")) == NULL)
    {
        puts("\n Error abriendo archivo");
        return 0;
    }
    else
    {
        system("CLS");
        printf("\nCLIENTE REGISTRADOS\n");
        //mientras no llegue a fin del archivo
        //procedemos a leer

        printf("\nNo.\tNombre\t\tApellido\t\tTelefono\tEmail\n");
        while (!feof(pp))
        {
            //leer archivo
            if (fread(p,sizeof(PERSONA),1,pp)) //leer el archivo
            {
                cont++;
               /* printf("Cliente %d:\n",cont);
                printf( "Nombre: %s\n", p->nombre ); //imprimir los datos almacenados en el archivo
                printf( "Apellido: %s\n", p->apellido);
                printf( "Tel%cfono: %s\n",130, p->telefono);
                printf( "Email: %s\n", p->email);*/

                printf("%d\t%s\t\t%s\t\t%s\t%s\n",cont,p->nombre,p->apellido,p->telefono,p->telefono);
            }
        }
        fclose(pp);
    }

    system("pause");
    return 0;
}
//Funcion: mi_fflush
//Limpiar el buffer
void mi_fflush()
{
    int c;
    while((c=getchar())!='\n' && c!=EOF)
    {
    }
}


