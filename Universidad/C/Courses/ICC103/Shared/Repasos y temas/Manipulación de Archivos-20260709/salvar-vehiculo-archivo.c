#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char marca[20];
    int anio;
    float precio;
} Vehiculo;

Vehiculo* registrar_vehiculos(int);
void mostrar_vehiculos();

int main()
{
    Vehiculo *autos;
    int n, anio;
    float precio;
    char marca[20];

    printf("Cantidad de vehiculos: ");
    scanf("%d", &n);
    fflush(stdin);

    autos = registrar_vehiculos(n);

    mostrar_vehiculos();

    free(autos);
    system("pause");
    return 0;
}

Vehiculo* registrar_vehiculos(int n)
{
    Vehiculo *v;
    int i;

    v = (Vehiculo*) malloc(n * sizeof(Vehiculo));

    FILE *file_vehiculo_bin, *file_vehiculo_txt;

    if ((file_vehiculo_bin=fopen("Vehiculos.dat","a+b"))==NULL)
    {
        puts("Error abriendo archivo");
        return 0;
    }
    if ((file_vehiculo_txt=fopen("Vehiculos.txt","a+"))==NULL)
    {
        puts("Error abriendo archivo");
        return 0;
    }

    for(i = 0; i < n; i++)
    {
        printf("\nVehiculo #%d\n", i + 1);
        printf("Marca: ");
        fflush(stdin);
        gets((v + i)->marca);
        printf("A%co: ",164);
        scanf("%d", &((v + i)->anio));
        printf("Precio: ");
        scanf("%f", &((v + i)->precio));
        fflush(stdin);

        //salvar en archivo
        fwrite((v+i),sizeof(Vehiculo),1,file_vehiculo_bin);
        fwrite((v+i),sizeof(Vehiculo),1,file_vehiculo_txt);
    }
    fclose(file_vehiculo_bin);
    fclose(file_vehiculo_txt);
    return v;
}
void mostrar_vehiculos()
{
    FILE *file_vehiculo_bin;
    Vehiculo v;

    //Validar si hay error al abrir el archivo en modo lectura
    if ((file_vehiculo_bin=fopen("Vehiculos.dat","rb"))==NULL)
    {
        puts("Error abriendo archivo");
        return;
    }
    else
    {

        printf("\nMarca\tA%co\tPrecio\n",164);

        while(!feof(file_vehiculo_bin))
        {
            /*
            if(fread(&v,sizeof(Vehiculo),1,file_vehiculo_bin))
                printf("\nMarca: %s\tA%co: %d\tPrecio: %.2f\n",v.marca
                                                              ,164
                                                              ,v.anio
                                                              ,v.precio);

            */
            if(fread(&v,sizeof(Vehiculo),1,file_vehiculo_bin))
                printf("\n%s\t%d\t%.2f\n",v.marca
                                         ,v.anio
                                         ,v.precio);
        }
    }
    fclose(file_vehiculo_bin);
}

