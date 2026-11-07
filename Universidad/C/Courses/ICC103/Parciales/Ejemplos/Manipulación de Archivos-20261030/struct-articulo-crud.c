#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define LEN 30
#define MAX 100

typedef struct
{
    char ID[10];
    char nombre[LEN];
    float precio;
    char estatus; //'A'-> 'Activo' 'I'-> Inactivo
    int stock;
} ARTICULO;

void menu();
void crear_articulo();
void mostrar_articulos(char *);
void actualizar_articulo(char *);
void eliminar_articulo(char *, char *);

int main()
{
    menu();
    system("PAUSE");
    return 0;

}
void menu()
{
    int op;
    char *idbuscar;
    idbuscar = (char *)calloc(10,sizeof(char));

    printf("\nCRUD ARTICULO\n\n");
    printf("1- Crear Art%cculo\n",161);
    printf("2- Listar Art%cculos\n",161);
    printf("3- Actualizar Art%cculo\n",161);
    printf("4- Borrar Art%cculo\n",161);
    printf("Indique Opci%cn: ",162);
    scanf("%d",&op);

    if(op==1)
        crear_articulo();
    else if(op==2)
        mostrar_articulos("articulos.dat");
    else if (op==3)
    {
        getchar();
        printf("\nIndique ID articulo a modificar: ");
        gets(idbuscar);
        actualizar_articulo(idbuscar);
    }
    else if (op==4)
    {
        getchar();
        printf("\nIndique ID articulo a modificar: ");
        gets(idbuscar);
        eliminar_articulo(idbuscar,"articulos.dat");
    }

}
void crear_articulo()
{
    ARTICULO *a;

    a = (ARTICULO *)malloc(sizeof(ARTICULO));

    getchar();
    printf("\nDatos Art%cculo\n",161);
    printf("Digite ID: ");
    gets(a->ID);
    printf("Indique Nombre: ");
    gets(a->nombre);
    printf("Digite Precio: ");
    scanf("%f",&a->precio);
    a->estatus = 'A';
    a->stock = MAX;

    FILE *fa;

    fa = fopen("articulos.dat","a+b");
    if(fa==NULL)
    {
        printf("\nError abriendo archivo.\nNo se pudo crear el art%cculo.n",161);
        return;
    }
    else
    {
        fwrite(a,sizeof(ARTICULO),1,fa);
        printf("\nArticulo salvado correctamente\n");
    }
    free(a);
    fclose(fa);
}
void mostrar_articulos(char *nom_arch)
{
    FILE *fa;
    ARTICULO *a;

    a = (ARTICULO *)malloc(sizeof(ARTICULO));

    fa = fopen("articulos.dat","rb");

    if(fa==NULL)
    {
        printf("\nEl archivo no existe");
        return;
    }
    else
    {
        printf("\n==================================================================\n");
        printf("%10s%10s%10s%10s%10s\n","ID"
                                     ,"Nombre"
                                     ,"Precio"
                                     ,"Estatus"
                                     ,"Stock");
        printf("==================================================================\n");
        while(fread(a,sizeof(ARTICULO),1,fa)==1)
        {
            printf("%10s%10s%10.2f%10c%10d\n",a->ID
                                           ,a->nombre
                                           ,a->precio
                                           ,a->estatus
                                           ,a->stock);
        }
       // printf("\nArticulo salvado correctamente\n");
    }
    fclose(fa);
    free(a);
}
void actualizar_articulo(char *idbuscar)
{
    FILE *fa;
    ARTICULO *a;
    int find=0;

    a = (ARTICULO *)malloc(sizeof(ARTICULO));

    fa = fopen("articulos.dat","r+b");

    if(fa==NULL)
    {
        printf("\nEl archivo no existe");
        return;
    }
    else
    {
        while(fread(a,sizeof(ARTICULO),1,fa)==1)
        {
            if(stricmp(a->ID,idbuscar)==0)
            {
                if(a->estatus=='A')
                    a->estatus = 'I';
                else
                    a->estatus = 'A';

                find=1;
                fseek(fa,-sizeof(ARTICULO),SEEK_CUR);
                fwrite(a,sizeof(ARTICULO),1,fa);
                break;
            }
        }
    }
    fclose(fa);
    free(a);

    if(find==1)
    {
        printf("\nArticulo actualizado\n");
        mostrar_articulos("articulos.dat");
    }
}
void eliminar_articulo(char *idbuscar, char *nom_arch)
{
    FILE *fa, *ftemp;
    ARTICULO *a;
    int find=0;

    a = (ARTICULO *)malloc(sizeof(ARTICULO));

    ftemp = fopen("temp.dat","w+b");

    if(ftemp==NULL)
    {
        printf("\nNo se pudo crear archivo temporal");
        return;
    }

    fa = fopen(nom_arch,"rb");

    if(fa==NULL)
    {
        printf("\nEl archivo no existe");
        return;
    }
    else
    {
        while(fread(a,sizeof(ARTICULO),1,fa)==1)
        {
            if(stricmp(a->ID,idbuscar)==0)
                find=1;
            else
            {
                fwrite(a,sizeof(ARTICULO),1,ftemp);
            }
        }
    }
    fclose(ftemp);
    fclose(fa);

    if(find==1) //si elimine un articulo
    {
        remove(nom_arch); //borrar el archivo original que tenia todos los articulos
        rename("temp.dat",nom_arch);
        printf("\nArticulado eliminado\n\n");
        mostrar_articulos(nom_arch);
    }
    else
    {
        remove("temp.dat");
    }

}
