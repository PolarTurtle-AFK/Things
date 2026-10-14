/*
Defina un tipo de datos para almacenar la siguiente información.
a) Un estudiante posee los siguientes atributos: matrícula de 8 caracteres, nombre1 de 30
caracteres, nombre2 de 35 caracteres, apellido1 de 25 caracteres, apellido2 de 25
caracteres, carrera de 4 caracteres, categoría de pago de 3 caracteres, nacionalidad de 3
caracteres, dirección de 256 caracteres.
b) Una asignatura tiene los siguientes atributos: código de 7 caracteres, nombre de 60
caracteres, créditos de tipo entero, horas teóricas de tipo entero, horas prácticas de tipo
entero.
c) Un grupo tiene los siguientes atributos: código de la asignatura de 7 caracteres, número del
grupo de 3 caracteres, cupo del grupo tipo entero, Horario de 50 caracteres.
d) Una inscripción tiene los siguientes atributos: matrícula del estudiante de 8 caracteres,
código de la asignatura de 7 caracteres, número del grupo de 3 caracteres.
e) Si se tiene un arreglo de grupos con MAXGRUPOS y otro de asignaturas con MAXASIG, se
desea una función que liste los grupos de las asignaturas que tienen únicamente horas
teóricas.
f) Se desea una función que dado una matrícula, un arreglo de estudiantes y la cantidad de
estudiantes, retorne la posición donde se encuentra dicha matrícula. (Se asume no hay
repeticiones de matrícula).
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAXGRUPOS 5
#define MAXASIG 3

typedef struct
{
    char matricula[8];
    char nombre1 [30];
    char nombre2 [35];
    char apellido1 [25];
    char apellido2 [25];
    char carrera[4];
    char categoria[3];
    char nacionalidad[3];
    char direccion[256];
} ESTUD;

typedef struct
{
    char codasig[7];
    char nombre[60];
    int creditos;
    int horast;
    int horasp;
} ASIG;

typedef struct
{
    char codasig[7];
    char numgrupo[3];
    int cupo;
    char horario[50];
} GRUPO;

typedef struct
{
    char matricula[8];
    char codasig[7];
    char numgrupo[3];
} INSC;

void listar_grupos_asig_horast(GRUPO *, int, ASIG *, int);
int posicion_matricula(ESTUD *, int, char *);

int main()
{

    ASIG a[MAXASIG]= {
                        {"ICC103","Fundamentos de Programacion",4,3,3},
                        {"ICC101","Introduccion a la Algoritmia",3,3,2},
                        {"ING101","Ingles Introductorio",5,5,0}
                     };
    GRUPO g[MAXGRUPOS] = {
                            {"ICC103","10",25,"Lu y Mie 8-10pm"},
                            {"ICC101","11",25,"Ma y Jue 8-10pm"},
                            {"ING101","10",25,"Lu, Mie y Vie 8-10am"},
                            {"ING101","20",25,"Ma, Ju y Vie 9-11am"},
                            {"ICC103","15",25,"Lu y Mie 8-10pm"}
                        };
    ESTUD e[3] = {
                    {"1010","Alexander","","Estevez","Guzman","ITT","01","DO","Santiago"},
                    {"1011","Edwin","Manuel","Cabrera","Frias","ICC","01","DO","Santiago"},
                    {"1012","Naioby","","Abreu","Sanchez","ICC","01","DO","Santiago"}
                 };

    listar_grupos_asig_horast(g,MAXGRUPOS,a,MAXASIG);
    int result = posicion_matricula(e,3,"1012"); //si cambia posicion_matricula(e,3,"1012")

    if(result>0)
        printf("\n\nEstudiante existe.\nMatricula: %s\nNombre: %s %s\nCarrera: %s\n\n",(e+result)->matricula
                                                                                  ,(e+result)->nombre1
                                                                                  ,(e+result)->apellido1
                                                                                  ,(e+result)->carrera);
    else
        printf("No existe el estudiante\n");

    system("PAUSE");
    return 0;
}
/*
Si se tiene un arreglo de grupos con MAXGRUPOS y otro de asignaturas con MAXASIG, se
desea una función que liste los grupos de las asignaturas que tienen únicamente horas
teóricas.
*/
//g - el arreglo de grupo
//ng cantidad de grupo
//a el arreglo de asignaturas
//na - cantidad de asignaturas
void listar_grupos_asig_horast(GRUPO *g, int ng, ASIG *a, int na)
{
    int i, j;
    //recorrer las asignaturas
    for(i=0; i<na; i++)
    {
        //si la asignatura actual solo tiene horas teorícas
        if((a+i)->horasp == 0 && (a+i)->horast > 0)
        {
            //recorrer los grupos
            for(j=0; j<ng; j++)
            {
                if(stricmp((a+i)->codasig, (g+j)->codasig)==0)
                    printf("Grupo %s (%s). Cupo: %d, Horario: %s\n",(g+j)->codasig
                                                                   ,(g+j)->numgrupo
                                                                   ,(g+j)->cupo
                                                                   ,(g+j)->horario);
            }
        }
    }
}
/*
Se desea una función que dado una matrícula, un arreglo de estudiantes y la cantidad de
estudiantes, retorne la posición donde se encuentra dicha matrícula. (Se asume no hay
repeticiones de matrícula)
*/
int posicion_matricula(ESTUD *e, int n, char *matbuscar)
{
    int i;
    for(i=0; i<n; i++)
    {
        if(strcmp((e+i)->matricula,matbuscar)==0)
            return i;
    }
    return -1; //no la encontró
}
