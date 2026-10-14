#include<stdio.h>
#include<stdlib.h>
#define MAX 100

typedef struct
{
    char id[9];
    char nombres[50];
    char apellidos[50];
    char sexo; //'F' 'M'
    int edad;
} INFOESTUDIANTE;

void mostrar_estudiante(INFOESTUDIANTE);
void listar_estudiantes(INFOESTUDIANTE [], int);

int main()
{
    INFOESTUDIANTE estud[MAX];
    int n, i;

    printf("Digite cantidad de estudiantes: ");
    scanf("%d",&n);

    for(i=0; i<n; i++)
    {
        getchar();
        printf("\nEstudiante %d: ",i+1);
        printf("\nIndica ID: ");
        gets(estud[i].id);

        printf("Indica nombres: ");
        gets(estud[i].nombres);

        printf("Indica apellidos: ");
        gets(estud[i].apellidos);

        printf("Indica sexo: ");
        scanf("%c",&estud[i].sexo);

        printf("Indica edad: ");
        scanf("%d",&estud[i].edad);
    }

    printf("\nListado de Estudiantes\n\n");
    listar_estudiantes(estud,n);
    /*
    for(i=0; i<n; i++)
        mostrar_estudiante(estud[i]);
    */
    system("PAUSE");
    return 0;
}
void mostrar_estudiante(INFOESTUDIANTE est)
{
    printf("\nEstudiante %s - %s %s %c %d\n",est.id
           ,est.nombres
           ,est.apellidos
           ,est.sexo
           ,est.edad);
}
void listar_estudiantes(INFOESTUDIANTE e[], int n)
{
    int i;
    printf("\nNo.  ID        Nombres     Apellidos    Sexo   Edad\n");
    for(i=0; i<n; i++)
    {
        printf("%2d%5s%15s%14s%6c%8d\n",i+1
                                     ,e[i].id
                                     ,e[i].nombres
                                     ,e[i].apellidos
                                     ,e[i].sexo
                                     ,e[i].edad);
    }
}
