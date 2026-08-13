#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

#define ROJO 1
#define AMARILLO 2
#define VERDE 3

#define CARRO 1
#define MOTOCICLETA 2
#define VEHICULO_PESADO 3

#define ACERCANDO 1
#define NO_ACERCANDO 2

#define CRUZO 1
#define NO_CRUZO 2

int scanentero() {
    int n;

    while (scanf("%d", &n) != 1) {
        printf("Solo numeros enteros: ");

        while(getchar() != '\n');
    }

    return n;
}

void listarmatriz(int cambios, int simulado, float porcentaje[], int matrizResultados[][4]){

    printf("\n************** Resultado Simulaci%cn Pase de Veh%cculos **************\n\n", 162, 161);
    printf("\n**************    Veh%cculos Cruzaron el Sem%cforo      **************\n\n", 161, 160);
    printf("Sem%cforo %10s %15s %20s %11s\n", 160, "CARRO", "MOTOCICLETA", "VEHICULO PESADO", "TOTAL");
    printf("---------------------------------------------------------%7s-----\n", " ");

    char *colores[4] = {"","ROJO","AMARILLO","VERDE"};
    int totcol[4] ={0,0,0,0};

    for (int fila = ROJO; fila <= VERDE; fila++){
        int totalFila = 0;
        printf("%-12s", colores[fila]);
        for (int col = CARRO; col <= VEHICULO_PESADO; col++){

            if (col == 1){
                printf("%7d", matrizResultados[fila][col]);
            }
            else if (col == 2){
                printf("%15d", matrizResultados[fila][col]);
            }
            else{
                printf("%22d", matrizResultados[fila][col]);
            }
            totalFila += matrizResultados[fila][col]; // total por semaforo
            totcol[col] += matrizResultados[fila][col]; // total por tipo de vehiculo
        }
        printf("%13d\n", totalFila);
    }

    printf("---------------------------------------------------------%7s-----\n"," ");
    printf("%-12s", "Total:");
    int totalGeneral = 0;
    for (int col = CARRO; col <= VEHICULO_PESADO; col++){

        if (col == 1){
            printf("%7d", totcol[col]);
        }
        else if (col == 2){
            printf("%15d", totcol[col]);
        }
        else{
            printf("%22d", totcol[col]);
        }
        totalGeneral += totcol[col];
    }
    printf("%13d\n", totalGeneral);

    printf("\nEl semaforo cambi%c %d veces\n\n", 162, cambios);
    printf("Cantidad total de veh%cculos simulados %d\n", 161, simulado);

    printf("\nPorcentaje por tipo de veh%cculo que cruzaron en ROJO:\n", 161);
    printf("Carros: %.2f%%\n", porcentaje[CARRO]);
    printf("Motocicletas: %.2f%%\n", porcentaje[MOTOCICLETA]);
    printf("Vehiculos pesados: %.2f%%\n", porcentaje[VEHICULO_PESADO]);

    if (porcentaje[VEHICULO_PESADO] >= porcentaje[MOTOCICLETA] && porcentaje[VEHICULO_PESADO] >= porcentaje[CARRO]){
        if (matrizResultados[ROJO][VEHICULO_PESADO] >= 4 && matrizResultados[ROJO][VEHICULO_PESADO] <= 10){
            printf("se debe incorporar un reductor de velocidad a 300 metros.");
        }
        else if (matrizResultados[ROJO][VEHICULO_PESADO] > 15){
            printf("se deben incorporar 2 reductores, uno a 400 metros y otro a 800 metros antes del sem%cforo.", 160);
        }
    }
    else if (porcentaje[CARRO] >= porcentaje[MOTOCICLETA] && porcentaje[CARRO] >= porcentaje[VEHICULO_PESADO]){
        if (matrizResultados[ROJO][CARRO] >= 7){
            printf("se debe incorporar un reductor de velocidad a 200 metros antes del sem%cforo.", 160);
        }
    }
    else if (porcentaje[MOTOCICLETA] >= porcentaje[VEHICULO_PESADO] && porcentaje[MOTOCICLETA] >= porcentaje[CARRO]){
        if (matrizResultados[ROJO][MOTOCICLETA] >= 4 && matrizResultados[ROJO][MOTOCICLETA] <= 10){
            printf("se debe poner una se%cal de tr%cnsito indicando que hay un sem%cforo a 200 metros.", 164, 160, 160);
        }
        else if (matrizResultados[ROJO][MOTOCICLETA] > 10){
            printf("se debe incorporar un reductor de velocidad a 150 metros antes del sem%cforo.", 160);
        }
    }
}

void sleepy(){
    Sleep(0);
}
long random(int min, int max){
    long numero = 0;
    numero = rand()%(max-min+1)+min;
    return numero;
}

int cambiosemaforo(int numero, int colorAnterior, int *cambios){ 
    char *colores[] = {"","ROJO","AMARILLO","VERDE"};
    int color = 0;
    if (numero >=20 && numero <=30){
        color = ROJO;
    }else if (numero>=31 && numero <=40){
        color = AMARILLO;
    }else if (numero>=41 && numero <=50){
        color = VERDE;
    }

    printf("\nEl semaforo cambio a: %s\n", colores[color]);
    if (color != colorAnterior){
        (*cambios)++;
    }
    sleepy();
    return color;
}
int seleccionartipovehiculo(int numero){
    int tipo = 0;
    char *vehiculos[] = {"","Carro","Motocicleta","Vehiculo Pesado"};

    if (numero >=1 && numero <=4){
        tipo = CARRO;
    }
    else if (numero>=5 && numero <=8){
        tipo = MOTOCICLETA;
    }
    else if (numero>=9 && numero <=12){
        tipo = VEHICULO_PESADO;
    }

    if (tipo !=2){
        printf("\nUn %s se esta acercando", vehiculos[tipo]);
    }else
        printf("\nUna %s se esta acercando", vehiculos[tipo]);

    for(int i = 0; i < 5; i++){
        printf(".");
        sleepy();
    }

    printf("\n");
    sleepy();
    return tipo;
}

int vehiculoacercando(int numero,int *simulado){
    int estado = 0;
    if (numero>=1 && numero<=30){
        estado = ACERCANDO;
        //printf("\nUn veh%cculo se esta acercando\n",161);
        (*simulado)++;
    }else if (numero >=31 && numero <=50){
        printf("\nNingun veh%cculo se esta acercando\n",161);
        estado = NO_ACERCANDO;
    }
    sleepy();
    return estado;
}

int vehiculocruzo(int numero, int color, int tipo, int matrizResultados[4][4]){
    int estado = 0;
    if (color == VERDE){
        estado = CRUZO;
        sleepy();
        matrizResultados[color][tipo]++;
        printf("\nVeh%cculo ha pasado\n",161);
        return estado;
    }
    if (numero >=1 && numero <=4){
        estado = CRUZO;
        if(color == AMARILLO){
            matrizResultados[color][tipo]++;
            printf("\nVeh%cculo ha pasado en AMARILLO,\n%c%c%ctener cuidado de que no pase en ROJO la pr%cxima vez!!!\n",161,173,173,173,162);
        }
        else if(color == ROJO){
            printf("\nVeh%cculo ha pasado en ROJO,\n%c%c%cel mismo debe ser multado!!!\n",161,173,173,173);
            matrizResultados[color][tipo]++;

        }
    }else if (numero>=5 && numero <=8){
        estado = NO_CRUZO;
        printf("\nEl veh%cculo no cruz%c el semaforo\n",161,162);
    }
    sleepy();
    return estado;
}
int main(){

    srand(time(NULL));
    int cantvehiculos = 0;
    int cantiteraciones = 0;
    int numero = 0;
    int color =0;
    int cambios = 0;
    int simulado = 0;
    int matrizResultados[4][4] = {0};
    int estado = 0;
    int tipo = 0;
    printf("Introduzca la cantidad de veh%cculos a simular: ", 161);
    cantvehiculos = scanentero();
    printf("Introduzca cu%cntas iteraciones ser%c cambiado el sem%cforo: ", 160,160,160);
    cantiteraciones = scanentero();
    system("cls");

    printf("Hello World!");
    numero = random(20,50);
    color = cambiosemaforo(numero, color, &cambios);
    

    for(int i = 1; i <= cantvehiculos; i++){

        numero = random(1,50);
        estado = vehiculoacercando(numero, &simulado);
        if (estado == ACERCANDO){
            numero = random(1, 12);
            tipo = seleccionartipovehiculo(numero);
            numero = random(1, 8);
            vehiculocruzo(numero, color, tipo, matrizResultados);
        }
        
        if(i % cantiteraciones == 0){
            numero = random(20,50);
            color = cambiosemaforo(numero, color, &cambios);
        }
    }
    int totalRojo = 0;
    float porcentaje[4] = {0};

    for (int tipo = CARRO; tipo <= VEHICULO_PESADO; tipo++){
        totalRojo += matrizResultados[ROJO][tipo];
    }

    for (int tipo = CARRO; tipo <= VEHICULO_PESADO; tipo++){
        if (totalRojo > 0){
            porcentaje[tipo] = (matrizResultados[ROJO][tipo] * 100.0) / totalRojo;
        }
    }

    listarmatriz(cambios, simulado, porcentaje, matrizResultados);

    return 0;
}