#include<stdio.h>
#include<stdlib.h>

typedef struct
{
    char idExamen[4];
    char nombreExamen[30];
    float puntuacion;
    char aprobado; // 'A' 'F'
} EXAMEN;

void leer_examen(EXAMEN *);

int main()
{
    int n;
    EXAMEN *examenes;

    do
    {
        printf("Digite cantidad de examenes: ");
        scanf("%d",&n);

        if(n<2)
        {
            printf("\aError!!!\nDigite un valor mayor a uno (1).\n");
            system("PAUSE");
            system("CLS");
        }
    }
    while(n<2);

    examenes=(EXAMEN *)malloc(n*sizeof(EXAMEN));

    int i;
    for(i=0; i<n; i++)
    {
        printf("Examen %d\n",i+1);
        leer_examen(examenes+i);
    }
    examenes=(EXAMEN *)realloc(examenes, n+1*sizeof(EXAMEN));
    printf("Agregando un Examen extra \n");
    leer_examen(examenes+i);

    system("PAUSE");
    return 0;
}
void leer_examen(EXAMEN *ex)
{
    fflush(stdin);
    printf("Digite ID: ");
    gets(ex->idExamen);

    printf("Digite nombre examen: ");
    gets(ex->nombreExamen);

    printf("Digite puntuaci%cn: ",162);
    scanf("%f",&(ex->puntuacion));

    if((ex->puntuacion) >=60)
    {
        (ex->aprobado) = 'A';
        printf("Aprobado\n");
    }

    else
    {
        (ex->aprobado) = 'F';
        printf("Reprobado\n");
    }
}
