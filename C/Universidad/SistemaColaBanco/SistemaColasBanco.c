#include <stdio.h>
#include <stdlib.h>

long generarNumeroTicket(int n, int clientesCajero[][n], int serviciosAtiendeCajeros[][n], int *cajeroSeleccionado, int *posicionCliente);
long atenderClienteCajero(int n, int clientesCajero[3][n], int serviciosAtiendeCajero[3][n], int codigoCajero, int *tipoServicio);
void listarTicketsEnEspera(int n, int clientesCajero[3][n], int serviciosAtiendeCajero[3][n]);
void listarClientesEnCola(int size, int clientesCajero[3][size]);
double duracionServicio(int n, int servicio[][n], int cajero, int posicion);
const char *nombreservicio(int servicio);
int main()
{
    int maxClientes = 0;
    int servicio = 0;
    long ticket = 0;
    double duracion = 0;
    int cajeroSeleccionado = 0;
    int posicionCliente = 0;

    printf("Introduce cantidad maxima de clientes que puede trabajar cada cajero: ");
    do scanf("%d", &maxClientes); while (maxClientes <= 0);
    if (maxClientes == 67)
    {
        printf("Six Seven!!!\n");
        return 0;
    }
    int opcion = 0;
    int clientesCajero[3][maxClientes];
    int serviciosAtiendeCajero[3][maxClientes];

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < maxClientes; j++)
        {
            clientesCajero[i][j] = 0;
            serviciosAtiendeCajero[i][j] = 0;
        }
    }

    do
    {
        char Respuesta = '0';
        system("cls");
        printf("****************************** BANK PUKAM SRL ******************************\n");
        printf("1. Generar Ticket\n");
        printf("2. Atender Cliente\n");
        printf("3. Listar Tiempo Espera Clientes\n");
        printf("4. Listar Clientes En Cola\n");
        printf("5. Salir\n");
        printf("Seleccionar Opcion: ");
        scanf("%d", &opcion);

        switch (opcion)
        {
        case 1:
        {
            printf("\n\n");
            printf("************** SERVICIOS OFRECIDOS **************\n");
            printf("1. Deposito\n");
            printf("2. Retiro\n");
            printf("3. Apertura de Cuenta\n");
            printf("4. Solicitud de Prestamo\n");
            printf("5. Consulta General\n");

            printf("\nSelecciona un Servicio: ");
            do
            {
                scanf("%d", &servicio);
                if (servicio < 1 || servicio > 5)
                {
                    printf("Desea cancelar la seleccion de servicio?: ");
                    fflush(stdin);
                    scanf("%c", &Respuesta);

                    if (Respuesta == 's' || Respuesta == 'S')
                    {
                        printf("\nSolicitud de Servicio Cancelada!");
                        printf("\nPresione Enter para continuar...");
                        fflush(stdin);
                        getchar();
                        break;
                    }else if (Respuesta == 'n' || Respuesta == 'N')
                    {
                        printf("Por favor, seleccione un servicio valido (1-5): ");
                    }
                }
            } while (servicio < 1 || servicio > 5);
            if (servicio < 1 || servicio > 5)
            {
                break;
            }

            ticket = generarNumeroTicket(maxClientes, clientesCajero, serviciosAtiendeCajero, &cajeroSeleccionado, &posicionCliente);
            duracion = duracionServicio(maxClientes, serviciosAtiendeCajero, cajeroSeleccionado, posicionCliente);
            if (ticket > 0)
            {
                serviciosAtiendeCajero[cajeroSeleccionado][posicionCliente] = servicio;

                printf("\n%-19s %-s%05ld\n", "No. Ticket:", "TK-", ticket);
                printf("%-19s %-s\n", "Servicio:", nombreservicio(servicio));
                printf("%-19s %.2f segundos\n", "Tiempo en Espera:", duracion);
                printf("%-19s %-s%d\n", "Le atendera:", "cajero No.", cajeroSeleccionado + 1);
            }
            else
            {
                printf("No se pudo generar el ticket. Todos los cajeros estan ocupados.\n");
            }
            
            printf("\nPresione Enter para continuar...");
            fflush(stdin);
            getchar();
            break;
        }
        case 2:
            printf("Ingrese el numero de cajero (1-3) para atender al cliente: ");
            scanf("%d", &cajeroSeleccionado);
            if (cajeroSeleccionado < 1 || cajeroSeleccionado > 3)
            {
                printf("Cajero invalido. Debe estar entre 1 y 3.\n");
                printf("\nPresione Enter para continuar...");
                fflush(stdin);
                getchar();
                break;
            }
            cajeroSeleccionado--;
            ticket = atenderClienteCajero(maxClientes, clientesCajero[0], serviciosAtiendeCajero, cajeroSeleccionado, &servicio);
            if (ticket > 0)
            {
                printf("\n%s fue realizado(a) exitosamente para el ticket no.: TK-%05ld por el cajero no. %d\n", nombreservicio(servicio), ticket, cajeroSeleccionado+1);
            }
            else if (ticket == 0)
            {
                printf("No hay clientes en cola para el cajero %d.\n", cajeroSeleccionado);
                printf("\nPresione Enter para continuar...");
                fflush(stdin);
                getchar();
                break;
            }
            printf("\nPresione Enter para continuar...");
            fflush(stdin);
            getchar();
            break;
        case 3:
            listarTicketsEnEspera(maxClientes, clientesCajero, serviciosAtiendeCajero);
            printf("\nPresione Enter para continuar...");
            fflush(stdin);
            getchar();
            break;
        case 4:
            listarClientesEnCola(maxClientes, clientesCajero);
            printf("\nPresione Enter para continuar...");
            fflush(stdin);
            getchar();
            break;

        case 5:
            printf("Saliendo del programa...\n");
            break;
        default:
            printf("Servicio debe estar entre los listados(1-5)\n");
            printf("Desea cancelar la seleccion de servicio?: ");

            fflush(stdin);
            scanf("%c", &Respuesta);

            if (Respuesta == 's' || Respuesta == 'S')
            {
                printf("\nSolicitud de Servicio Cancelada!");
                printf("\nPresione Enter para continuar...");
                fflush(stdin);
                getchar();
            }
            break;

            if (opcion != 5)
            {
            }
        }
    } while (opcion != 5);

    return 0;
}

long generarNumeroTicket(int n, int clientesCajero[][n], int serviciosAtiendeCajeros[][n], int *cajeroSeleccionado, int *posicionCliente)
{
    long ticketMayor = 0;
    int menorcajero = 0;
    int menorcantidad = n + 1;

    for (int i = 0; i < 3; i++)
    {
        int cantidad = 0;
        for (int j = 0; j < n; j++)
        {
            if (clientesCajero[i][j] != 0)
            {
                cantidad++;
            }
        }
        if (cantidad < menorcantidad)
        {
            menorcantidad = cantidad;
            menorcajero = i;
        }
    }
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (clientesCajero[i][j] > ticketMayor)
            {
                ticketMayor = clientesCajero[i][j];
            }
        }
    }

    for (int j = 0; j < n; j++)
    {
        if (clientesCajero[menorcajero][j] == 0)
        {
            ticketMayor++;
            clientesCajero[menorcajero][j] = ticketMayor;
            serviciosAtiendeCajeros[menorcajero][j] = 0;
            *cajeroSeleccionado = menorcajero;
            *posicionCliente = j;
            return ticketMayor;
        }
    }

    return 0;
}

long atenderClienteCajero(int n, int clientesCajero[3][n], int serviciosAtiendeCajero[3][n], int codigoCajero, int *tipoServicio)
{

    if (codigoCajero < 0 || codigoCajero >= 3)
    {
        return -1;
    }
    if (clientesCajero[codigoCajero][0] == 0)
    {
        return 0;
    }
    long ticket = clientesCajero[codigoCajero][0];
    *tipoServicio = serviciosAtiendeCajero[codigoCajero][0];

    for (int j = 0; j < n-1; j++)
    {
        clientesCajero[codigoCajero][j] = clientesCajero[codigoCajero][j + 1];
        serviciosAtiendeCajero[codigoCajero][j] = serviciosAtiendeCajero[codigoCajero][j + 1];
    }
    clientesCajero[codigoCajero][n - 1] = 0;
    serviciosAtiendeCajero[codigoCajero][n - 1] = 0;

    return ticket;
}
void listarTicketsEnEspera(int n, int clientesCajero[3][n], int serviciosAtiendeCajero[3][n])
{
    int totalCliente = 0;

    printf("%50s %s\n", " ", "Tiempo");
    printf("%-15s %s %40s\n", " ", "No.", "En Espera");
    printf("%-15s %-10s %-22s %-1s\n", "Cajero", "Ticket", "Servicio", "(Segundos)");
    printf("---------------------------------------------------------------\n");

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (clientesCajero[i][j] != 0)
            {
                totalCliente++;
                if (j == 0)
                {
                    printf("Cajero No. %-5d", i + 1);
                }
                else
                {
                    printf("%-16s", " ");
                }
                printf("TK-%05d   ", clientesCajero[i][j]);
                printf("%-25s", nombreservicio(serviciosAtiendeCajero[i][j]));
                printf("%-10.2f\n", duracionServicio(n, serviciosAtiendeCajero, i, j));
            }
        }
        printf("\n");
    }
    printf("---------------------------------------------------------------\n");
    printf("Total Clientes En Cola: %d\n", totalCliente);
}
void listarClientesEnCola(int size, int clientesCajero[3][size])
{
    printf("\n%-8s %-17s\n", "Cajero", "Tickets En Cola");
    printf("---------------------------------------------------\n");
    for (int c = 0; c < 3; c++)
    {

        printf("%-10d", c + 1);

        for (int j = 0; j < size; j++)
        {

            if (clientesCajero[c][j] != 0)
            {
                printf("%-5d", clientesCajero[c][j]);
            }
        }
        printf("\n");
    }
    printf("---------------------------------------------------\n");
}

double duracionServicio(int n, int servicio[][n], int cajero, int posicion)
{
    long tiempoEspera = 0;

    for (int i = 0; i < posicion; i++)
    {

        switch (servicio[cajero][i])
        {

        case 1:
            tiempoEspera += 60;
            break;
        case 2:
            tiempoEspera += 120;
            break;
        case 3:
            tiempoEspera += 300;
            break;
        case 4:
            tiempoEspera += 480;
            break;
        case 5:
            tiempoEspera += 90;
            break;
        }
    }
    return tiempoEspera;
}

const char *nombreservicio(int servicio)
{
    switch (servicio)
    {
    case 1:
        return "Deposito";
    case 2:
        return "Retiro";
    case 3:
        return "Apertura de Cuenta";
    case 4:
        return "Solicitud de Prestamo";
    case 5:
        return "Consulta General";
    default:
        return "Desconocido";
    }
}

/*
4
1
1
1
1
1
1
1
1
1
1
1
1
1
1
1
1
1
1
1
1
1
1
1
1
1
1
1
1
1
1
1
1
1
1
1



*/

