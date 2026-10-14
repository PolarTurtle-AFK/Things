#include<stdio.h>
#include<stdlib.h>
#define MAX 100
#define C 5

typedef struct
{
    char tipo; //'C' -> Telefono Casa 'E' -> Email 'W' -> WhatsApp
    char desc[50];
}INFOCONTACTO;

typedef struct
{
    char id[9];
    char nombres[50];
    char apellidos[50];
    char sexo; //'F' 'M'
    int edad;
    INFOCONTACTO contacto[C]; //Puede tener varios contactos
    int numcont; //cuanto contactos tiene el estudiante en cuestion
} INFOESTUDIANTE;

void leer_estudiantes(INFOESTUDIANTE *, int);
void listar_estudiantes(INFOESTUDIANTE [], int);
void listar_estudiantes_punteros(INFOESTUDIANTE *, int);

int main()
{
    INFOESTUDIANTE estud[MAX];
    int n, i;

    printf("Digite cantidad de estudiantes: ");
    scanf("%d",&n);

    leer_estudiantes(estud,n);
    printf("\nListado de Estudiantes\n\n");
    listar_estudiantes(estud,n);
    printf("\nListado de Estudiantes PUNTEROS\n\n");
    listar_estudiantes_punteros(estud,n);

    system("PAUSE");
    return 0;
}

void leer_estudiantes(INFOESTUDIANTE *e, int n)
{
    int i, j;
    //e --> estudiante
    for(i=0; i<n; i++)
    {
        getchar();
        printf("\nEstudiante %d: ",i+1);
        printf("\nIndica ID: ");
        gets((e+i)->id);

        printf("Indica nombres: ");
        gets((e+i)->nombres);

        printf("Indica apellidos: ");
        gets((e+i)->apellidos);

        printf("Indica sexo: ");
        scanf("%c",&(e+i)->sexo);

        printf("Indica edad: ");
        scanf("%d",&(e+i)->edad);

        printf("Indica cantidad de contactos: ");
        scanf("%d",&(e+i)->numcont);


        for(j=0; j<(e+i)->numcont; j++)
        {
            getchar();
            printf("\Contacto %d: \n",j+1);
            printf("Indique tipo: ");
            scanf("%c",&(e+i)->contacto[j].tipo);

            printf("Indique valor: ");
            gets((e+i)->contacto[j].desc);
            getchar();
        }
    }
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
void listar_estudiantes_punteros(INFOESTUDIANTE *est, int n)
{
    int i, j;
    printf("\nNo.  ID        Nombres     Apellidos    Sexo   Edad\n");
    for(i=0; i<n; i++)
    {
        printf("%2d%5s%15s%14s%6c%8d\n",i+1
                                     ,(est+i)->id
                                     ,(est+i)->nombres
                                     ,(est+i)->apellidos
                                     ,(est+i)->sexo
                                     ,(est+i)->edad);

        for(j=0; j<(est+i)->numcont; j++)
        {
            printf("\Contacto %d: %c - %s\n",j+1
                                            ,(est+i)->contacto[j].tipo
                                            ,(est+i)->contacto[j].desc);
        }

    }
}
