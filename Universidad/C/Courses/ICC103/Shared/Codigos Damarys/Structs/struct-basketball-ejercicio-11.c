/*
Se desea registrar los datos de los torneos de basketball. Tomando en cuenta lo siguientes
atributos y entidades pertenecientes al torneo:

a) Equipo: identificador (3 caracteres); Nombre (40 caracteres); Siglas (15 caracteres);
cantidad juegos jugados, ganados y perdidos (enteros);Fecha de ingreso al torneo
(CREAR ESTRUCTURA FECHA)

b) Jugador: identificador del equipo donde juega (3 caracteres); cédula de identidad y
electoral (11 caracteres); Nombre (50 caracteres); Fecha de ingreso al equipo
(FECHA);Cantidad de asistencias, bolas robadas, puntos de dos, puntos de tres,
puntos de la línea de tiros libres (enteros)

c) Partido: Identificador del partido (3 caracteres); Identificador equipo local ;
identificador equipo visitante; Fecha del partido (FECHA)

Se desea:
a) Que exprese estas entidades en forma de estructuras de datos en C

b) Los jugadores se guardan en un arreglo de jugadores de 24 (12 por cada equipo). Se desea
realizar una función que retorne la posición donde se encuentra el jugador con más puntos
dentro del arreglo de jugadores, tome como argumento: un puntero a una estructura
jugador, con el que se manejará los jugadores; un entero que indicará la cantidad de
jugadores a evaluar.

*/
#include<stdio.h>
#include<stdlib.h>

typedef struct
{
    int dia;
    int mes;
    int agno;
}infoFecha;

typedef struct
{
    char IdEquipo[3];
    char nombre[40];
    char siglas[15];
    int jjugados;
    int jperdidos;
    infoFecha fechatorneo;

}infoEquipo;

typedef struct
{
    char IdJugador[3];
    char cedula[11];
    char nombre[50];
    infoFecha fechaing;
    int cantAsist;
    int bolrobadas;
    int ptosdos;
    int ptostres;
    int ptostiroslib;

}infoJugador;

typedef struct
{
    char IdPartido[3];
    char IdEqLocal[3];
    char IdEqVisit[3];
    infoFecha FechaPartido;
}infoPartido;

int pos_jugador_mas_puntos(infoJugador *, int);
int total_ptos_jugador(infoJugador *);

int main()
{
    //j --> arreglo de jugadores
    infoJugador j[] = {
                        {"01","1111","Elian M",18,2,2021,1,0,3,3,4},
                        {"02","2222","Brailin H",17,5,2022,1,0,5,4,8},
                        {"03","3333","Melvin P",28,4,2021,1,0,1,1,0},
                        {"04","4444","Nathalia F",25,3,2020,1,0,6,7,10},
                        {"05","5555","Alejandro D",17,4,2023,1,0,2,2,4}
                      };
    int pos= pos_jugador_mas_puntos(j,5);
    printf("\nEl jugador con mas puntos es %s %s con %d puntos.\n",(j+pos)->IdJugador
                                                                  ,(j+pos)->nombre
                                                                  ,total_ptos_jugador(j+pos));
    system("PAUSE");
    return 0;
}

/*
b) Los jugadores se guardan en un arreglo de jugadores de 24 (12 por cada equipo). Se desea
realizar una función que retorne la posición donde se encuentra el jugador con más puntos
dentro del arreglo de jugadores, tome como argumento: un puntero a una estructura
jugador, con el que se manejará los jugadores; un entero que indicará la cantidad de
jugadores a evaluar.

*/

int total_ptos_jugador(infoJugador *jugador)
{
    return ((jugador->ptosdos)*2 + (jugador->ptostres)*3 + (jugador->ptostiroslib));
}
int pos_jugador_mas_puntos(infoJugador *jugadores, int n)
{
    int i, mayorptos = total_ptos_jugador(jugadores), pos=0;
    //mayorptos se le envía el resultado del total de puntos del jugador de la primera posicion
    //mayorptos = (jugadores->ptosdos)*2 + (jugadores->ptostres)*3 + (jugadores->ptostiroslib);

    //empezar en el 2do jugador
    for(i=1; i<n; i++)
    {
        //if((jugadores+i)->ptosdos)*2 +
        //((jugadores+i)->ptostres)*3 + ((jugadores+i)->ptostiroslib) > mayorptos)
        if(total_ptos_jugador(jugadores+i) > mayorptos)
        {
            mayorptos = total_ptos_jugador(jugadores+i);
            pos = i;
        }
    }
    return pos;
}
