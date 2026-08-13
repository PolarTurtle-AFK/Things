#include<stdio.h>
#include<stdlib.h>

typedef struct
{
    char cedula[12];
    char nombres[50];
    char apellidos[50];
    int edad;
}INFOPERSONA;

typedef struct nodo
{
    INFOPERSONA persona;
    struct nodo *proximo;
}NODOPERSONA;

NODOPERSONA* CrearNodoPersona(INFOPERSONA, NODOPERSONA *);

void mi_fflush();

int main()
{
    NODOPERSONA *cabeza = NULL;
    INFOPERSONA pers;

    printf("Digite cantidad de personas: ");

    printf("Digite cedula: ");
    gets(pers.cedula);

    printf("Digite nombres: ");
    gets(pers.nombres);

    printf("Digite apellidos:");
    gets(pers.apellidos);

    printf("Digite edad: ");
    scanf("%d",&pers.edad);

    cabeza=CrearNodoPersona(pers,cabeza);

    free(cabeza);

    system("PAUSE");
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
NODOPERSONA* CrearNodoPersona(INFOPERSONA persona, NODOPERSONA *proximo)
{
    NODOPERSONA *pnuevo; //1-Crear un puntero en blanco
    //2-Reservar espacio en memoria
    pnuevo=(NODOPERSONA *)malloc(sizeof(NODOPERSONA));
    pnuevo->persona = persona;
    pnuevo->proximo = proximo;

    return pnuevo;
}

