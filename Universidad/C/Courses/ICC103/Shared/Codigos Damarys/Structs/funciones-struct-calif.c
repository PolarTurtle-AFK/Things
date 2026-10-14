#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct
{
    char codcarrera[4];
    char descripcion[50];
}carrera;

typedef struct
{
    char codasignatura[9];
    char descripcion[50];
    int creditos;
}asignatura;

typedef struct
{
    char matricula[9];
    char nombre[30];
    char codcarrera[4];
}estudiante;

typedef struct
{
    char semestre[9];
    char matricula[9];
    char codasig[9];
    char Cal;
}calificaciones;

char *carrera_mas_pasaron(calificaciones [], int, estudiante [], int ,char []);
char *carrera_mas_estudiante(estudiante [], int);

int main()
{
    estudiante e[5]= {
                        {"1000","Ana Perez","ICC"},
                        {"2000","Carlos Perez","ICC"},
                        {"3000","Ramona Cruz","ITT"},
                        {"4000","Jose Perez","ITT"},
                        {"5000","Juan Martinez","ITT"}
                     };
    calificaciones c[8] = {
                            {"1930","1000","ICC103",'A'},
                            {"1930","1000","FIS101",'A'},
                            {"1930","2000","ICC103",'B'},
                            {"1930","2000","FIS201",'B'},
                            {"1930","3000","ICC103",'F'},
                            {"1930","4000","FIS201",'A'},
                            {"1930","5000","ICC103",'F'},
                            {"1930","5000","ESP101",'A'}
                          };

    char *carr;

    carr = carrera_mas_pasaron(c,8,e,5,"ICC103");
    if(carr!=NULL)
        printf("\nLa carrera que mas aprobaron ICC103 es %s\n",carr);

    carr = carrera_mas_estudiante(e,5);
    if(carr!=NULL)
        printf("\nLa carrera que mas estudiantes posee es %s\n",carr);

    system("PAUSE");
    return 0;
}
char *carrera_mas_pasaron(calificaciones cali[], int nc, estudiante e[], int ce,char a[])
{
    int i, j, k;
    int cont, max=0, pos=-1;

    for(i=0; i<ce; i++)
    {
        cont=0;
        for(j=0; j<ce; j++)
        {
            if(strcmp(e[j].codcarrera, e[i].codcarrera)==0)
            {
                for(k=0; k<nc; k++)
                {
                    if(strcmp(cali[k].matricula, e[j].matricula)==0 &&
                       strcmp(cali[k].codasig,a)==0 &&
                       cali[k].Cal !='F')
                        cont++;
                }
            }
        }
        if(cont>max)
        {
            max=cont;
            pos = i;
        }
    }
    if(pos>=0)
        return e[pos].codcarrera;
    else
        return NULL;
}
char *carrera_mas_estudiante(estudiante e[], int ce)
{
    int i, j, cont, max=0, pos=-1;

    for(i=0; i<ce; i++)
    {
        cont=0;
        for(j=0; j<ce; j++)
        {
            if(strcmp(e[i].codcarrera, e[j].codcarrera)==0)
                cont++;
        }
        if(cont>max)
        {
            max=cont;
            pos=i;
        }
    }
    if(pos==-1)
        return NULL;
    return e[pos].codcarrera;
}
