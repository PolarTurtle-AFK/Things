#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 10

typedef struct
{
    char cedula[12];
    char nombres[60];
    char apellidos[60];
    char genero; //'F' -> Femenino 'M' -> Masculino
}infopersona;

void print_persona(infopersona);
void print_persona_puntero(infopersona *);
void crear_personas(infopersona [], int);
void imprimir_personas(infopersona *, int);

int main()
{
    infopersona persona, persona2;
    infopersona persona3 = {"40289631","Britney","Spears",'F'};
    infopersona *pers;

    /*
    pers = &persona3;

    printf("Cedula: ");
    gets(persona.cedula);

    printf("Nombres: ");
    gets(persona.nombres);

    printf("Apellidos: ");
    gets(persona.apellidos);

    printf("Genero: ");
    scanf("%c",&persona.genero);

    print_persona(persona);
    //persona2 = persona;

    strcpy(persona2.cedula,"4444");
    strcpy(persona2.nombres,"Henry");
    strcpy(persona2.apellidos,"Cavill");
    persona2.genero = 'M';

    printf("\nDatos persona 2");
    print_persona(persona2);

    printf("\nDatos persona 3 sin puntero");
    print_persona(persona3);

    printf("\nDatos persona 3 con puntero");
    print_persona_puntero(&persona3);
    print_persona_puntero(pers);

    */
    int n;
    do
    {
        printf("Digite cantidad de personas: ");
        scanf("%d",&n);

        if(n<2)
        {
            printf("\a\nError!\nDigite un valor mayor que uno (1)\n");
            system("PAUSE");
            system("CLS");
        }
    }while(n<2);
    infopersona p[MAX];

    crear_personas(p,n);

    int i;
    for(i=0; i<n; i++)
    {
        print_persona(p[i]);
    }

    printf("\nPersonas Registradas\n");
    imprimir_personas(p,n);

    system("PAUSE");
    return 0;
}
void print_persona(infopersona p)
{
    printf("\nPersona Registrada: %s %s (%s) %s\n",p.nombres
                                             ,p.apellidos
                                             ,p.cedula
                                             ,(p.genero == 'F' ? "Femenino" : "Masculino"));
    /*if(p.genero=='F')
        printf("\nFemenino\n");
    else
        printf("\nMasculino\n");*/
}
void print_persona_puntero(infopersona *p)
{
    printf("\nPersona Registrada: %s %s (%s) %s\n",p->nombres
                                                  ,p->apellidos
                                                  ,p->cedula
                                                  ,(p->genero == 'F' ? "Femenino" : "Masculino"));
}
void crear_personas(infopersona p[], int n)
{
    int i;
    for(i=0; i<n; i++)
    {
        getchar();
        printf("\nDatos Persona %d\n",i+1);
        printf("Digite cedula: ");
        gets(p[i].cedula);

        printf("Digite nombres: ");
        gets(p[i].nombres);

        printf("Digite apellidos: ");
        gets(p[i].apellidos);

        printf("Digite genero: ");
        scanf("%c",&p[i].genero);
    }
}
void imprimir_personas(infopersona *p, int n)
{
    int i;
    printf("\n%s%15s%15s%15s\n","Cedula"
                             ,"Nombres"
                             ,"Apellidos"
                             ,"Genero");
    for(i=0; i<n; i++)
    {
        printf("%s%15s%15s%15s\n",(p+i)->cedula
                               ,(p+i)->nombres
                               ,(p+i)->apellidos
                               ,(p+i)->genero == 'F' ? "Femenino" : "Masculino");
    }

}
