#include<stdio.h>
#include<stdlib.h>
#define MAXID 6
#define MAXSTRING 50
#define MAXCLIENTE 3

typedef struct
{
    char id[MAXID];
    char nombre[MAXSTRING];

}CLIENTE;

typedef struct nodo
{
    CLIENTE cliente;
    struct nodo *proximo;
}NODO;

CLIENTE captura_cliente();
void insertar_nodo(CLIENTE, NODO **);
void insertar_cola(CLIENTE, NODO **);
void imprimir_cliente(CLIENTE);
void freeall(NODO *);

int main()
{
    int i;
    NODO *cabeza, *cola;
    cabeza = cola = NULL;

    for(i=0;i<MAXCLIENTE;i++)
    {
        if(i==0) //cuando se trate del primer elemento de la lista o nodo cabeza
        {
            insertar_nodo(captura_cliente(), &cabeza);
            cola=cabeza;
        }
        //cuando la lista ya tiene más de un elemento
        else
            insertar_cola(captura_cliente(), &cola);
    }
    //imprimir los valores de la lista
    NODO *indice;

    for(indice=cabeza;indice;indice=indice->proximo)
    {
        imprimir_cliente(indice->cliente);
    }

    freeall(cabeza);

    system("PAUSE");
    return 0;
}
//Función: captura_cliente
//Se declara una estructura del tipo Cliente, y se capturan sus datos
//retorna la estructura con los datos digitados por el usuario
CLIENTE captura_cliente()
{
    CLIENTE cl;

    printf("Datos cliente:\n");
    printf("Digite id: ");
    gets(cl.id);
    printf("Digite nombre: ");
    gets(cl.nombre);

    return cl;
}

void insertar_nodo(CLIENTE cliente, NODO **cabeza)
{
    NODO *pnuevo;

    pnuevo=(NODO *)malloc(sizeof(NODO));
    pnuevo->cliente = cliente;
    pnuevo->proximo = *cabeza;
    *cabeza = pnuevo;

    return;
}
void insertar_cola(CLIENTE cliente, NODO **cola)
{
    NODO *pnuevo;

    pnuevo=(NODO *)malloc(sizeof(NODO));
    pnuevo->cliente = cliente;
    pnuevo->proximo=NULL;
    (*cola)->proximo=pnuevo;

    *cola=pnuevo;
}
void imprimir_cliente(CLIENTE cliente)
{
    printf("%s %s\n",cliente.id,cliente.nombre);
}
void freeall(NODO *nodo)
{
    NODO *indice, *temporal;
    for(indice=nodo; indice; temporal=indice, indice=indice->proximo)
        free(temporal);
}

