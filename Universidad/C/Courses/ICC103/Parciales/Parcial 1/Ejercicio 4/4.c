#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char Codigo[20];
    int Segundos;
}reproduccion;

typedef struct{
    char nombre[20];
    reproduccion reproduccion;
    int cantrep;
}cuenta;

typedef struct {
    char Codigo[7];
    char Titulo[40];
    char Artista[30];
    int Duracion;
    cuenta cuenta
}cancion;
char artista_mas_escuchado (cuenta *c, cancion *can, int nc);

int main()
{
    cuenta c[3]={
        "damari",
        {
            {"hablamucho"},1,
        },
        1,
    };

    cancion can[3]={
        "C003",
        "Espresso",
        "Sabrina carpenter",
        175,
    };
    artista_mas_escuchado(c,can,1);
    return 0;
}



char artista_mas_escuchado (cuenta *c, cancion *can, int nc){
    for(int i=0; i<nc; i++){
        if(strcmp(can[i].Codigo,c->reproduccion.Codigo)==0){
            if(can[i].Duracion>=30){
                printf("USUARIO: %s",c->nombre);
                printf("ARTISTA: %s", can[i].Artista);
            }else
            return '\0';
        }

    }
}













