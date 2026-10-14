#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct
{
    int dia;
    int mes;
    int agno;
} FECHA;

typedef struct
{
    char ID[12];
    char nombre[50];
    FECHA fechanac;
    char genero; //'F' --> Femenino, 'M' --> Masculino
    char activo; //'A' --> Activo , 'I' --> Inactivo
} PERSONA;

void menu();
void create_persona(PERSONA *, char *);
void read_persona(PERSONA *, char *);
void update_persona(PERSONA *, char *);
void disable_persona(PERSONA *, char *);

int main()
{
    menu();

    system("PAUSE");
    return 0;
}
void menu()
{
    int opcion;

    printf("=====================================\n");
    printf("    Sistema de Personas\n");
    printf("=====================================\n");
    printf("1- Registrar persona\n");
    printf("2- Listar personas registradas\n");
    printf("3- Actualizar datos persona\n");
    printf("4- Desactivar persona\n");
    printf("5- Salir\n");
    printf("\nDigite la opci%cn: ",162);
    scanf("%d",&opcion);

    PERSONA *p;

    p = (PERSONA *)malloc(sizeof(PERSONA));

    if(opcion == 1)
        create_persona(p,"Persona.dat");
    else if(opcion == 2)
        read_persona(p,"Persona.dat");
    else if(opcion == 3)
        update_persona(p,"Persona.dat");
    else if(opcion == 4)
        disable_persona(p,"Persona.dat");

}
void create_persona(PERSONA *p, char *file_name)
{
    FILE *fpersona;

    fpersona = fopen(file_name,"a+b");
    if(fpersona == NULL)
    {
        printf("\nError al abrir archivo.\n");
        return;
    }

    getchar();
    printf("\nDigite ID: ");
    gets(p->ID);
    printf("\nDigite Nombre: ");
    gets(p->nombre);
    printf("\nDigite fecha de nacimiento (dd/mm/yyyy): ");
    scanf("%d/%d/%d",&p->fechanac.dia, &p->fechanac.mes,&p->fechanac.agno);
    getchar();
    printf("\nDigite su g%cnero (F/M): ",130);
    scanf("%c",&p->genero);
    p->activo = 'A'; //Por defecto toda persona registrada está activa

    fwrite(p,sizeof(PERSONA),1,fpersona);
    fclose(fpersona);

}
void read_persona(PERSONA *p, char *file_name)
{
    FILE *fpersona;
    int cont=1;

    fpersona = fopen(file_name,"rb");
    if(fpersona == NULL)
    {
        printf("\nError al abrir archivo.\n");
        return;
    }
    printf("=========================================================================================\n");
    printf("%2s%8s %-40s%-8s  %-9s %-9s\n\n","No."
                                       ,"ID"
                                       ,"Nombre"
                                       ,"Fecha Nac"
                                       ,"Genero"
                                       ,"Estatus");
    printf("=========================================================================================\n");
    while(fread(p,sizeof(PERSONA),1,fpersona)==1) //while(!feof(fpersona))
    {
        //fread(p,sizeof(PERSONA),1,fpersona);
        printf("%2d%8s %-40s%02d/%02d/%04d  %-9s %-9s\n",cont
                                                         ,p->ID
                                                         ,p->nombre
                                                         ,p->fechanac.dia
                                                         ,p->fechanac.mes
                                                         ,p->fechanac.agno
                                                         ,(p->genero == 'F')? "Femenino" : "Masculino"
                                                         ,(p->activo == 'A') ? "Activo" : "Inactivo");
        cont++;
    }

    fclose(fpersona);
}
void update_persona(PERSONA *p, char *file_name)
{
    FILE *fpersona;
    char *id_buscar;
    int find=0;

    id_buscar = (char *)calloc(9,sizeof(char));

    fpersona = fopen(file_name,"r+b");
    if(fpersona == NULL)
    {
        printf("\nError al abrir archivo.\n");
        return;
    }
    getchar();
    printf("Digite ID a buscar: ");
    gets(id_buscar);

    while(fread(p,sizeof(PERSONA),1,fpersona)==1)
    {
        if(strcmp(p->ID, id_buscar)==0)
        {
            p->fechanac.dia=9;
            p->fechanac.mes=9;
            p->fechanac.agno=9999;

            fseek(fpersona,-sizeof(PERSONA),SEEK_CUR);
            fwrite(p,sizeof(PERSONA),1,fpersona);
            find=1;

            printf("\nDatos modificados exitosamente\n");
            break;
        }
    }
    fclose(fpersona);
    if(find==0)
        printf("\nPersona no encontrada\n");
    else
        read_persona(p,file_name);
}
void disable_persona(PERSONA *p, char *file_name)
{
    FILE *fpersona;
    char *id_buscar;
    int find=0;

    id_buscar = (char *)calloc(9,sizeof(char));

    fpersona = fopen(file_name,"r+b");
    if(fpersona == NULL)
    {
        printf("\nError al abrir archivo.\n");
        return;
    }
    getchar();
    printf("Digite ID a buscar: ");
    gets(id_buscar);

    while(fread(p,sizeof(PERSONA),1,fpersona)==1)
    {
        if(strcmp(p->ID, id_buscar)==0)
        {
            p->activo ='I';

            fseek(fpersona,-sizeof(PERSONA),SEEK_CUR);
            fwrite(p,sizeof(PERSONA),1,fpersona);
            find=1;

            printf("\nPersona deshabilitada exitosamente\n");
            break;
        }
    }
    fclose(fpersona);
    if(find==0)
        printf("\nPersona no encontrada\n");
    else
        read_persona(p,file_name);
}
