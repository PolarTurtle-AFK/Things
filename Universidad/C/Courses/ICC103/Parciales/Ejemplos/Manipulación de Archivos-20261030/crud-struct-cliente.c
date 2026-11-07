#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct
{
    char cedula[12];
    char nombres[30];
    char apellidos[30];
    char estatus; //'A'-> Activo 'I'-> Inactivo
} InfoCliente;

void menu();

int main()
{
    menu();
    system("PAUSE");
    return 0;
}

InfoCliente *crear_cliente(char *);
void informe_clientes(char *);
void modificar_cliente(InfoCliente *, char *);
void cambiar_estatus_cliente(InfoCliente *, char *);

void menu()
{
    int op;
    InfoCliente *c;
    c = (InfoCliente *)calloc(1,sizeof(InfoCliente));

    char *filename;

    filename = (char *)calloc(13,sizeof(char));
    strcpy(filename,"clientes.dat");

    do
    {
        printf("\nSistema de Clientes\n\n");
        printf("1- Crear Cliente\n");
        printf("2- Informe de Clientes\n");
        printf("3- Modificar Cliente\n");
        printf("4- Cambiar Estatus Cliente\n");
        printf("0- Salir\n");

        do
        {
            printf("\nDigite opcion: ");
            scanf("%d",&op);

            if(op<0 || op>4)
                printf("\nIndique una opcion valida\n");

        }
        while(op<0 || op>4);


        if(op==1)
            c = crear_cliente(filename);
        else if (op==2)
            informe_clientes(filename);
        else if (op==3)
            modificar_cliente(c,filename);
        else if (op==4)
            cambiar_estatus_cliente(c,filename);

        printf("\n\n");
        system("PAUSE");
        system("CLS");
    }
    while(op!=0);
    free(c);
}
InfoCliente *crear_cliente(char *filename)
{
    InfoCliente *c;
    c = (InfoCliente *)calloc(1,sizeof(InfoCliente));

    FILE *fcliente;

    fcliente = fopen(filename,"a+b");
    if(fcliente == NULL)
    {
        printf("\nError al abrir archivo\n");
        return NULL;
    }

    printf("\n================================\n");
    printf("      Crear Cliente      ");
    printf("\n================================\n");

    getchar();
    printf("C%cdula: ",130);
    gets(c->cedula);
    printf("Nombres: ");
    gets(c->nombres);
    printf("Apellidos: ");
    gets(c->apellidos);
    c->estatus = 'A'; //Por defecto el cliente creado está activo

    fwrite(c,sizeof(InfoCliente),1,fcliente);
    fclose(fcliente);

    printf("\nCliente creado exitosamente!\n");

    return c;
}
void informe_clientes(char *filename)
{
    FILE *fcliente;

    fcliente = fopen(filename,"rb");
    if(fcliente == NULL)
    {
        printf("\nError al abrir archivo\n");
        return;
    }
    InfoCliente *c;
    c = (InfoCliente *)calloc(1,sizeof(InfoCliente));

    printf("\n=======================================================\n");
    printf("                 Informe de Clientes      ");
    printf("\n=======================================================\n");

    printf("%-10s%-15s%-15s%-10s\n\n","Cedula"
           ,"Nombres"
           ,"Apellidos"
           ,"Estado");

    while(!feof(fcliente))
    {
        if(fread(c,sizeof(InfoCliente),1,fcliente))
        {
            printf("%-10s%-15s%-15s%-10s\n",c->cedula
                   ,c->nombres
                   ,c->apellidos
                   ,(c->estatus == 'A') ? "Activo" : "Inactivo");
        }
    }
    fclose(fcliente);
    free(c);

}
void modificar_cliente(InfoCliente *c, char *filename)
{
    FILE *fcliente;

    fcliente = fopen(filename,"r+b");
    if(fcliente == NULL)
    {
        printf("\nError al abrir archivo\n");
        return;
    }
    char *cedBuscar;
    cedBuscar = (char *)calloc(12,sizeof(char));

    getchar();
    printf("Digite cedula cliente a modificar: ");
    gets(cedBuscar);

    while(fread(c,sizeof(InfoCliente),1,fcliente)==1)
    {
        if(strcmp(c->cedula,cedBuscar)==0)
        {
            printf("Nombres: ");
            gets(c->nombres);
            printf("Apellidos: ");
            gets(c->apellidos);

            fseek(fcliente,-sizeof(InfoCliente),SEEK_CUR);
            fwrite(c,sizeof(InfoCliente),1,fcliente);

            printf("\nCliente modificado\n");
            break;
        }
    }

    fclose(fcliente);
    free(cedBuscar);

    informe_clientes(filename);
}
void cambiar_estatus_cliente(InfoCliente *c, char *filename)
{
    FILE *fcliente;

    fcliente = fopen(filename,"r+b");
    if(fcliente == NULL)
    {
        printf("\nError al abrir archivo\n");
        return;
    }
    char *cedBuscar;
    cedBuscar = (char *)calloc(12,sizeof(char));

    getchar();
    printf("Digite cedula cliente a modificar: ");
    gets(cedBuscar);

    while(fread(c,sizeof(InfoCliente),1,fcliente)==1)
    {
        if(strcmp(c->cedula,cedBuscar)==0)
        {
            if(c->estatus == 'A')
                c->estatus = 'I';
            else if(c->estatus == 'I')
                c->estatus = 'A';

            fseek(fcliente,-sizeof(InfoCliente),SEEK_CUR);
            fwrite(c,sizeof(InfoCliente),1,fcliente);

            printf("\nCliente modificado\n");
            break;
        }
    }

    fclose(fcliente);
    free(cedBuscar);

    informe_clientes(filename);
}
