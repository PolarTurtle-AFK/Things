#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct empleado
{
    char codempleado[7];
    char nombre[30];
    char puesto[30];
    float sueldo;
};
struct departamento
{
    char coddepto[7];
    char nombre[30];
    struct empleado emp[50];
    int cantemp;
};

void depto_mayor_paga(struct departamento [], int , struct departamento *);

int main()
{
    struct departamento depto[3]= {
                                    {"D001","Contabilidad",
                                        {
                                           {"E001", "Henry Cavill", "Manager", 50000},
                                           {"E002", "Britney Spears", "Asistente", 10000},
                                           {"E003", "Chris Evans", "Secretario", 15000},
                                           {"E004", "Scarlet Johanson", "Contadora", 25000},
                                        },4

                                    },
                                    {"D002","Finanzas",
                                        {
                                           {"E005", "Ramon Perez", "Manager", 50000},
                                           {"E006", "Patricia Spears", "Asistente", 10000}
                                        },2

                                    },
                                    {"D003","Operaciones",
                                        {
                                           {"E007", "Pedro Perez", "Manager", 20000},
                                           {"E008", "Ruth Leon", "Asistente", 6000}
                                        },2

                                    }
                                  };
    struct departamento mayordepto;
    depto_mayor_paga(depto,3,&mayordepto);


    printf("\nEl depto que mas paga es: %s %s\n",mayordepto.coddepto
                                                ,mayordepto.nombre);

    system("PAUSE");
    return 0;
}
void depto_mayor_paga(struct departamento depto[], int n, struct departamento *d)
{
    int i, j, pos=0;
    float promedio, mayor=0;

    for(i=0; i<n; i++)
    {
        if(depto[i].cantemp >0)
        {
            promedio = 0;
            for(j=0; j<depto[i].cantemp; j++)
                promedio += depto[i].emp[j].sueldo;

            promedio/= depto[i].cantemp; // promedio = promedio/depto[i].cantemp;

            if(promedio>mayor)
            {
                mayor = promedio;
                pos=i;
            }
        }
    }
    *d = *(depto + pos);
}

