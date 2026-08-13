#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <windows.h>

#define MAX_CLIENTES  500
#define MAX_VEHICULOS 500
#define MAX_HISTORIAL 500















// =========================================================================
// PAUSA DE PANTALLA
// =========================================================================
void pausar(void) {
    printf("Presione ENTER para continuar...");
    getchar();
}
// =========================================================================
// UTILIDADES
// =========================================================================
int leerEnteroRango(const char *mensaje, int min, int max) {
    int num;
    char buffer[100];
    while (1) {
        printf("%s", mensaje);
        if (fgets(buffer, sizeof(buffer), stdin) == NULL) continue;
        buffer[strcspn(buffer, "\n")] = '\0';
        if (strlen(buffer) == 0) {
            printf("Debe introducir un valor num%crico!!\n", 130); // é
            continue;
        }
        if (sscanf(buffer, "%d", &num) != 1) {
            printf("Debe introducir un valor num%crico!!\n", 130);
            continue;
        }
        if (num >= min && num <= max) return num;
        printf("Error: El valor debe estar entre %d y %d.\n", min, max);
    }
}

float leerFloatRango(const char *mensaje, float min, float max) {
    float num;
    char buffer[100];
    while (1) {
        printf("%s", mensaje);
        if (fgets(buffer, sizeof(buffer), stdin) == NULL) continue;
        buffer[strcspn(buffer, "\n")] = '\0';
        if (strlen(buffer) == 0) {
            printf("Debe introducir un valor num%crico!!\n", 130);
            continue;
        }
        if (sscanf(buffer, "%f", &num) != 1) {
            printf("Debe introducir un valor num%crico!!\n", 130);
            continue;
        }
        if (num >= min && num <= max) return num;
        printf("Error: El valor debe estar entre %.2f y %.2f.\n", min, max);
    }
}

void leerCadenaNoVacia(const char *mensaje, char *destino, int tamanio) {
    while (1) {
        printf("%s", mensaje);
        if (fgets(destino, tamanio, stdin) == NULL) continue;
        destino[strcspn(destino, "\n")] = '\0';
        if (strlen(destino) > 0) break;
        printf("Error: No puede estar vac%co.\n", 161); // í
    }
}

int leerSiNo(const char *mensaje) {
    char buffer[10];
    while (1) {
        printf("%s", mensaje);
        if (fgets(buffer, sizeof(buffer), stdin) == NULL) continue;
        buffer[strcspn(buffer, "\n")] = '\0';
        if (strlen(buffer) == 0) {
            printf("Error: No puede estar vac%co.\n", 161);
            continue;
        }
        char c = toupper(buffer[0]);
        if (c == 'S' || c == 'N') return c;
        printf("Error: Solo S o N.\n");
    }
}

// =========================================================================
// VALIDACIONES
// =========================================================================
int validarPlaca(char placa[]) {
    if (strlen(placa) == 0) return 0;
    for (int i = 0; placa[i]; i++)
        if (!isalnum((unsigned char)placa[i])) return 0;
    return 1;
}

int validarNombre(char nombre[]) {
    int i;

    if (strlen(nombre) == 0)
        return 0;

    for (i = 0; nombre[i] != '\0'; i++) {
        unsigned char c = (unsigned char)nombre[i];

        if ((c >= 'A' && c <= 'Z') ||      // Letras mayúsculas
            (c >= 'a' && c <= 'z') ||      // Letras minúsculas
            c == ' ' ||                    // Espacio
            c == 160 || c == 130 || c == 161 || c == 162 || c == 163 || // á é í ó ú
            c == 181 || c == 144 || c == 214 || c == 224 || c == 233 || // Á É Í Ó Ú
            c == 164 || c == 165)          // ñ Ñ
        {
            continue;
        }

        return 0;
    }

    return 1;
}

int compararSinMayus(const char *a, const char *b) {
    while (*a && *b) {
        char ca = tolower((unsigned char)*a);
        char cb = tolower((unsigned char)*b);
        if (ca != cb) return ca - cb;
        a++; b++;
    }
    return tolower((unsigned char)*a) - tolower((unsigned char)*b);
}

int placaRepetida(char placas[][20], int cantidad, char placa[]) {
    for (int i = 0; i < cantidad; i++)
        if (compararSinMayus(placas[i], placa) == 0) return 1;
    return 0;
}

int choferRepetido(char choferes[][50], int cantidad, char chofer[]) {
    for (int i = 0; i < cantidad; i++)
        if (compararSinMayus(choferes[i], chofer) == 0) return 1;
    return 0;
}

int usuarioRepetido(char usuarios[][50], int cantidad, char usuario[]) {
    for (int i = 0; i < cantidad; i++)
        if (compararSinMayus(usuarios[i], usuario) == 0) return 1;
    return 0;
}

int buscarUsuarioIndex(char usuarios[][50], int cantidad, char usuario[]) {
    for (int i = 0; i < cantidad; i++)
        if (compararSinMayus(usuarios[i], usuario) == 0) return i;
    return -1;
}

int generarPosicion(int min, int max) {
    return min + rand() % (max - min + 1);
}

// =========================================================================
// CONFIGURACION
// =========================================================================
void configurarSistema(int *configurado, int *cli_min, int *cli_max, int *veh_min, int *veh_max,
                       float *costo_recogida, float *costo_viaje) {
    char msg[100];
    sprintf(msg, "Distancia m%cnima cliente: ", 161); // í
    *cli_min = leerEnteroRango(msg, 0, 1000);
    sprintf(msg, "Distancia m%cxima cliente: ", 160); // á
    *cli_max = leerEnteroRango(msg, *cli_min + 1, 5000);
    sprintf(msg, "Distancia m%cnima veh%cculo: ", 161, 161);
    *veh_min = leerEnteroRango(msg, 0, 1000);
    sprintf(msg, "Distancia m%cxima veh%cculo: ", 160, 161);
    *veh_max = leerEnteroRango(msg, *veh_min + 1, 5000);
    sprintf(msg, "Costo por kil%cmetro de recogida: ", 162); // ó
    *costo_recogida = leerFloatRango(msg, 1.0, 500.0);
    sprintf(msg, "Costo por kil%cmetro del viaje: ", 162);
    *costo_viaje = leerFloatRango(msg, 1.0, 500.0);
    *configurado = 1;
}

// =========================================================================
// REGISTROS
// =========================================================================
void registrarVehiculo(char placas[][20], char choferes[][50], char estados[],
                       float puntos[], float promedios[], int viajes[],
                       float kilometros[], float dinero[],
                       int *cantidad, int maximo) {
    if (*cantidad >= maximo) {
        printf("\nError: Se alcanz%c el l%cmite configurado de veh%cculos (%d).\n", 162, 161, 161, maximo);
        pausar();
        return;
    }
    char placa[20], chofer[50];
    printf("Introduzca los datos del veh%cculo no. %d:\n\n", 161, *cantidad + 1);

    while (1) {
        leerCadenaNoVacia("No. Placa: ", placa, sizeof(placa));
        if (!validarPlaca(placa)) {
            printf("Error: Solo letras y n%cmeros.\n", 163); // ú
            continue;
        }
        if (placaRepetida(placas, *cantidad, placa)) {
            printf("Error: Placa ya registrada.\n");
            continue;
        }
        break;
    }

    while (1) {
        leerCadenaNoVacia("Nombre Chofer: ", chofer, sizeof(chofer));
        if (!validarNombre(chofer)) {
            printf("Error: Solo letras y espacios.\n");
            continue;
        }
        if (choferRepetido(choferes, *cantidad, chofer)) {
            printf("Error: Chofer ya registrado.\n");
            continue;
        }
        break;
    }

    char msg[50];
    sprintf(msg, "Veh%cculo Activo (S/N): ", 161);
    char estado = leerSiNo(msg);

    strcpy(placas[*cantidad], placa);
    strcpy(choferes[*cantidad], chofer);
    estados[*cantidad] = estado;
    puntos[*cantidad] = 0;
    promedios[*cantidad] = 0;
    viajes[*cantidad] = 0;
    kilometros[*cantidad] = 0;
    dinero[*cantidad] = 0;
    (*cantidad)++;
    printf("\nVeh%cculo registrado correctamente.\n", 161);
    pausar();
}

void registrarClientes(char usuarios[][50], char nombres[][50], int metodosPago[],
                       int *cantidadClientes, int maxClientes) {
    if (*cantidadClientes >= maxClientes) {
        printf("\nError: Se alcanz%c el l%cmite configurado de clientes (%d).\n", 162, 161, maxClientes);
        pausar();
        return;
    }
    char usuario[50], nombre[50];
    printf("\nIntroduzca los datos del cliente no. %d:\n\n", *cantidadClientes + 1);

    while (1) {
        leerCadenaNoVacia("Usuario: ", usuario, sizeof(usuario));
        if (usuarioRepetido(usuarios, *cantidadClientes, usuario)) {
            printf("Usuario existe en un registro anterior!\n");
            continue;
        }
        break;
    }

    while (1) {
        leerCadenaNoVacia("Nombre: ", nombre, sizeof(nombre));
        if (validarNombre(nombre)) break;
        printf("Error: Solo letras y espacios.\n");
    }

    char msg[100];
    sprintf(msg, "M%ctodo Pago (1-> Efectivo, 2 -> Tarjeta ): ", 130); // é
    metodosPago[*cantidadClientes] = leerEnteroRango(msg, 1, 2);
    strcpy(usuarios[*cantidadClientes], usuario);
    strcpy(nombres[*cantidadClientes], nombre);
    (*cantidadClientes)++;
    printf("\nCliente registrado correctamente.\n");
    pausar();
}

// =========================================================================
// LISTADOS
// =========================================================================
void listarVehiculos(char placas[][20], char choferes[][50], char estados[], int cantidad) {
    if (cantidad == 0) {
        printf("\nNo hay veh%cculos registrados.\n", 161);
        pausar();
        return;
    }
    printf("\n******************** V E H I C U L O S   R E G I S T R A D O S ********************\n");
    printf("%-15s %-20s\n", "No.", "Nombre");
    printf("%-15s %-20s %10s\n", "Placa", "Chofer", "Activo");
    printf("---------------------------------------------------------------\n");
    for (int i = 0; i < cantidad; i++) {
        printf("%-15s %-20s %10c\n", placas[i], choferes[i], estados[i]);
    }
    printf("---------------------------------------------------------------\n");
    printf("%-15s %-20d\n", "Total:", cantidad);
    pausar();
}

void listarClientes(char usuarios[][50], char nombres[][50], int metodosPago[], int cantidad) {
    if (cantidad == 0) {
        printf("\nNo hay clientes registrados.\n");
        pausar();
        return;
    }
    printf("\n******************** CLIENTES REGISTRADOS ********************\n");
    printf("---------------------------------------------------------------\n");
    char metodo[12];
    sprintf(metodo, "M%ctodo Pago", 130);
    printf("%-12s %-20s %-12s\n", "Usuario", "Nombre", metodo);
    for (int i = 0; i < cantidad; i++) {
        printf("%-12s %-20s %-12s\n",
               usuarios[i],
               nombres[i],
               metodosPago[i] == 1 ? "Efectivo" : "Tarjeta");
    }
    printf("---------------------------------------------------------------\n");
    printf("%-12s %-20d\n", "Total:", cantidad);
    pausar();
}
;
// =========================================================================
// LOGICA DE VIAJE
// =========================================================================
int seleccionarVehiculo(char estados[], float promedios[], int viajes[], int posVehiculos[],
                        int posCliente, int vehiculos_registrados, int *distanciaRecogidaGanador) {
    int mejor = -1, menorDist = -1, menorViajes = -1;
    float mejorProm = -1.0;
    for (int i = 0; i < vehiculos_registrados; i++) {
        if (estados[i] != 'S') continue;
        int dist = abs(posVehiculos[i] - posCliente);
        if (mejor == -1 || dist < menorDist) {
            mejor = i; menorDist = dist; mejorProm = promedios[i]; menorViajes = viajes[i];
            *distanciaRecogidaGanador = dist;
        } else if (dist == menorDist) {
            if (promedios[i] > mejorProm) {
                mejor = i; mejorProm = promedios[i]; menorViajes = viajes[i];
                *distanciaRecogidaGanador = dist;
            } else if (promedios[i] == mejorProm && viajes[i] < menorViajes) {
                mejor = i; menorViajes = viajes[i];
                *distanciaRecogidaGanador = dist;
            }
        }
    }
    return mejor;
}

int calcularTiempo(int distanciaRecogida, int clima) {
    if (distanciaRecogida == 0) return 2;
    float vel = (clima == 1) ? 30.0f : 20.0f;
    return (int)((distanciaRecogida / vel) * 60);
}

float calcularCosto(int distanciaRecogida, int distanciaViaje,
                    float costo_recogida, float costo_viaje, int clima) {
    float subtotal = 100.0f + (distanciaRecogida * costo_recogida) + (distanciaViaje * costo_viaje);
    return (clima == 2) ? subtotal * 1.20f : subtotal;
}

void mostrarVehiculosEvaluados(char placas[][20], char choferes[][50], char estados[],
                               float promedios[], int viajes[], int posVehiculos[],
                               int posCliente, int vehiculos_registrados, int ganador) {
    char titulo[80];
    sprintf(titulo, "TOP 4 Veh%cculos Encontrados:", 161);
    printf("\n================ %s ================\n", titulo);
    printf("%-11s %11s %12s %15s %11s\n","No.", "Distancia", "Distancia", "Puntuacion", "Cantidad");
    char veh[10];
    sprintf(veh, "Veh%cculo", 161);
    printf("%-11s %11s %12s %15s %11s","Placa", veh, "Recogida", "Promedio", "Viajes");
    printf("\n-----------------------------------------------------------------\n");

    int indices[MAX_VEHICULOS];
    int distRecogida[MAX_VEHICULOS];
    int cantidadActivos = 0;
    for (int i = 0; i < vehiculos_registrados; i++) {
        if (estados[i] != 'S') continue;
        indices[cantidadActivos] = i;
        distRecogida[cantidadActivos] = abs(posVehiculos[i] - posCliente);
        cantidadActivos++;
    }

    for (int i = 0; i < cantidadActivos - 1; i++) {
        for (int j = 0; j < cantidadActivos - 1 - i; j++) {
            int a = indices[j], b = indices[j + 1];
            int intercambiar = 0;
            if (distRecogida[j] > distRecogida[j + 1]) {
                intercambiar = 1;
            } else if (distRecogida[j] == distRecogida[j + 1]) {
                if (promedios[a] < promedios[b]) {
                    intercambiar = 1;
                } else if (promedios[a] == promedios[b] && viajes[a] > viajes[b]) {
                    intercambiar = 1;
                }
            }
            if (intercambiar) {
                int tmpIdx = indices[j]; indices[j] = indices[j + 1]; indices[j + 1] = tmpIdx;
                int tmpDist = distRecogida[j]; distRecogida[j] = distRecogida[j + 1]; distRecogida[j + 1] = tmpDist;
            }
        }
    }

    int limite = (cantidadActivos < 4) ? cantidadActivos : 4;
    for (int k = 0; k < limite; k++) {
        int i = indices[k];
        printf("%-11s %11.2f %12d %15.2f %11.2f\n",
               placas[i],
               (float)posVehiculos[i],
               distRecogida[k],
               promedios[i],
               (float)viajes[i]);
    }
    printf("-----------------------------------------------------------------\n");
}

void mostrarResumenViaje(char nombreCliente[], char placa[], char chofer[],
                         int distanciaRecogida, int distanciaViaje, int clima, float costo, int tiempo, int metodoPago) {
    printf("\n========= RESUMEN DEL VIAJE ==========\n");
    printf("Cliente: %s\n", nombreCliente);
    printf("M%ctodo Pago: %s\n", 130, metodoPago == 1 ? "Efectivo" : "Tarjeta");
    printf("Chofer asignado: %s\n", chofer);
    printf("Placa: %s\n", placa);
    printf("Clima: %s\n", clima == 1 ? "Soleado" : "Lluvioso");
    printf("Distancia del veh%cculo al cliente: %d.00 KMs\n", 161, distanciaRecogida);
    printf("Distancia del viaje: %d.00 KMs\n", distanciaViaje);
    printf("Tiempo estimado de espera: %d.00 minutos\n", tiempo);
    printf("Costo estimado: RD$%.2f\n", costo);
}

int confirmarViaje(void) {
    char msg[60];
    sprintf(msg, "%cDesea confirmar el viaje? (S/N): ", 168); // ¿
    return leerSiNo(msg);
}

void actualizarEstadisticas(float puntos[], float promedios[], int viajes[],
                            float kilometros[], float dinero[], int ganador,
                            int distanciaRecogida, int distanciaViaje, float costo,
                            float *puntuacionDada) {
    float puntaje;
    while (1) {
        printf("Favor otorgar puntuaci%cn al chofer(1-5): ", 162); // ó
        char buf[10];
        if (fgets(buf, sizeof(buf), stdin) == NULL) continue;
        buf[strcspn(buf, "\n")] = '\0';
        if (strlen(buf) == 0) {
            printf("Error: No puede estar vac%co.\n", 161);
            continue;
        }
        if (sscanf(buf, "%f", &puntaje) != 1) {
            printf("Error: Debe ser un n%cmero.\n", 163);
            continue;
        }
        if (puntaje >= 1.0 && puntaje <= 5.0) break;
        printf("Error: La puntuaci%cn debe estar entre 1 y 5.\n", 162);
    }
    *puntuacionDada = puntaje;
    puntos[ganador] += puntaje;
    viajes[ganador] += 1;
    kilometros[ganador] += (distanciaRecogida + distanciaViaje);
    dinero[ganador] += costo;
    promedios[ganador] = puntos[ganador] / viajes[ganador];
}


void guardarHistorial(char nombreCliente[], char placa[], char chofer[],
                      int distanciaRecogida, int distanciaViaje, int clima, float costo, int tiempo,
                      float puntuacion, int metodoPago, int *hist_cantidad,
                      char histClientes[][50], char histPlacas[][20], char histChoferes[][50],
                      int histDistanciaRecogida[], int histDistanciaViaje[],
                      int histClima[], float histCosto[], int histTiempo[],
                      float histPuntuacion[], int histMetodoPago[]) {
    if (*hist_cantidad >= MAX_HISTORIAL) {
        printf("\nAdvertencia: Historial lleno.\n");
        return;
    }
    int idx = *hist_cantidad;
    strcpy(histClientes[idx], nombreCliente);
    strcpy(histPlacas[idx], placa);
    strcpy(histChoferes[idx], chofer);
    histDistanciaRecogida[idx] = distanciaRecogida;
    histDistanciaViaje[idx] = distanciaViaje;
    histClima[idx] = clima;
    histCosto[idx] = costo;
    histTiempo[idx] = tiempo;
    histPuntuacion[idx] = puntuacion;
    histMetodoPago[idx] = metodoPago;
    (*hist_cantidad)++;
}

void filtrarestadisticas (char histClientes[][50], int viajes[], float dinero[], int *hist_cantidad, int histClima[]) {

    char filtrar[50];
    leerCadenaNoVacia("Filtrar Letras Nombre: ", filtrar, sizeof(filtrar));
    if (strcmp(filtrar, "") == 0) {
        printf("no puede estar vac%co.\n", 161);
        return;
    }else{
        printf("%-15s %-20s %-10s %-12s\n", "Cliente", "Cantidad de viajes", "Clima", "Costos Total");
        for (int i = 0; i < *hist_cantidad; i++) {
            for (int j = 0; j < strlen(filtrar); j++) {
                if (tolower(histClientes[i][j]) != tolower(filtrar[j])) {
                    break;
                }
                if (j == strlen(filtrar) - 1) {
                    printf("%-15s %-20d %-10s %-12.2f\n", histClientes[i], viajes[i], (histClima[i] == 1 ? "Soleado" : "Lluvioso"), dinero[i]);
                }
            }
        }
    }
    pausar();

}
void procesarViaje(char usuarios[][50], char nombres[][50],
                   char placas[][20], char choferes[][50], char estados[],
                   float puntos[], float promedios[], int viajes[],
                   float kilometros[], float dinero[],
                   int vehiculos_registrados, int clientes_registrados,
                   int cli_min, int cli_max, int veh_min, int veh_max,
                   float costo_recogida, float costo_viaje,
                   int metodosPago[], int *hist_cantidad,
                   char histClientes[][50], char histPlacas[][20], char histChoferes[][50],
                   int histDistanciaRecogida[], int histDistanciaViaje[],
                   int histClima[], float histCosto[], int histTiempo[],
                   float histPuntuacion[], int histMetodoPago[]) {
    char usr[50];
    printf("\nSolicitar viaje\n");
    leerCadenaNoVacia("Introduzca su Usuario: ", usr, sizeof(usr));
    int idx = buscarUsuarioIndex(usuarios, clientes_registrados, usr);
    if (idx == -1) {
        printf("Usuario no existe.\n");
        char res = leerSiNo("¿Desea reintentar? (S/N): ");
        if (res == 'N') {
            printf("\nViaje cancelado.\n");
            pausar();
            return;
        }else {
            procesarViaje(usuarios, nombres, placas, choferes, estados,
                          puntos, promedios, viajes, kilometros, dinero,
                          vehiculos_registrados, clientes_registrados,
                          cli_min, cli_max, veh_min, veh_max,
                          costo_recogida, costo_viaje,
                          metodosPago, hist_cantidad,
                          histClientes, histPlacas, histChoferes,
                          histDistanciaRecogida, histDistanciaViaje,
                          histClima, histCosto, histTiempo,
                          histPuntuacion, histMetodoPago);
            return;
        }
    }
    int clima = leerEnteroRango("Introduzca Clima (1-> Soleado, 2-> Lluvioso): ", 1, 2);
    int distViaje = leerEnteroRango("Introduzca Distancia Viaje: ", 1, 1000);

    int posCliente = generarPosicion(cli_min, cli_max);
    int posVehiculos[MAX_VEHICULOS];
    for (int i = 0; i < vehiculos_registrados; i++) {
        if (estados[i] == 'S') posVehiculos[i] = generarPosicion(veh_min, veh_max);
        else posVehiculos[i] = 0;
    }

    int distRecogida;
    int ganador = seleccionarVehiculo(estados, promedios, viajes, posVehiculos,
                                      posCliente, vehiculos_registrados, &distRecogida);
    if (ganador == -1) {
        printf("\nNo hay veh%cculos activos disponibles.\n", 161);
        pausar();
        return;
    }

    char msg[80];
    sprintf(msg, "%cDesea listar los veh%cculos evaluados (S/N)?: ", 168, 161);
    char ver = leerSiNo(msg);
    if (ver == 'S')
        mostrarVehiculosEvaluados(placas, choferes, estados, promedios, viajes,
                                  posVehiculos, posCliente, vehiculos_registrados, ganador);

    int tiempo = calcularTiempo(distRecogida, clima);
    float costo = calcularCosto(distRecogida, distViaje, costo_recogida, costo_viaje, clima);

    mostrarResumenViaje(nombres[idx], placas[ganador], choferes[ganador],
                        distRecogida, distViaje, clima, costo, tiempo, metodosPago[idx]);

    if (confirmarViaje() == 'S') {
        printf("Viaje registrado exitosamente!\n");
        float puntDada;
        actualizarEstadisticas(puntos, promedios, viajes, kilometros, dinero,
                               ganador, distRecogida, distViaje, costo, &puntDada);
        guardarHistorial(nombres[idx], placas[ganador], choferes[ganador],
                         distRecogida, distViaje, clima, costo, tiempo, puntDada,
                         metodosPago[idx], hist_cantidad,
                         histClientes, histPlacas, histChoferes,
                         histDistanciaRecogida, histDistanciaViaje,
                         histClima, histCosto, histTiempo,
                         histPuntuacion, histMetodoPago);
    } else {
        printf("\nViaje cancelado.\n");
    }
    pausar();
}

// =========================================================================
// HISTORIAL
// =========================================================================
void mostrarHistorial(int hist_cantidad,
                      char histClientes[][50], char histPlacas[][20], char histChoferes[][50],
                      int histDistanciaRecogida[], int histDistanciaViaje[],
                      int histClima[], float histCosto[], int histTiempo[],
                      float histPuntuacion[], int histMetodoPago[]) {
    if (hist_cantidad == 0) {
        printf("\nNo hay viajes registrados.\n");
        pausar();
        return;
    }
    char colMetodo[10], colPuntuacion[12];
    sprintf(colMetodo, "M%ctodo", 130);
    sprintf(colPuntuacion, "Puntuaci%cn", 162);
    printf("%7s %-12s %-26s %-26s %-11s %11s %12s %10s %12s\n",
           "No.", "No.", " ", " ", " ", "Distancia", "Costo", colMetodo, colPuntuacion);
    printf("%7s %-12s %-26s %-26s %-11s %11s %12s %10s %12s\n",
           "Viaje", "Placa", "Chofer", "Cliente", "Clima", "Recorrida", "Viaje", "Pago", "Recibida");
    printf("---------------------------------------------------------------------------------------------------------------------------------------\n");
    for (int i = 0; i < hist_cantidad; i++) {
        printf("%7d %-12s %-26s %-26s %-11s %11.2f %12.2f %10s %12.2f\n",
               i + 1,
               histPlacas[i],
               histChoferes[i],
               histClientes[i],
               histClima[i] == 1 ? "Soleado" : "Lluvioso",
               (float)histDistanciaViaje[i],
               histCosto[i],
               histMetodoPago[i] == 1 ? "Efectivo" : "Tarjeta",
               histPuntuacion[i]);
    }
    printf("---------------------------------------------------------------------------------------------------------------------------------------\n");
    pausar();
}

// =========================================================================
// MAIN
// =========================================================================
int main() {

    srand((unsigned int)time(NULL));

    char msg[100];
    sprintf(msg, "L%cmite m%cximo de clientes a registrar (1-500): ", 161, 160);
    int cant_clientes = leerEnteroRango(msg, 1, MAX_CLIENTES);
    sprintf(msg, "L%cmite m%cximo de veh%cculos a registrar (1-500): ", 161, 160, 161);
    int cant_vehiculos = leerEnteroRango(msg, 1, MAX_VEHICULOS);

    int configurado = 0;
    int cli_min = 1, cli_max = 20, veh_min = 1, veh_max = 10;
    float costo_recogida = 15.0, costo_viaje = 30.0;

    char placas[MAX_VEHICULOS][20], choferes[MAX_VEHICULOS][50], estados[MAX_VEHICULOS];
    float puntos[MAX_VEHICULOS], promedios[MAX_VEHICULOS], kilometros[MAX_VEHICULOS], dinero[MAX_VEHICULOS];
    int viajes[MAX_VEHICULOS];
    int vehiculos_registrados = 0;

    char usuarios[MAX_CLIENTES][50], nombres[MAX_CLIENTES][50];
    int metodosPago[MAX_CLIENTES];
    int clientes_registrados = 0;

    int hist_cantidad = 0;
    char histClientes[MAX_HISTORIAL][50], histPlacas[MAX_HISTORIAL][20], histChoferes[MAX_HISTORIAL][50];
    int histDistanciaRecogida[MAX_HISTORIAL], histDistanciaViaje[MAX_HISTORIAL];
    int histClima[MAX_HISTORIAL], histTiempo[MAX_HISTORIAL], histMetodoPago[MAX_HISTORIAL];
    float histCosto[MAX_HISTORIAL], histPuntuacion[MAX_HISTORIAL];

    int opcion;
    do {
        system("cls");
        printf("******************** PUCMM RIDE *********************\n");
        printf("1. Configuraciones\n");
        printf("2. Registrar Veh%cculos\n", 161);
        printf("3. Registrar Clientes\n");
        printf("4. Solicitar Viaje\n");
        printf("5. Listar Veh%cculos Registrados\n", 161);
        printf("6. Listar Clientes Registrados\n");
        printf("7. Historial Viaje\n");
        printf("8. Salir\n");
        printf("9. Filtrar Estadisticas\n");
        printf("Seleccione Opci%cn: ", 162);
        opcion = leerEnteroRango("", 1, 9); 

        if (!configurado && opcion == 4) {
            printf("\nError: Debe configurar el sistema primero (Opci%cn 1).\n", 162);
            pausar();
            continue;
        }

        switch (opcion) {
            case 1:
                configurarSistema(&configurado, &cli_min, &cli_max, &veh_min, &veh_max,
                                  &costo_recogida, &costo_viaje);
                break;
            case 2:
                registrarVehiculo(placas, choferes, estados, puntos, promedios, viajes,
                                  kilometros, dinero, &vehiculos_registrados, cant_vehiculos);
                break;
            case 3:
                registrarClientes(usuarios, nombres, metodosPago, &clientes_registrados, cant_clientes);
                break;
            case 4:
                if (clientes_registrados == 0 || vehiculos_registrados == 0) {
                    printf("\nError: Necesita al menos 1 cliente y 1 veh%cculo.\n", 161);
                    pausar();
                } else {
                    procesarViaje(usuarios, nombres, placas, choferes, estados,
                                  puntos, promedios, viajes, kilometros, dinero,
                                  vehiculos_registrados, clientes_registrados,
                                  cli_min, cli_max, veh_min, veh_max,
                                  costo_recogida, costo_viaje,
                                  metodosPago, &hist_cantidad,
                                  histClientes, histPlacas, histChoferes,
                                  histDistanciaRecogida, histDistanciaViaje,
                                  histClima, histCosto, histTiempo,
                                  histPuntuacion, histMetodoPago);
                }
                break;
            case 5:
                listarVehiculos(placas, choferes, estados, vehiculos_registrados);
                break;
            case 6:
                listarClientes(usuarios, nombres, metodosPago, clientes_registrados);
                break;
            case 7:
                mostrarHistorial(hist_cantidad, histClientes, histPlacas, histChoferes,
                                 histDistanciaRecogida, histDistanciaViaje,
                                 histClima, histCosto, histTiempo,
                                 histPuntuacion, histMetodoPago);
                break;
            case 8:
                printf("\nSaliendo del sistema...\n");
                break;
            case 9:
                filtrarestadisticas(histClientes, viajes, dinero, &hist_cantidad, histClima);
                break;
                
            
        }
    } while (opcion != 8);

    return 0;
}