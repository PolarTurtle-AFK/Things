#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct
{
    char cedula[12];
    char nombres[50];
    char apellidos[50];
    int edad;
} INFOPERSONA;

typedef struct nodopersona
{
    INFOPERSONA persona;
    struct nodopersona *proximo;
} NODOPERSONA;

NODOPERSONA* CrearNodoCabezaPersona(INFOPERSONA, NODOPERSONA *);
NODOPERSONA* BuscarPersonaCedula(NODOPERSONA *, char *);
NODOPERSONA* EliminarPersonaCedula(NODOPERSONA *, char *);
void ImprimirListadoPersona(NODOPERSONA *);
void LiberarMemoriaLista(NODOPERSONA *);
void mi_fflush();

int main()
{
    NODOPERSONA *cabeza = NULL;
    INFOPERSONA pers;
    int n, i;

    printf("Digite cantidad de personas: ");
    scanf("%d",&n);

    for(i=0; i<n; i++)
    {
        mi_fflush();
        printf("\nDatos persona %d: \n",i+1);
        printf("Digite cedula: ");
        gets(pers.cedula);

        printf("Digite nombres: ");
        gets(pers.nombres);

        printf("Digite apellidos:");
        gets(pers.apellidos);

        printf("Digite edad: ");
        scanf("%d",&pers.edad);

        //cada vez que creo un nodo se asigna como el nodo
        //inicial o nodo cabeza de mi lista
        cabeza=CrearNodoCabezaPersona(pers,cabeza);
    }

    ImprimirListadoPersona(cabeza);
    char *cedulabuscar;

    cedulabuscar=(char *)malloc(sizeof(cabeza->persona.cedula));

    mi_fflush();
    printf("\nDigite cedula a buscar: ");
    gets(cedulabuscar);

    NODOPERSONA *persona_encont = BuscarPersonaCedula(cabeza,cedulabuscar);

    if(persona_encont!=NULL)
        printf("\n%s %s\n",persona_encont->persona.nombres,persona_encont->persona.apellidos);
    else
        printf("Cedula NO registrada\n");

    cabeza=EliminarPersonaCedula(cabeza,cedulabuscar);

    //Mostrar listado de personas
    printf("\nLuego de eliminar\n");
    ImprimirListadoPersona(cabeza);
    LiberarMemoriaLista(cabeza);

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
//Función: CrearNodoPersona
//Objetivo: Crea un nuevo nodo como cabeza de mi lista
//Inicialmente el nodo cabeza apunta a NULL, pero ya luego
//irá apuntando al nodo enviado que ya existe en la lista
//Retornar el nuevo nodo agregado a la lista

NODOPERSONA* CrearNodoCabezaPersona(INFOPERSONA persona, NODOPERSONA *proximo)
{
    NODOPERSONA *pnuevo; //1-Crear un puntero en blanco
    //2-Reservar espacio en memoria
    pnuevo=(NODOPERSONA *)malloc(sizeof(NODOPERSONA));
    pnuevo->persona = persona;
    pnuevo->proximo = proximo;

    return pnuevo;
}
//Función: ImprimirListadoPersona
//Recorre la lista para ir mostrando todos los datos
void ImprimirListadoPersona(NODOPERSONA *cabeza)
{
    NODOPERSONA *indice;
    int i=1;

    printf("\n\nNo.\tCedula\tNombres\t\tApellidos\t\tEdad\n");
    for(indice=cabeza; indice; indice=indice->proximo,i++)
    {
        printf("%d\t%s\t%s\t\t%s\t\t%d\n",i,
               indice->persona.cedula,
               indice->persona.nombres,
               indice->persona.apellidos,
               indice->persona.edad);
    }
}
//Función: LiberarMemoriaLista
//Objetivo: liberar espacios en memoria
//de los nodos
void LiberarMemoriaLista(NODOPERSONA *cabeza)
{
    NODOPERSONA *indice, *temp;
    for(indice=cabeza; indice;)
    {
        temp = indice->proximo;
        free(indice);
        indice = temp;
    }
}
NODOPERSONA* BuscarPersonaCedula(NODOPERSONA *cabeza, char *cedula)
{
    NODOPERSONA *indice;
    for(indice=cabeza; indice; indice=indice->proximo)
    {
        if(strcmp(indice->persona.cedula,cedula)==0)
            return indice;
    }
}
/*
NODOPERSONA* BuscarPersonaCedula(NODOPERSONA *cabeza, char *cedulaant, char *cedulanueva)
{
    NODOPERSONA *indice;
    for(indice=cabeza; indice; indice=indice->proximo)
    {
        if(strcmp(indice->persona.cedula,cedula)==0)
            strcpy(indice->persona.cedula,cedulanueva)
    }
}*/
NODOPERSONA* EliminarPersonaCedula(NODOPERSONA *cabeza, char *cedula)
{
    NODOPERSONA *indice, *anterior = NULL;
    for(indice=cabeza; indice; anterior=indice, indice=indice->proximo)
    {
        if(strcmp(indice->persona.cedula,cedula)==0)
        {
            if(anterior==NULL)
                cabeza=indice->proximo;
            else
                anterior->proximo = indice->proximo;

            free(indice); //Liberar el espacio en memoria del que estoy eliminando
            return cabeza;
        }
    }
    return cabeza;
}
