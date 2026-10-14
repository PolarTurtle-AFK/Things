#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct
{
    char id[9];
    char nombre[50];
    char codcarrera[4];
    char estatus; //'A' --> Activo 'I' --> Inactivo
} ESTUDIANTE;

void menu();
void create_estud(ESTUDIANTE *, char *);
void read_estudiante(ESTUDIANTE *, char *);
void update_estudiante(ESTUDIANTE *, char *);
void disable_estudiante(ESTUDIANTE *, char *);

int main()
{
    menu();


    system("PAUSE");
    return 0;
}
void menu()
{
    int opcion;

    ESTUDIANTE *e;

    printf("=============================\n");
    printf("  Sistema de Estudiantes\n");
    printf("=============================\n");
    printf("1- Registrar Estudiante\n");
    printf("2- Mostrar Estudiantes\n");
    printf("3- Actualizar Estudiante\n");
    printf("4- Desactivar Estudiante\n\n");
    printf("Digite una opci%cn: ",162);
    scanf("%d",&opcion);

    e = (ESTUDIANTE *)malloc(sizeof(ESTUDIANTE));
    if(opcion==1)
        create_estud(e,"Estudiante.dat");
    else if(opcion==2)
        read_estudiante(e,"Estudiante.dat");
    else if(opcion==3)
        update_estudiante(e,"Estudiante.dat");
    else if(opcion==4)
        disable_estudiante(e,"Estudiante.dat");

    free(e);

}
void create_estud(ESTUDIANTE *e, char *file_name)
{
    FILE *file_estud;

    getchar();
    printf("Digite Id: ");
    gets(e->id);

    printf("Digite nombre: ");
    gets(e->nombre);

    printf("Digite carrera: ");
    gets(e->codcarrera);
    e->estatus = 'A'; //por defecto el estudiante está Activo

    file_estud = fopen(file_name,"a+b");
    if(file_estud==NULL)
    {
        printf("\nNo se pudo abrir el archivo\n");
        return;
    }

    fwrite(e,sizeof(ESTUDIANTE),1,file_estud);
    fclose(file_estud);
}
void read_estudiante(ESTUDIANTE *e, char *file_name)
{
    int i=1;
    FILE *file_estud;
    file_estud = fopen(file_name,"rb");

    if(file_estud==NULL)
    {
        printf("\nNo se pudo abrir el archivo\n");
        return;
    }

    printf("\n-----------------------------------------------------------------------------\n");
    printf("%2s%8s %-40s%-8s  %-9s\n\n","No."
                                   ,"ID"
                                   ,"Nombre"
                                   ,"Carrera"
                                   ,"Estatus");
    printf("-----------------------------------------------------------------------------\n");
    while(!(feof(file_estud)))
    {

        if(fread(e,sizeof(ESTUDIANTE),1,file_estud))
        {
            printf("%2d %9s %-40s %-8s %-7s\n",i
                                            ,e->id
                                            ,e->nombre
                                            ,e->codcarrera
                                            ,(e->estatus == 'A') ? "Activo":"Inactivo");
            i++;
        }
    }
    fclose(file_estud);
}

void update_estudiante(ESTUDIANTE *e, char *file_name)
{
    FILE *file_estud;
    file_estud = fopen(file_name,"r+b");

    char *id_buscar = (char *)malloc(9*sizeof(char));
    char *codcarr = (char *)malloc(4*sizeof(char));
    int find=0;

    if(file_estud==NULL)
    {
        printf("\nNo se pudo abrir el archivo\n");
        return;
    }
    getchar();
    printf("\nDigite ID a modificar: ");
    gets(id_buscar);

    printf("\nDigite nueva carrera: ");
    gets(codcarr);

    while((fread(e,sizeof(ESTUDIANTE),1,file_estud))==1)
    {
        //Si coincide el estudiante actual del archivo con el que estoy buscando
        //por ID
        if(stricmp(e->id,id_buscar)==0)
        {
            strcpy(e->codcarrera,codcarr);
            //retrocedo porque el fread se coloca en el siguiente registro
            //y entonces debo retroceder para actualizar el actual encontrado
            fseek(file_estud,-sizeof(ESTUDIANTE),SEEK_CUR);
            fwrite(e,sizeof(ESTUDIANTE),1,file_estud);

            find =1;
            printf("\nEstudiante modificado\n");

            break;
        }
    }
    if(find==0)
        printf("\nEstudiante no encontrado\n");

    free(id_buscar);
    free(codcarr);
    fclose(file_estud);
}
void disable_estudiante(ESTUDIANTE *e, char *file_name)
{
    FILE *file_estud;
    file_estud = fopen(file_name,"r+b");

    char *id_buscar = (char *)malloc(9*sizeof(char));
    char *codcarr = (char *)malloc(4*sizeof(char));
    int find=0;

    if(file_estud==NULL)
    {
        printf("\nNo se pudo abrir el archivo\n");
        return;
    }
    getchar();
    printf("\nDigite ID a modificar: ");
    gets(id_buscar);

    while((fread(e,sizeof(ESTUDIANTE),1,file_estud))==1)
    {
        //Si coincide el estudiante actual del archivo con el que estoy buscando
        //por ID
        if(stricmp(e->id,id_buscar)==0)
        {
            e->estatus='I';
            //retrocedo porque el fread se coloca en el siguiente registro
            //y entonces debo retroceder para actualizar el actual encontrado
            fseek(file_estud,-sizeof(ESTUDIANTE),SEEK_CUR);
            fwrite(e,sizeof(ESTUDIANTE),1,file_estud);

            find =1;
            printf("\nEstudiante desactivado\n");

            break;
        }
    }
    if(find==0)
        printf("\nEstudiante no encontrado\n");

    free(id_buscar);
    free(codcarr);
    fclose(file_estud);
}

