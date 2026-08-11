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
    struct nodopersona *anterior;
    struct nodopersona *proximo;
} NODOPERSONA;

NODOPERSONA* CrearNodoCabezaPersona(INFOPERSONA, NODOPERSONA *);
NODOPERSONA* CrearNodoColaPersona(INFOPERSONA, NODOPERSONA *);
NODOPERSONA* BuscarPersonaCedula(NODOPERSONA *, char *);
NODOPERSONA* EliminarPersonaCedula(NODOPERSONA *, char *);
void ImprimirListadoPersona(NODOPERSONA *);
void LiberarMemoriaLista(NODOPERSONA *);
void mi_fflush();

int main()
{
    NODOPERSONA *cabeza = NULL, *cola = NULL;
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

        //inicialmente inserto el nodo cabeza
        //y este tambien es el final de la lista
        //o sea nodo cola
        if(i==0)
        {
            cabeza=CrearNodoCabezaPersona(pers,cabeza);
            //if(cabeza!=NULL)
                //salvar_archivo;
            cola=cabeza;
        }
        //ya luego para el resto de elementos
        //me interesa agregar siempre al final de la lista
        else
            cola=CrearNodoColaPersona(pers,cola);
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
//y el anterior será NULL porque se trata de una lista
//doblemente enlazada
//Retornar el nuevo nodo agregado a la lista

NODOPERSONA* CrearNodoCabezaPersona(INFOPERSONA persona, NODOPERSONA *cabeza)
{
    NODOPERSONA *pnuevo;
    pnuevo=(NODOPERSONA *)malloc(sizeof(NODOPERSONA));
    pnuevo->persona = persona;
    pnuevo->proximo = cabeza;
    pnuevo->anterior = NULL;

    //validando si ya hay elementos en el nodo, por el nuevo nodo pasa a ser la cabeza
    //y el que llega en cabeza a la función pasa a ser el anterior al nuevo
    //que estoy creando
    if(cabeza!=NULL)
        cabeza->anterior = pnuevo;

    return pnuevo;
}
NODOPERSONA* CrearNodoColaPersona(INFOPERSONA persona, NODOPERSONA *cola)
{
    NODOPERSONA *pnuevo;
    pnuevo=(NODOPERSONA *)malloc(sizeof(NODOPERSONA));
    pnuevo->persona = persona;
    pnuevo->proximo = NULL;
    pnuevo->anterior = cola;

    //validando si ya hay elementos en el nodo, por el nuevo nodo pasa a ser la cabeza
    //y el que llega en cabeza a la función pasa a ser el anterior al nuevo
    //que estoy creando
    if(cola!=NULL)
        cola->proximo = pnuevo;

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
    //for(indice=cabeza; indice;)
    indice=cabeza;
    while(indice) //mientras haya un valor en el nodo o sea != NULL
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

NODOPERSONA* EliminarPersonaCedula(NODOPERSONA *cabeza, char *cedula)
{
    NODOPERSONA *indice;
    //si desea buscar desde el final debe usar cola
    //for(indice=cola; indice; indice=indice->anterior)
    for(indice=cabeza; indice; indice=indice->proximo)
    {
        if(strcmp(indice->persona.cedula,cedula)==0)
        {
            //busco el anterior del elemento que deseo borrar
            //para asignarle el proximo de este al anterior
            if(indice->anterior)
                indice->anterior->proximo = indice->proximo;

            //buscar el próximo del elemento que deseo borrar
            //para asignarle el anterior de este a su próximo
            //de manera que no quede suelto
            if(indice->proximo)
                indice->proximo->anterior = indice->anterior;

            if(indice==cabeza)
                cabeza=indice->proximo;

            free(indice); //Liberar el espacio en memoria del que estoy eliminando
            return cabeza;
        }
    }
    return cabeza;
}

