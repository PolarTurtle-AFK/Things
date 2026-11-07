#include<stdio.h>
#include<stdlib.h>

typedef struct
{
    char cedula[12];
    char nombre[30];
    char apellido[30];
    int edad;
    float sueldo;
}Empleado;

int main()
{
    Empleado *e, *emps;
    int n;

    e = (Empleado *)malloc(sizeof(Empleado));

    printf("Digite c%cdula: ",130);
    gets(e->cedula);
    printf("Digite nombre: ");
    gets(e->nombre);
    printf("Digite apellido: ");
    gets(e->apellido);

    do
    {
        printf("Digite cantidad de empleados: ");
        scanf("%d",&n);

        if(n<2)
        {
            printf("\nError!\nDigite un valor mayor que uno (1).\n");
            system("PAUSE");
            system("CLS");
        }
    }while(n<2);

    emps = (Empleado *)calloc(n,sizeof(Empleado));

    int i;
    for(i=0; i<n; i++)
    {
        getchar();
        printf("Datos Empleado %d\n", i+1);
        printf("Digite c%cdula: ",130);
        gets((emps+i)->cedula);

        printf("Digite nombre: ");
        gets((emps+i)->nombre);
    }
    free(e);
    system("PAUSE");
    return 0;
}
