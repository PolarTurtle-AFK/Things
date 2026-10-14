#include<stdio.h>
#include<stdlib.h>

struct INFOESTUDIANTE
{
    char id[9];
    char nombres[50];
    char apellidos[50];
    char sexo; //'F' 'M'
    int edad;
};

void mostrar_estudiante(struct INFOESTUDIANTE);

int main()
{
    struct INFOESTUDIANTE estud1;

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

    system("PAUSE");
    return 0;
}
void mostrar_estudiante(struct INFOESTUDIANTE est)
{
    printf("\nEstudiante %s - %s %s %c %d\n",est.id
                                          ,est.nombres
                                          ,est.apellidos
                                          ,est.sexo
                                          ,est.edad);
}
