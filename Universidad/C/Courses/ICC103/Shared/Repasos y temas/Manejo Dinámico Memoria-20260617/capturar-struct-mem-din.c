#include<stdio.h>
#include<stdlib.h>

typedef struct
{
    char id[6];
    char nombre[50];
}AUTOR;

typedef struct
{
    char isbn[15];
    char titulo[50];
    AUTOR autores[10];
    int cant_autores;
}LIBRO;

void mi_fflush();

int main()
{
    LIBRO *libro1;

    libro1 = (LIBRO *) calloc(1,sizeof(LIBRO));//libro1 = (LIBRO *) malloc(sizeof(LIBRO));

    printf("Digite datos del libro\n");
    printf("Digite ISBN: ");
    gets(libro1->isbn);
    printf("Digite titulo: ");
    gets(libro1->titulo);
    printf("Digite cantidad de autores: ");
    scanf("%d",&libro1->cant_autores);

    int i;
    for(i=0; i<libro1->cant_autores; i++)
    {
        printf("Autor %d\n",i+1);
        printf("Digite id: ");
        gets(libro1->autores[i].id);
        mi_fflush();
        printf("Digite nombre: ");
        gets(libro1->autores[i].nombre);
    }
    free(libro1);
    system("PAUSE");
    return 0;
}
void mi_fflush()
{
    int c;
    while((c=getchar())!='\n' && c!=EOF) {}
}

