#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct
{
    char ID[5];
    char nombres[30];
    char apellidos[30];
    char activo; //'A'-> Activo 'I'->Inactivo
    float sueldo;
} InfoEmp;

void crear_empleado(InfoEmp *, char *);
void informe_empleados(char *);
void modificar_empleado(InfoEmp *, char *);
void cambiar_estado_empleado(InfoEmp *, char *);

int main()
{
    int opcion;

    do
    {
        printf("\nManejo de Empleados\n\n");
        printf("1- Crear Empleado\n");
        printf("2- Informe de Empleados\n");
        printf("3- Modificar Empleado\n");
        printf("4- Activar/Desactivar Empleado\n");
        printf("0- Salir\n");
        do
        {

            printf("\nIndique la opci%cn: ",162);
            scanf("%d",&opcion);

            if(opcion<0 || opcion>4)
                printf("Digite una opci%cn v%clida\n",162,160);
        }
        while(opcion<0 || opcion>4);

        InfoEmp *e;
        e = (InfoEmp *)calloc(1,sizeof(InfoEmp));

        if(opcion==1)
            crear_empleado(e,"empleados.dat");
        else if(opcion==2)
            informe_empleados("empleados.dat");
        else if(opcion==3)
            modificar_empleado(e,"empleados.dat");
        else if(opcion==4)
            cambiar_estado_empleado(e,"empleados.dat");

        free(e);

    }
    while(opcion!=0);


    system("PAUSE");
    return 0;
}

void crear_empleado(InfoEmp *e, char *fname)
{
    FILE *femp;

    femp = fopen(fname,"a+b");
    if(femp == NULL)
    {
        printf("\nError al abrir el archivo\n");
        return;
    }

    printf("\n\nCrear Empleado\n\n");
    getchar();
    printf("ID: ");
    gets(e->ID);
    printf("Nombres: ");
    gets(e->nombres);
    printf("Apellidos: ");
    gets(e->apellidos);
    printf("Sueldo: ");
    scanf("%f",&e->sueldo);
    e->activo = 'A'; //Como nuevo empleado ya está activo
    printf("\nEmpleado creado exitosamente\n\n");

    fwrite(e,sizeof(InfoEmp),1,femp);
    fclose(femp);
}
void informe_empleados(char *fname)
{
    FILE *femp;
    femp = fopen(fname,"rb");
    if(femp == NULL)
    {
        printf("\nError al abrir el archivo\n");
        return;
    }
    InfoEmp *e;
    e = (InfoEmp *)calloc(1,sizeof(InfoEmp));

    //while(fread(e,sizeof(InfoEmp),1,femp)==1)
    printf("\n======================================================\n");
    printf("              Informe de Empleados\n");
    printf("======================================================\n\n");

    printf("%s%11s%19s%10s%10s\n","ID"
           ,"Nombres"
           ,"Apellidos"
           ,"Activo"
           ,"Sueldo");

    while(!feof(femp))
    {
        if(fread(e,sizeof(InfoEmp),1,femp))
        {
            printf("%s%10s%19s%6s%15.2f\n",e->ID
                   ,e->nombres
                   ,e->apellidos
                   ,(e->activo == 'A') ? "Si" : "No"
                   ,e->sueldo);
        }
    }
    fclose(femp);
    free(e);
    printf("\n\n");

}
void modificar_empleado(InfoEmp *e, char *fname)
{
    FILE *femp;

    femp = fopen(fname,"r+b");
    if(femp == NULL)
    {
        printf("\nError al abrir el archivo\n");
        return;
    }
    char *IDbuscar;
    IDbuscar = (char *)calloc(5,sizeof(char));
    float sueldonuevo;

    getchar();
    printf("Digite ID empleado a modificar: ");
    gets(IDbuscar);

    //mientras haya información en el archivo
    while(fread(e,sizeof(InfoEmp),1,femp)==1)
    {
        if(strcmp(e->ID, IDbuscar)==0)
        {
            printf("Ingrese sueldo actualizado: ");
            scanf("%f",&sueldonuevo);

            e->sueldo = sueldonuevo;
            fseek(femp,-sizeof(InfoEmp),SEEK_CUR);
            fwrite(e,sizeof(InfoEmp),1,femp);

            printf("\nEmpleado modificado exitosamente\n");
            break;
        }
    }

    fclose(femp);
    free(IDbuscar);

    informe_empleados(fname);
}
void cambiar_estado_empleado(InfoEmp *e, char *fname)
{
    FILE *femp;

    femp = fopen(fname,"r+b");
    if(femp == NULL)
    {
        printf("\nError al abrir el archivo\n");
        return;
    }
    char *IDbuscar;
    IDbuscar = (char *)calloc(5,sizeof(char));

    getchar();
    printf("Digite ID empleado a modificar: ");
    gets(IDbuscar);

    //mientras haya información en el archivo
    while(fread(e,sizeof(InfoEmp),1,femp)==1)
    {
        if(strcmp(e->ID, IDbuscar)==0)
        {
            if(e->activo == 'A')
                e->activo = 'I';
            else
                e->activo ='A';

            fseek(femp,-sizeof(InfoEmp),SEEK_CUR);
            fwrite(e,sizeof(InfoEmp),1,femp);

            printf("\nEmpleado actualizado exitosamente\n");
            break;
        }
    }

    fclose(femp);
    free(IDbuscar);

    informe_empleados(fname);
}

