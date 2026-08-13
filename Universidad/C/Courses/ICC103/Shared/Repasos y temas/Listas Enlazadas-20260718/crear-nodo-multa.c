#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct
{
    char codigo[12];
    char descripcion[50];
    int condicion;
    float monto;
} INFOMULTA;

typedef struct nodomulta
{
    INFOMULTA multa;
    struct nodomulta *proximo;
} NODOMULTA;

NODOMULTA* CrearNodoMulta(INFOMULTA, NODOMULTA *);
NODOMULTA* EliminarMulta(NODOMULTA *, char *);
void ImprimirListadoMulta(NODOMULTA *);

void mi_fflush();

int main()
{
    NODOMULTA *cabeza = NULL;
    INFOMULTA multa;
    int n, i;

    printf("Digite cantidad de multa: ");
    scanf("%d",&n);

    for(i=0; i<n; i++)
    {
        mi_fflush();
        printf("\nDigite codigo: ");
        gets(multa.codigo);

        printf("Digite descripcion: ");
        gets(multa.descripcion);

        printf("Digite condicion: ");
        scanf("%d",&multa.condicion);

        printf("Digite monto: ");
        scanf("%f",&multa.monto);

        cabeza=CrearNodoMulta(multa,cabeza);
    }
    ImprimirListadoMulta(cabeza);

    char *codigomulta;

    codigomulta=(char *)malloc(sizeof(cabeza->multa.codigo));

    mi_fflush();
    printf("\nDigite codigo multa a eliminar: ");
    gets(codigomulta);

    cabeza=EliminarMulta(cabeza,codigomulta);

    //Mostrar listado de personas
    printf("\nLuego de eliminar\n");
    ImprimirListadoMulta(cabeza);

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
NODOMULTA* CrearNodoMulta(INFOMULTA multa, NODOMULTA *proximo)
{
    NODOMULTA *pnuevo;
    pnuevo=(NODOMULTA *)malloc(sizeof(NODOMULTA));
    pnuevo->multa = multa;
    pnuevo->proximo = proximo;

    return pnuevo;
}
void ImprimirListadoMulta(NODOMULTA *cabeza)
{
    NODOMULTA *indice;
    int i=1;

    printf("\n\nNo.\tCodigo\tDescripcion\t\tCondicion\t\tMonto\n");
    for(indice=cabeza; indice; indice=indice->proximo,i++)
    {
        printf("%d\t%s\t%s\t\t%d\t\t%.2f\n",i,
               indice->multa.codigo,
               indice->multa.descripcion,
               indice->multa.condicion,
               indice->multa.monto);
    }
}
NODOMULTA* EliminarMulta(NODOMULTA *cabeza, char *codigo)
{
    NODOMULTA *indice, *anterior = NULL;
    for(indice=cabeza; indice; anterior=indice, indice=indice->proximo)
    {
        if(strcmp(indice->multa.codigo,codigo)==0)
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
