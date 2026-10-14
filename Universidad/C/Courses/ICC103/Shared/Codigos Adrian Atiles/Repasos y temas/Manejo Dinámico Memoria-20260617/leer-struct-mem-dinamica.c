#include<stdio.h>
#include<stdlib.h>

typedef struct
{
    int dia;
    int mes;
    int agno;
}FECHA;

typedef struct
{
    char id[6];
    char nombre[50];
    FECHA fecha_nac;
}EMPLEADO;

EMPLEADO *llenar_datos_emp();
void print_datos_emp(EMPLEADO *);

int main()
{
    EMPLEADO *e;

    e = llenar_datos_emp();
    print_datos_emp(e);

    free(e);
    system("PAUSE");
    return 0;
}
EMPLEADO *llenar_datos_emp()
{
    EMPLEADO *e;

    e = (EMPLEADO *)calloc(1,sizeof(EMPLEADO));

    printf("Digite ID: ");
    gets(e->id);
    printf("Digite nombre: ");
    gets(e->nombre);
    printf("Digite fecha de nacimiento (dd/mm/yy): ");
    scanf("%d/%d/%d",&e->fecha_nac.dia,&e->fecha_nac.mes,&e->fecha_nac.agno);

    return e;
}
void print_datos_emp(EMPLEADO *e)
{
    printf("\nEmpleado: %s %s %d/%d/%d\n",e->id
                                         ,e->nombre
                                         ,e->fecha_nac.dia
                                         ,e->fecha_nac.mes
                                         ,e->fecha_nac.agno);
}
