#include<stdio.h>
#include<stdlib.h>

typedef struct
{
    int hora;
    int min;
    int seg;
}TIEMPO;

typedef struct
{
    int dia;
    int mes;
    int agno;
    TIEMPO time;
}FECHA;

typedef struct
{
    char id[9];
    char nombres[50];
    char apellidos[50];
    char sexo; //'F' 'M'
    int edad;
    FECHA fechanacim;
}INFOESTUDIANTE;

void leer_estudiante(INFOESTUDIANTE *);
void mostrar_estudiante(INFOESTUDIANTE);

int main()
{
    INFOESTUDIANTE estud1, *puntestud;

    //puntestud = &estud1;

    leer_estudiante(&estud1);
    mostrar_estudiante(estud1);

    system("PAUSE");
    return 0;
}
void leer_estudiante(INFOESTUDIANTE *e)
{
    printf("Indica ID: ");
    gets(e->id);

    printf("Indica nombres: ");
    gets(e->nombres);

    printf("Indica apellidos: ");
    gets(e->apellidos);

    printf("Indica sexo: ");
    scanf("%c",&e->sexo);

    printf("Indica edad: ");
    scanf("%d",&e->edad);

    printf("Digite fecha de nacimiento: ");
    scanf("%d %d %d",&e->fechanacim.dia
                    ,&e->fechanacim.mes
                    ,&e->fechanacim.agno);
                    //,&e->fechanacim.hora.time);

}
void mostrar_estudiante(INFOESTUDIANTE est)
{
    printf("\nEstudiante %s - %s %s %c %d  %d/%d/%d\n",est.id
                                                      ,est.nombres
                                                      ,est.apellidos
                                                      ,est.sexo
                                                      ,est.edad
                                                      ,est.fechanacim.dia
                                                      ,est.fechanacim.mes
                                                      ,est.fechanacim.agno);
}
