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
    int n;
    EXAMEN *ex;

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

    ex=(EXAMEN *)malloc(n*sizeof(EXAMEN));

    int i;
    for(i=0; i<n; i++)
    {
        fflush(stdin);
        printf("Digite ID: ");
        gets((ex+i)->idExamen);

        printf("Digite nombre examen: ");
        gets((ex+i)->nombreExamen);

        printf("Digite puntuaci%cn: ",162);
        scanf("%f",&((ex+i)->puntuacion));

        if(((ex+i)->puntuacion) >=60)
        {
            ((ex+i)->aprobado) = 'A';
            printf("Aprobado\n");
        }

        else
        {
            ((ex+i)->aprobado) = 'F';
            printf("Reprobado\n");
        }
    }
    ex=(EXAMEN *)realloc(ex, n+1*sizeof(EXAMEN));
    fflush(stdin);
    printf("Agregando un Examen extra \n");
    printf("Digite ID: ");
    gets((ex+i)->idExamen);

    printf("Digite nombre examen: ");
    gets((ex+i)->nombreExamen);

    printf("Digite puntuaci%cn: ",162);
    scanf("%f",&((ex+i)->puntuacion));

    if(((ex+i)->puntuacion) >=60)
    {
        ((ex+i)->aprobado) = 'A';
        printf("Aprobado\n");
    }

    else
    {
        ((ex+i)->aprobado) = 'F';
        printf("Reprobado\n");
    }
    system("PAUSE");
    return 0;
}

