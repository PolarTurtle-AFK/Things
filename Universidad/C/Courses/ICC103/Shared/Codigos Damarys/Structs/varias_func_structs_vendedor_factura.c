/*


a) Realizar la función void cliente_mas_deudor
(Factura fact[], int cf, Fecha actual, CondicionPago cond[], int cc)
la cual imprime el código del cliente con más facturas vencidas,
a la fecha actual.

b) Realizar la función void cliente_mas_compra
(Factura fact[], int cf, Cliente cl[], int ccl)
la cual imprime los datos del cliente que más ha comprado,
es decir, el que tiene el monto acumulado mayor en facturas.
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct
{
    int dia, mes, agno;
}Fecha;

typedef struct
{
   char CodCliente[5];
   char nombre[50];
   char telefono[11];
   Fecha Fec_Ingreso;
}Cliente;

typedef struct
{
   char CodCondPago[3];
   int dias;

}CondicionPago;

typedef struct
{
   char CodCliente[5];
   Fecha Fec_Factura;
   float monto;
   char pagada;
   char CodCondPago[3];

}Factura;

void cliente_mas_deudor(Factura [], int, Fecha, CondicionPago [], int);
void cliente_mas_compra(Factura [], int, Cliente [], int);
void cliente_mas_antiguo(Cliente cl[], int);
void cliente_mas_antiguo_ref_dias(Cliente cl[], int);

int main()
{
    int ncp=5, nfact=6, ncl=3;
    //condiciones de pago registradas
    CondicionPago cp[] = {"01",10,
                          "02",15,
                          "03",30,
                          "04",45,
                          "05",60
                         };
    //clientes registrados
    Cliente cl[] = {"0001","Anthony Rodriguez","8095555555",1,2,2000,
                    "0002","Melany Reyna","8095554444",29,10,1999,
                    "0003","Ricardo Robinson","18295553333",31,10,1999,
                   };

    //facturas registradas
    Factura f[] = {"0001",5,2,2000,890.55,'S',"01",
                   "0002",15,2,2004,8500.00,'S',"01",
                   "0003",5,6,2007,67.50,'S',"01",
                   "0003",10,3,2009,18456.50,'N',"05",
                   "0002",30,3,2009,985,'N',"01",
                   "0002",10,3,2009,567.88,'S',"01",
                  };
    int i;
    //imprimir datos clientes
    for(i=0;i<ncl;i++)
    {
        printf("\n\nCliente No.%d:",i+1);
        printf("\nCodigo: %s.",cl[i].CodCliente);
        printf("\nNombre: %s.",cl[i].nombre);
        printf("\nTelefono: %s.",cl[i].telefono);
        printf("\nFecha Ing.: %02d/%02d/%04d.",cl[i].Fec_Ingreso.dia,cl[i].Fec_Ingreso.mes,cl[i].Fec_Ingreso.agno);
    }
    //imprimir datos facturas
    for(i=0;i<nfact;i++)
    {
        printf("\n\nFactura No.%d:",i+1);
        printf("\nCliente: %s.",f[i].CodCliente);
        printf("\nFecha Fact.: %02d/%02d/%04d.",f[i].Fec_Factura.dia,f[i].Fec_Factura.mes,f[i].Fec_Factura.agno);
        printf("\nMonto a Pagar: %.2f.",f[i].monto);
        printf("\nPagada: %c.",f[i].pagada);
        printf("\nCondicion Pago: %s.",f[i].CodCondPago);
    }

    Fecha Fec_Actual;
    printf("\n\n");
    //printf("\nDigite la fecha actual para obtener cliente mas deudor: ");
    //scanf("%d %d %d",&Fec_Actual.dia,&Fec_Actual.mes,&Fec_Actual.agno);

    //determinar clieten mas deudor
    //cliente_mas_deudor(f,nfact,Fec_Actual,cp,ncp);

    //determinar cliente mas compra
    cliente_mas_compra(f,nfact,cl,ncl);

    //determinar cliente mas antiguo
    //cliente_mas_antiguo(cl,ncl);

    //determinar cliente mas antiguo manejando los dias en vez
    //de las fechas como tal (dia, mes, agno)
    //cliente_mas_antiguo_ref_dias(cl,ncl);

    printf("\n\n");
    system("pause");
    return 0;
}
//asumir que un mes tiene 30 dias
//un año 365
void cliente_mas_deudor(Factura fact[], int cf, Fecha actual, CondicionPago cond[], int cc)
{
    int i, j, k, cont=0, masdeuda=0, poscldeudor=-1;
    long diasfact, diasact;
    //llevar todo a dias, debido a la que la condicion de pago
    //se maneja tomando en cuentas los dias a pagar
    diasact = actual.dia+(actual.mes*30)+(actual.agno*365);
    //recorrer todas las facturas
    for(i=0;i<cf;i++)
    {
        //recorrer las demás facturas, para buscar las del cliente
        //de la factura actual "i"
        for(j=i;j<cf;j++)
        {
            //si la factura que estoy verificando "j" es del mismo cliente de la
            //factura actual tomada inicialmente en "i"
            if(stricmp(fact[i].CodCliente,fact[j].CodCliente)==0)
            {
                //verificar si no está pagada
                if(fact[j].pagada=='N')
                {
                    //llevar la fecha de la factura a dias para comparar mejor
                    diasfact=fact[j].Fec_Factura.dia+(fact[j].Fec_Factura.mes*30)+(fact[j].Fec_Factura.agno*365);

                    //determinar la condición de pago de la factura actual
                    //para ver cuantos dias tiene para pagar
                    for(k=0;k<cc;k++)
                    {
                        //si al restar la fecha actual, menos la de la factura
                        //sobrepasa la cantidad de dias de la condicion de pago
                        //de tal factura, entonces está vencida
                        if(stricmp(fact[j].CodCondPago,cond[k].CodCondPago)==0)
                        {
                            if((diasact-diasfact)>cond[k].dias)
                                cont++;
                        }
                    }
                }
            }
        }
        //cuando termino de verificar todas las facturas del cliente
        //actual ver si es el que más debe
        if(cont>masdeuda)
        {
            masdeuda = cont;
            poscldeudor = i; //obtengo posición de la factura
                             //que tiene el código del cliente mas deudor
        }
        cont=0;
    }
    //finalmente imprimir codigo cliente mas deudor
    if(poscldeudor>=0)
    {
        printf("\nEl cliente mas deudor es: ");
        puts(fact[poscldeudor].CodCliente);
    }
    else
        printf("\nPara la fecha indicada no hay clientes deudores.\n");
}

void cliente_mas_compra(Factura fact[], int cf, Cliente cl[], int ccl)
{
    int i, j, cont, posclmascompra=0;
    float montomayorcl=0, montoclact=0;
    //recorrer todos los clientes
    for(i=0;i<ccl;i++)
    {
        //recorrer todas las facturas, para obtener
        //las del cliente actual
        for(j=0;j<cf;j++)
        {
            //si la factura actual es del codigo del cliente actual
            //acumular monto en factura
            if(stricmp(cl[i].CodCliente,fact[j].CodCliente)==0)
                montoclact+= fact[j].monto;
        }
        //al terminar de buscar todas las facturas de ese cliente
        //verificar si es el que mas ha comprado
        if(montoclact>montomayorcl)
        {
            montomayorcl=montoclact;
            posclmascompra = i;
        }
    }
    //imprimir datos del cliente que mas ha comprado
    printf("\nEl cliente que mas compra es: \n");
    printf("\nCodigo: %s.",cl[posclmascompra].CodCliente);
    printf("\nNombre: %s.",cl[posclmascompra].nombre);
    printf("\nTelefono: %s.",cl[posclmascompra].telefono);
    printf("\nFecha Ing.: %02d/%02d/%04d.",cl[posclmascompra].Fec_Ingreso.dia,cl[posclmascompra].Fec_Ingreso.mes,cl[posclmascompra].Fec_Ingreso.agno);
}

void cliente_mas_antiguo(Cliente cl[], int ccl)
{
    int i, j, posantiguo=0;
    Fecha Antiguo;

    Antiguo.dia=cl[0].Fec_Ingreso.dia;
    Antiguo.mes=cl[0].Fec_Ingreso.mes;
    Antiguo.agno=cl[0].Fec_Ingreso.agno;

    //recorrer todos los clientes
    for(i=0;i<ccl;i++)
    {
        //si el año es menor, ya este es mas antiguo
        if(cl[i].Fec_Ingreso.agno<Antiguo.agno)
        {
            posantiguo=i;
            Antiguo = cl[i].Fec_Ingreso;
        }
        //si es mayor o igual verificar entonces el mes
        else if(cl[i].Fec_Ingreso.agno==Antiguo.agno && cl[i].Fec_Ingreso.mes<Antiguo.mes)
        {
            posantiguo=i;
            Antiguo = cl[i].Fec_Ingreso;
        }
        //es del mismo año y del mismo mes, entonces verificar los dias
        else if(cl[i].Fec_Ingreso.mes==Antiguo.mes && cl[i].Fec_Ingreso.dia<Antiguo.dia)
        {
            posantiguo=i;
            Antiguo = cl[i].Fec_Ingreso;
        }
    }
    //imprimir datos del cliente que mas antiguo
    printf("\n\nEl cliente mas antiguo es: \n");
    printf("\nCodigo: %s.",cl[posantiguo].CodCliente);
    printf("\nNombre: %s.",cl[posantiguo].nombre);
    printf("\nTelefono: %s.",cl[posantiguo].telefono);
    printf("\nFecha Ing.: %02d/%02d/%04d.",cl[posantiguo].Fec_Ingreso.dia,cl[posantiguo].Fec_Ingreso.mes,cl[posantiguo].Fec_Ingreso.agno);
}

void cliente_mas_antiguo_ref_dias(Cliente cl[], int ccl)
{
    int i, j, posantiguo=0;
    long menor, actual;

    menor=cl[0].Fec_Ingreso.dia+(cl[0].Fec_Ingreso.mes*30)+(cl[0].Fec_Ingreso.agno*365);

    //recorrer todos los clientes
    for(i=0;i<ccl;i++)
    {
        actual = cl[i].Fec_Ingreso.dia+(cl[i].Fec_Ingreso.mes*30)+(cl[i].Fec_Ingreso.agno*365);
        if(actual<menor)
        {
            posantiguo=i;
            menor = actual;
        }
    }
    //imprimir datos del cliente que mas antiguo
    printf("\n\nEl cliente mas antiguo es (REF DIAS): \n");
    printf("\nCodigo: %s.",cl[posantiguo].CodCliente);
    printf("\nNombre: %s.",cl[posantiguo].nombre);
    printf("\nTelefono: %s.",cl[posantiguo].telefono);
    printf("\nFecha Ing.: %02d/%02d/%04d.",cl[posantiguo].Fec_Ingreso.dia,cl[posantiguo].Fec_Ingreso.mes,cl[posantiguo].Fec_Ingreso.agno);
}

