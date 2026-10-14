#include<stdio.h>
#include<stdlib.h>

typedef struct
{
    int dia;
    int mes;
    int agno;
} FECHA;

typedef struct
{
    char id[6];
    char nombre[50];
    FECHA fecha_nac;
} EMPLEADO;

EMPLEADO *llenar_datos_emp(int);
void print_datos_emp(EMPLEADO *, int);

int main()
{
    EMPLEADO *e;

    int n=3;
    e = llenar_datos_emp(n);
    print_datos_emp(e, n);

    free(e);
    system("PAUSE");
    return 0;
}
EMPLEADO *llenar_datos_emp(int n)
{
    EMPLEADO *e;

    e = (EMPLEADO *)calloc(n,sizeof(EMPLEADO));

    int i;
    for(i=0; i<n; i++)
    {
        fflush(stdin);
        printf("Digite ID: ");
        gets((e+i)->id);
        printf("Digite nombre: ");
        gets((e+i)->nombre);
        fflush(stdin);
        printf("Digite fecha de nacimiento (dd/mm/yy): ");
        scanf("%d/%d/%d",&(e+i)->fecha_nac.dia,&(e+i)->fecha_nac.mes,&(e+i)->fecha_nac.agno);
    }
    return e;
}
void print_datos_emp(EMPLEADO *e, int n)
{
    int i;
    for(i=0; i<n; i++)
    {
        printf("\nEmpleado %d: %s %s %d/%d/%d\n",i+1
               ,(e+i)->id
               ,(e+i)->nombre
               ,(e+i)->fecha_nac.dia
               ,(e+i)->fecha_nac.mes
               ,(e+i)->fecha_nac.agno);
    }
}
