#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define		SANTIAGO        1
#define		SANTO_DOMINGO   2
#define		LA_VEGA         3

#define		RENTADO         1
#define		DISPONIBLE	    2
#define		MANTENIMIENTO   3
#define		RETIRADO        4
int capturarOpcionMenu();
void capturarInventarioVehiculos(int size, int idsVehiculos[size], float kilometrosVehiculos[size], int estatusVehiculo[size], int sucursalVehiculos[size]);


/**Desarrollar el c�digo de este prototipo*/
void listarEstatusVehiculosSucursal(int size, int idsVehiculos[size], float kilometrosVehiculos[size], int estatusVehiculo[size], int sucursalVehiculos[size], int sucursalFiltrar, int estatusFiltrar)
{
    printf("*************** ESTATUS VEHICULOS X SUCURSAL ***************\n");
    printf("%-15s %5s %12s %-9s", "Sucursal", "ID", "Kilometros", "Estatus");
    printf("\n------------------------------------------------------------\n");
    int totalsantiago = 0;
    int totalsantodomingo = 0;
    int totalvega = 0;
    for (int i = 0; i<size; i++)
    {
        if ((sucursalFiltrar == -1) || (sucursalFiltrar == sucursalVehiculos[i]))
        {
            if ((estatusFiltrar == -1) || (estatusFiltrar == estatusVehiculo[i]))
            {
                char sucursalnombre[67];
                char estatusnombre[67];

                if (sucursalVehiculos[i] == SANTIAGO)
                {
                    totalsantiago++;
                    strcpy(sucursalnombre, "Santiago");
                }
                else if (sucursalVehiculos[i] == SANTO_DOMINGO)
                {
                    totalsantodomingo++;
                    strcpy(sucursalnombre, "Santo Domingo");
                }
                else if (sucursalVehiculos[i] == LA_VEGA)
                {
                    totalvega++;
                    strcpy(sucursalnombre, "La Vega");
                }

                if (estatusVehiculo[i] == RENTADO)
                {
                    strcpy(estatusnombre, "Rentado");
                }
                else if (estatusVehiculo[i] == DISPONIBLE)
                {
                    strcpy(estatusnombre, "Disponible");
                }
                else if (estatusVehiculo[i] == MANTENIMIENTO)
                {
                    strcpy(estatusnombre, "Mantenimiento");
                }
                else if (estatusVehiculo[i] == RETIRADO)
                {
                    strcpy(estatusnombre, "Retirado");
                }
                for (int j= SANTIAGO; j<=LA_VEGA; j++)
                {
                    if (sucursalVehiculos[i] == j)
                    {
                            printf("%-15s %5d %12.2f %-9s\n", sucursalnombre, idsVehiculos[j], kilometrosVehiculos[i], estatusnombre);

                    }
                }
            }
        }
    }
    printf("------------------------------------------------------------\n");
    printf("\nTotal x Sucursal:\n");
    printf("%-15s %3d\n", "Santiago", totalsantiago);
    printf("%-15s %3d\n", "Santo Domingo", totalsantodomingo);
    printf("%-15s %3d\n", "La Vega", totalvega);
}

/**Desarrollar el c�digo de este prototipo*/
void listarTotalVehiculosEstatusSucursal(int size, int idsVehiculos[size], float kilometrosVehiculos[size], int estatusVehiculo[size], int sucursalVehiculos[size])
{
    printf("*************** TOTAL VEHICULOS X ESTATUS Y SUCURSAL ***************\n");
    printf("%-15s %15s %15s %15s", "Estatus", "Santiago", "Santo Domingo", "La Vega");
    printf("\n---------------------------------------------------------------------------\n");
    char sucursalnombre2[67];
    char estatusnombre2[67];
    int totalsantiago2 = 0;
    int totalsantodomingo2 = 0;
    int totalvega2 = 0;
    int totalrentado = 0;
    int totaldisponible = 0;
    int totalmantenimiento = 0;
    int retirado = 0;




    for (int i=0; i<size; i++)
    {
        if (sucursalVehiculos[i] == SANTIAGO)
        {
            totalsantiago2++;
            strcpy(sucursalnombre2, "Santiago");
        }
        else if (sucursalVehiculos[i] == SANTO_DOMINGO)
        {
            totalsantodomingo2++;
            strcpy(sucursalnombre2, "Santo Domingo");
        }
        else if (sucursalVehiculos[i] == LA_VEGA)
        {
            totalvega2++;
            strcpy(sucursalnombre2, "La Vega");
        }
        if (estatusVehiculo[i] == RENTADO)
        {
            strcpy(estatusnombre2, "Rentado");
        }
        else if (estatusVehiculo[i] == DISPONIBLE)
        {
            strcpy(estatusnombre2, "Disponible");
        }
        else if (estatusVehiculo[i] == MANTENIMIENTO)
        {
            strcpy(estatusnombre2, "Mantenimiento");
        }
        else if (estatusVehiculo[i] == RETIRADO)
        {
            strcpy(estatusnombre2, "Retirado");
        }
        for (int j= RENTADO; j<=RETIRADO; j++)
        {
                printf("%-15s %15d %15d %15d\n",estatusnombre2, totalsantiago2, totalsantodomingo2, totalvega2);

        }
    }

    printf("---------------------------------------------------------------------------\n");
    printf("%-15s %15d %15d %15d\n","Total Sucursal:", totalsantiago2, totalsantodomingo2, totalvega2);



}
/**Desarrollar el c�digo de este prototipo*/
void filtrarVehiculosPorKilometros(int size, int idsVehiculos[size], float kilometrosVehiculos[size], int estatusVehiculo[size], int sucursalVehiculos[size], float kmMin, float kmMax)
{
    printf("\n*************** FILTRADO DE VEHICULOS POR RANGO DE KILOMETROS ***************\n");
    printf("Rango consultado: %.2f - %.2f\n", kmMin, kmMax);
    printf("%-15s %5s %12s %9s", "Sucursal", "ID", "Kilometros", "Estatus\n");
    printf("---------------------------------------------------------------------------\n");
    int totalsantiago = 0;
    int totalvega = 0;
    int totalsantodomingo = 0;
    char sucursalnombre[67];
    char estatusnombre[67];
    for (int i=0; i<size; i++)
    {
        if (kilometrosVehiculos[i] >=kmMin)
        {
            if (kilometrosVehiculos[i] <= kmMax)
            {

                if (sucursalVehiculos[i] == SANTIAGO)
                {
                    totalsantiago++;
                    strcpy(sucursalnombre, "Santiago");
                }
                else if (sucursalVehiculos[i] == SANTO_DOMINGO)
                {
                    totalsantodomingo++;
                    strcpy(sucursalnombre, "Santo Domingo");
                }
                else if (sucursalVehiculos[i] == LA_VEGA)
                {
                    totalvega++;
                    strcpy(sucursalnombre, "La Vega");
                }

                if (estatusVehiculo[i] == RENTADO)
                {
                    strcpy(estatusnombre, "Rentado");
                }
                else if (estatusVehiculo[i] == DISPONIBLE)
                {
                    strcpy(estatusnombre, "Disponible");
                }
                else if (estatusVehiculo[i] == MANTENIMIENTO)
                {
                    strcpy(estatusnombre, "Mantenimiento");
                }
                else if (estatusVehiculo[i] == RETIRADO)
                {
                    strcpy(estatusnombre, "Retirado");
                }
                for (int j= SANTIAGO; j<=LA_VEGA; j++)
                {
                    if (sucursalVehiculos[i] == j)
                    {
                        printf("%-15s %5d %12.2f %-9s\n", sucursalnombre, idsVehiculos[i], kilometrosVehiculos[i], estatusnombre);
                    }
                }
            }
        }
    }
    printf("---------------------------------------------------------------------------\n");
    printf("\nTotal encontrados en el rango:\n");
    printf("%-15s %3d\n", "Santiago", totalsantiago);
    printf("%-15s %3d\n", "Santo Domingo", totalsantodomingo);
    printf("%-15s %3d\n", "La Vega", totalvega);

}

int main()
{
    int n;

    printf("\nIntroduzca la cantidad de veh%cculos a registrar: ", 161);
    scanf("%d",&n);

    int idsVehiculos[n];
    float kilometrosVehiculos[n];
    int estatusVehiculo[n];
    int sucursalVehiculos[n];
    int estatusFiltrar, sucursalFiltrar;
    float kmMin, kmMax;

    capturarInventarioVehiculos(n, idsVehiculos, kilometrosVehiculos, estatusVehiculo, sucursalVehiculos);

    do
    {
        int opcion = capturarOpcionMenu();

        switch(opcion)
        {
        case 1:
            printf("\nFavor especificar la sucursal y/o estatus a filtrar; si desea listar todos, especificar -1:\n");
            printf("Sucursal Filtrar ( 1-> Santiago, 2-> Santo Domingo, 3-> La Vega) : ");
            scanf("%d", &sucursalFiltrar);
            printf("Estatus Veh%cculo ( 1-> Rentado, 2-> Disponible, 3-> Mantenimiento, 4-> Retirado ) : ", 161);
            scanf("%d", &estatusFiltrar);

            listarEstatusVehiculosSucursal(n, idsVehiculos, kilometrosVehiculos, estatusVehiculo, sucursalVehiculos, sucursalFiltrar, estatusFiltrar);
            break;

        case 2:
            listarTotalVehiculosEstatusSucursal(n, idsVehiculos, kilometrosVehiculos, estatusVehiculo, sucursalVehiculos);
            break;

        case 3:
            printf("Introduzca los kil%cometros m%cnimos a consultar: ", 162, 161);
            scanf("%f", &kmMin);
            printf("Introduzca los kil%cometros m%cximos a consultar: ", 162, 160);
            scanf("%f", &kmMax);

            filtrarVehiculosPorKilometros(n, idsVehiculos, kilometrosVehiculos, estatusVehiculo, sucursalVehiculos, kmMin, kmMax);
            break;

        case 4:
            break;
        }

        printf("\nPresione una tecla para continuar...");
        fflush(stdin);
        getche();
        system("cls");

    }
    while(1);
}

int capturarOpcionMenu()
{
    int opcion = -1;

    do
    {
        printf("\n********************** RentCar PUCMM SRL *********************\n");
        printf("1. Estatus Veh%cculos x Sucursal\n", 161);
        printf("2. Total Veh%cculos x Sucursal y Estatus\n", 161);
        printf("3. Filtrar Veh%cculos x Rango de Kil%cometros\n", 161, 162);
        printf("4. Salir\n");
        printf("Introduzca Opci%cn: ", 162 );
        fflush(stdin);
        int ret = scanf("%d", &opcion);
        if(ret <= 0 )
        {
            printf("Opci%c inv%clida!!", 162, 160);
            continue;
        }
    }
    while ( opcion < 1 || opcion > 3 );

    return opcion;
}

void capturarInventarioVehiculos(int size, int idsVehiculos[size], float kilometrosVehiculos[size], int estatusVehiculo[size], int sucursalVehiculos[size])
{
    for(int vehiculo = 0; vehiculo < size; vehiculo++ )
    {
        printf("Introduzca los datos del veh%cculo No. %d vista:\n",161, vehiculo + 1);
        printf("ID: ");
        scanf("%d", &idsVehiculos[vehiculo]);
        printf("Kil%cometros recorridos: ", 162);
        scanf("%f", &kilometrosVehiculos[vehiculo]);
        printf("Estatus Veh%cculo ( 1-> Rentado, 2-> Disponible, 3-> Mantenimiento, 4-> Retirado ) : ", 161);
        scanf("%d", &estatusVehiculo[vehiculo]);
        printf("Sucursal ( 1-> Santiago, 2 -> Santo Domingo, 3 -> La Vega ): ");
        scanf("%d", &sucursalVehiculos[vehiculo]);
    }
}

/*
15
1001
0
2
1
1002
99999
1
2
1003
25000
3
3
1004
75000
4
1
1005
150000
1
2
1006
10
2
3
1007
500
3
1
1008
2000
4
2
1009
35000
1
3
1010
47000
2
1
1011
88000
3
2
1012
92000
4
3
1013
1500
1
1
1014
6700
2
2
1015
12345
3
3

*/
