#include<stdio.h>
#include<stdlib.h>
#define MAX 100

typedef struct
{
    int dia;
    int mes;
    int agno;
}FECHA;

typedef struct
{
    char cedula[13];
    char nombres[50];
    char apellidos[50];
    char tiposangre;
    FECHA fechanacim;
}INFOPERSONA;

void leer_personas(INFOPERSONA *, int);
void listar_personas(INFOPERSONA [], int);

int main()
{
    INFOPERSONA personas[MAX];
    int n;

    printf("Digite cantidad de personas: ");
    scanf("%d",&n);

    leer_personas(personas,n);
    listar_personas(personas, n);
    system("PAUSE");
    return 0;
}
void leer_personas(INFOPERSONA *p, int n)
{
    int i;
    for(i=0; i<n; i++)
    {
        printf("Datos persona %d: \n",i+1);
        getchar();
        printf("Indique cedula: ");
        gets((p+i)->cedula);
        printf("Indique nombres: ");
        gets((p+i)->nombres);
        printf("Indique apellidos: ");
        gets((p+i)->apellidos);
        printf("Indique tipo de sangre: ");
        scanf("%c",&(p+i)->tiposangre);
        printf("Indique fecha de nacimiento: ");
        scanf("%d %d %d",&(p+i)->fechanacim.dia, &(p+i)->fechanacim.mes, &(p+i)->fechanacim.agno);

    }
}
void listar_personas(INFOPERSONA p[], int n)
{
    int i;

    printf("\nNo. Cedula    Nombres    Apellidos    Tipo   Fecha Nac\n\n");

    for(i=0; i<n; i++)
    {
        printf("%d%10s%10s%10s%5c%10d%-d-%d\n",i+1
                                               ,p[i].cedula
                                               ,p[i].nombres
                                               ,p[i].apellidos
                                               ,p[i].tiposangre
                                               ,p[i].fechanacim.dia
                                               ,p[i].fechanacim.mes
                                               ,p[i].fechanacim.agno);
    }
}
