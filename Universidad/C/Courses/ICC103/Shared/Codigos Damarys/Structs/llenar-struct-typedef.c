#include<stdio.h>
#include<stdlib.h>

typedef struct
{
    char id[9];
    char nombres[50];
    char apellidos[50];
    char sexo; //'F' 'M'
    int edad;
}INFOESTUDIANTE;

void mostrar_estudiante(INFOESTUDIANTE);

int main()
{
    INFOESTUDIANTE estud1, estud2, estud3 = {"10169267",
                                             "Elian Gabriel",
                                             "Melendez Liranzo",
                                             'M',
                                             19
                                            };

    printf("Indica ID: ");
    gets(estud1.id);

    printf("Indica nombres: ");
    gets(estud1.nombres);

    printf("Indica apellidos: ");
    gets(estud1.apellidos);

    printf("Indica sexo: ");
    scanf("%c",&estud1.sexo);

    printf("Indica edad: ");
    scanf("%d",&estud1.edad);

    mostrar_estudiante(estud1);

    estud2 = estud1;
    mostrar_estudiante(estud2);
    mostrar_estudiante(estud3);

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
