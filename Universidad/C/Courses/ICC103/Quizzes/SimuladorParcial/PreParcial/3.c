#include <stdio.h>
#include <time.h>
#include <string.h>

#define MAX 100
typedef struct
{
int dia, mes, agno;
}Fecha;

typedef struct
{ 
char CodCliente[5];
Fecha Fec_factura;
float monto;
char CodCondPago[3];
}Factura;

typedef struct
{
char CodCliente [5];
char nombre[50];
char telefono[11];
Fecha Fec_Ingreso;
}Cliente; 

void oldest_customers (Cliente cl[MAX], int cantcl){

    time_t ahora = time(NULL);
    struct tm *fecha = localtime(&ahora);
    int anioActual = fecha->tm_year + 1900;

    for(int i=0;i<cantcl;i++){
        if (anioActual - cl[i].Fec_Ingreso.agno > 10 ||
            (anioActual - cl[i].Fec_Ingreso.agno == 10 &&
             (cl[i].Fec_Ingreso.dia >= 1 || cl[i].Fec_Ingreso.mes >= 1)))
            printf("Nombre: %s\n%d",cl[i].nombre, cl[i].Fec_Ingreso.agno);
    }
}

void customer_most_purchases(Factura *fact, int cantf, Cliente *cl, int cantcl){
int indicemayor=-1;
float bestcant=-1, cant;
    for (int i=0;i<cantcl;i++){
        cant=0;
        for(int j=0; j<cantf;j++){
            if(strcmp((cl+i)->CodCliente, (fact+j)->CodCliente) == 0){
                cant+=(fact+j)->monto;
            }
        }
        if (cant>bestcant){
            bestcant = cant;
            indicemayor = i;
        }
    }
    printf("Nombre: %s",cl[indicemayor].nombre);
}

int main(){
    Cliente clientes[MAX] = {
        {
            "ABCD", 
            "Amin", 
            "999-111-7272", 
            {12, 12, 2007}
        },
        {
            "DCBA", 
            "Adrian", 
            "999-676-3123", 
            {6, 10, 2024}
        }
    };

    Factura fact[MAX] = {
        {
            "ABCD",
            {12,12,2007},
            67.27,
            "345"
        }
    };
    oldest_customers(clientes, 2);
    customer_most_purchases(fact, 1, clientes, 2);
    return 0;
}
