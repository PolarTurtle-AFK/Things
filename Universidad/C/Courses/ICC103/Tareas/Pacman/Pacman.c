#include <stdio.h>
#include <stdlib.h>

#include <math.h>
#include <time.h>

#define JUGADOR '@'
#define FANTASMA 'F'
#define PARED '#'
#define PASTILLA '.'
#define VACIO ' '
#define MUERTO 'x'

#define SPAWN 9
#define CANTFANTASMAS 3
#define CANTPAREDES 6
#define LADO 1
#define ALTURA 8

/*
 * FUNCION: inicializar
 * Inicializa el mapa y coloca los elementos del juego.
 * Recibe: mapa, dimension del mapa, posiciones de los fantasmas,
 *         contenido debajo de los fantasmas y posicion del jugador.
 * Retorna: nada.
 */
void inicializar(char *mapa, int dim,int *posFantamsa, char *debajoFantasma, int *posJugador);

/*
 * FUNCION: mostrar_tablero
 * Muestra el tablero actual en pantalla.
 * Recibe: mapa y dimension del mapa.
 * Retorna: nada.
 */
void mostrar_tablero(char *mapa, int dim);

/*
 * FUNCION: mover_jugador
 * Permite al jugador moverse por el mapa validando las paredes.
 * Recibe: mapa, dimension del mapa, posiciones de los fantasmas
 *         y posicion del jugador.
 * Retorna: nada.
 */
void mover_jugador(char *mapa, int dim, int *posFantasma, int *posJugador);

/*
 * FUNCION: mover_fantasmas
 * Mueve los fantasmas aleatoriamente por el mapa.
 * Recibe: mapa, dimension del mapa, posiciones de los fantasmas,
 *         contenido debajo de los fantasmas y posicion del jugador.
 * Retorna: nada.
 */
void mover_fantasmas(char *mapa, int dim, int *posFantasma, char *debajoFantasma, int *posJugador);

/*
 * FUNCION: verificar_colision
 * Verifica si el jugador colisiono con un fantasma.
 * Recibe: mapa, posiciones de los fantasmas y posicion del jugador.
 * Retorna: 1 si hubo colision y -1 si no hubo colision.
 */
int verificar_colision(char *mapa, int *posFantasma, int *posJugador);

/*
 * FUNCION: condicion_victoria
 * Verifica las condiciones de victoria o derrota del juego.
 * Recibe: mapa, dimension del mapa, posiciones de los fantasmas
 *         y posicion del jugador.
 * Retorna: 0 si el juego continua, 1 si el jugador pierde
 *         y 2 si el jugador gana.
 */
int condicion_victoria(char *mapa, int dim, int *posFantasma, int *posJugador);

/*
 * FUNCION: radar
 * Cuenta la cantidad de fantasmas cercanos al jugador.
 * Recibe: mapa y dimension del mapa.
 * Retorna: nada.
 */
void radar(char *mapa, int dim);

/*
 * FUNCION: radarreinicio
 * Verifica si el jugador esta rodeado por paredes o fantasmas.
 * Recibe: mapa y posicion del jugador.
 * Retorna: -1 si no tiene movimientos disponibles y 67 si puede moverse.
 */
int radarreinicio(char *mapa, int *posJugador);

/*
 * FUNCION: obtener_posicion_jugador
 * Busca la posicion actual del jugador en el mapa.
 * Recibe: mapa y dimension del mapa.
 * Retorna: la posicion del jugador o -1 si no se encuentra.
 */
int obtener_posicion_jugador(char *mapa, int dim);

/*
 * FUNCION: obtener_movimiento
 * Convierte una direccion en el movimiento correspondiente.
 * Recibe: caracter que representa la direccion.
 * Retorna: el movimiento correspondiente o 0 si la direccion es invalida.
 */
int obtener_movimiento(char direccion);

int main() {
    srand(time(NULL));

    int dim = 8;
    char mapa[dim][dim];
    int posJugador;
    int posFantasma[CANTFANTASMAS];
    char debajoFantasma[CANTFANTASMAS];

    inicializar(&mapa[0][0], dim, &posFantasma[0], &debajoFantasma[0], &posJugador);

    while (condicion_victoria(&mapa[0][0], dim, &posFantasma[0], &posJugador) == 0) {
        mover_jugador(&mapa[0][0], dim, &posFantasma[0], &posJugador);
        if (condicion_victoria(&mapa[0][0], dim, &posFantasma[0], &posJugador) != 0)
            break;
        mover_fantasmas(&mapa[0][0], dim, &posFantasma[0], &debajoFantasma[0], &posJugador);
    }

    return 0;
}


void inicializar(char *mapa, int dim, int *posFantasma, char *debajoFantasma, int *posJugador) {
    fflush(stdin);
    int ubicacion, random_ubicacion;

    for (int i = 0; i < dim; i++) {
        for (int j = 0; j < dim; j++) {

            ubicacion = i * dim + j;

            if (i == 0 || i == dim - 1 || j == 0 || j == dim - 1)
                *(mapa + ubicacion) = PARED;
            else
                *(mapa + ubicacion) = PASTILLA;
        }
    }

    for (int fantasmas = 0; fantasmas < CANTFANTASMAS;) {

        random_ubicacion = rand() % (dim * dim);

        if (*(mapa + random_ubicacion) != PARED &&
            *(mapa + random_ubicacion) != FANTASMA &&
            random_ubicacion != SPAWN) {

            *(debajoFantasma + fantasmas) = *(mapa + random_ubicacion);
            *(posFantasma + fantasmas) = random_ubicacion;

            *(mapa + random_ubicacion) = FANTASMA;

            fantasmas++;
        }
    }

    for (int paredes = 0; paredes < CANTPAREDES;) {

        random_ubicacion = rand() % (dim * dim);

        if (*(mapa + random_ubicacion) != PARED &&
            *(mapa + random_ubicacion) != FANTASMA &&
            random_ubicacion != SPAWN) {

            *(mapa + random_ubicacion) = PARED;
            paredes++;
        }
    }

    *(mapa + SPAWN) = JUGADOR;
    *posJugador = SPAWN;

    mostrar_tablero(mapa, dim);
    radar(mapa,dim);
}

void mostrar_tablero(char *mapa, int dim)
{
    system("cls");
    printf("\n");
    for(int f=0;f<dim;f++)
    {
        for(int c=0;c<dim;c++)
        {
            printf("%2c", *(mapa + f * dim +c));
        }
        printf("\n");
    }
}

int condicion_victoria(char *mapa, int dim, int *posFantasma, int *posJugador) {
    int cant_pastillas = 0;
    for (int f = 0; f < dim; f++) {
        for (int c = 0; c < dim; c++) {

            if (*(mapa + f * dim + c) == PASTILLA)
                cant_pastillas++;
            
            if(verificar_colision(mapa,posFantasma, posJugador) == 1){
                mostrar_tablero(mapa,dim);
                radar(mapa,dim);
                printf("\nUn fantasma te atrapo. PERDISTE.");
                return 1;
            }
        }
    }

    if (cant_pastillas == 0) {
        mostrar_tablero(mapa,dim);
        radar(mapa,dim);
        printf("\nTe comiste todas las pastillas. GANASTE!");
        return 2;
    }

    if (radarreinicio(mapa, posJugador) == -1) {
    *(mapa + *posJugador) = MUERTO;
    mostrar_tablero(mapa, dim);
    printf("\nNo tienes movimientos posibles. PERDISTE.");
    return 1;
}

    return 0;
}

int obtener_posicion_jugador(char *mapa, int dim) {
    for (int i = 0; i < dim; i++) {
        for (int j = 0; j < dim; j++) {
            if (*(mapa + i * dim + j) == JUGADOR)
                return i * dim + j;
        }
    }

    return -1;
}

int obtener_movimiento(char direccion) {
    if (direccion == 'a') return -LADO;
    if (direccion == 'd') return LADO;
    if (direccion == 'w') return -ALTURA;
    if (direccion == 's') return ALTURA;
    return 0;
}

void mover_jugador(char *mapa, int dim, int *posFantasma, int *posJugador) {

    char direccion;
    int ubicacion_jugador;
    int movimiento;
    int nueva_ubicacion;

    do {
        printf("\nDigite donde te vas a mover [a, w, s, d]: ");
        scanf(" %c", &direccion);

        movimiento = obtener_movimiento(direccion);

        if (movimiento == 0) {
            printf("\nDireccion invalida.");
            continue;
        }

        ubicacion_jugador = obtener_posicion_jugador(mapa, dim);
        nueva_ubicacion = ubicacion_jugador + movimiento;

        if (*(mapa + nueva_ubicacion) == PARED) {
            printf("\nLa direccion elegida es un muro. Escriba otra.");
        } else {
            *(mapa + nueva_ubicacion) = JUGADOR;
            *(mapa + ubicacion_jugador) = VACIO;
            *posJugador = nueva_ubicacion;
            return;
        }
    verificar_colision(mapa,posFantasma, posJugador);
    } while (1);
}

void mover_fantasmas(char *mapa, int dim, int *posFantasma, char *debajoFantasma,int *posJugador) {

    verificar_colision(mapa,posFantasma, posJugador);

    for (int fantasma = 0; fantasma < CANTFANTASMAS; fantasma++) {

        int ubicacion_fantasma = *(posFantasma + fantasma);
        int nueva_ubicacion;
        int movimiento = rand() % 5;
        if (movimiento == 0)
            nueva_ubicacion = ubicacion_fantasma - 1;
        else if (movimiento == 1)
            nueva_ubicacion = ubicacion_fantasma + 1;
        else if (movimiento == 2)
            nueva_ubicacion = ubicacion_fantasma - dim;
        else if (movimiento == 3)
            nueva_ubicacion = ubicacion_fantasma + dim;
        else if (movimiento == 4)
            nueva_ubicacion = ubicacion_fantasma;

        if (*(mapa + nueva_ubicacion) != PARED && *(mapa + nueva_ubicacion) != FANTASMA) {

            *(mapa + ubicacion_fantasma) = *(debajoFantasma + fantasma);
            *(debajoFantasma + fantasma) = *(mapa + nueva_ubicacion);
            *(mapa + nueva_ubicacion) = FANTASMA;
            *(posFantasma + fantasma) = nueva_ubicacion;
        }
    }

    verificar_colision(mapa,posFantasma, posJugador);
    mostrar_tablero(mapa,dim);
    radar(mapa,dim);
    radarreinicio(mapa,posJugador);

}

int verificar_colision(char *mapa, int *posFantasma,int *posJugador)
{
    for (int i = 0; i < CANTFANTASMAS; i++){
        if (*(posFantasma+i) == *posJugador){
            *(mapa+*posJugador) = MUERTO;
            return 1;
        }
    }
    return -1;
}

void radar(char *mapa, int dim)
{
    int contadorfantasma = 0;
    int posicionJugador = obtener_posicion_jugador(mapa, dim);

    int filaJugador = posicionJugador / dim;
    int columnaJugador = posicionJugador % dim;

    for (int i = filaJugador - LADO; i <= filaJugador + LADO; i++)
    {

        for (int j = columnaJugador - LADO; j <= columnaJugador + LADO; j++)
        {
            if (*(mapa + i * dim + j) == FANTASMA)
            contadorfantasma++;

        }
    }
    printf("\n Fantasmas cerca: %d \n", contadorfantasma);
}

int radarreinicio(char *mapa, int *posJugador)
{
    int contaconta = 0;
    int posjugador = *posJugador;

    if (*(mapa + posjugador - LADO) == PARED ||
        *(mapa + posjugador - LADO) == FANTASMA)
        contaconta++;

    if (*(mapa + posjugador + LADO) == PARED ||
        *(mapa + posjugador + LADO) == FANTASMA)
        contaconta++;

    if (*(mapa + posjugador - ALTURA) == PARED ||
        *(mapa + posjugador - ALTURA) == FANTASMA)
        contaconta++;

    if (*(mapa + posjugador + ALTURA) == PARED ||
        *(mapa + posjugador + ALTURA) == FANTASMA)
        contaconta++;

    if (contaconta == 4)
        return -1;

    return 1;
}