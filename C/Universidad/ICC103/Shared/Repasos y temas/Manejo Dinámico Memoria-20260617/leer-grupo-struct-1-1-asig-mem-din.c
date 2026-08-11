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
    EXAMEN *ex;

    int opcion, cont=0;

    do
    {
        //reservar el primer espacio en memoria
        if(cont==0)
            ex=(EXAMEN *)calloc(1,sizeof(EXAMEN));

        //si tengo más de un elemento amplio el espacio
        //antes de llenar los datos del nuevo examen
        else
            ex=(EXAMEN *)realloc(ex,(cont+1)*sizeof(EXAMEN));

        leer_examen(ex+cont);
        cont++;

        printf("Desea continuar? (1-Si 2-No): ");
        scanf("%d",&opcion);


    }while(opcion==1);

    printf("\nSaliendo...\n");
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

