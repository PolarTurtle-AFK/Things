#include<stdio.h>
#include<stdlib.h>

typedef struct
{
    char idExamen[4];
    char nombreExamen[30];
    float puntuacion;
    char aprobado; // 'A' 'F'
} EXAMEN;

int main()
{
    EXAMEN *ex1;

    ex1=(EXAMEN *)calloc(1,sizeof(EXAMEN));

    printf("Digite ID: ");
    gets(ex1->idExamen);

    printf("Digite nombre examen: ");
    gets(ex1->nombreExamen);

    printf("Digite puntuaci%cn: ",162);
    scanf("%f",&(ex1->puntuacion));

    if((ex1->puntuacion) >=60)
    {
        (ex1->aprobado) = 'A';
        printf("Aprobado\n");
    }

    else
    {
        (ex1->aprobado) = 'F';
        printf("Reprobado\n");
    }

    system("PAUSE");
    return 0;
}

