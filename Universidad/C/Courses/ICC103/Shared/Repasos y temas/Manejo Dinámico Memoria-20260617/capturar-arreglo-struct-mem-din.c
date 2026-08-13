#include<stdio.h>
#include<stdlib.h>

typedef struct
{
    char id[6];
    char nombre[50];
} AUTOR;

typedef struct
{
    char isbn[15];
    char titulo[50];
    AUTOR autores[10];
    int cant_autores;
} LIBRO;

LIBRO *registrar_libros(int);
void print_libros(LIBRO *, int);
void mi_fflush();

int main()
{
    int n;

    do
    {
        printf("Digite cantidad de libros: ");
        scanf("%d",&n);

        if(n<2)
        {
            printf("\n\aError!!!\nDigite un valor mayor que uno (1).\n");
            system("PAUSE");
            system("CLS");
        }
    }
    while(n<2);

    LIBRO *libros;

    libros = registrar_libros(n);
    print_libros(libros,n);

    free(libros);
    system("PAUSE");
    return 0;
}
LIBRO *registrar_libros(int n)
{
    LIBRO *libros;

    libros = (LIBRO *) calloc(n,sizeof(LIBRO));//libros = (LIBRO *) malloc(n*sizeof(LIBRO));
    int i, j;

    for(i=0; i<n; i++)
    {
        mi_fflush();
        printf("Digite datos del libro\n");
        printf("Digite ISBN: ");
        gets((libros+i)->isbn);
        printf("Digite titulo: ");
        gets((libros+i)->titulo);
        printf("Digite cantidad de autores: ");
        scanf("%d",&(libros+i)->cant_autores);

        for(j=0; j<(libros+i)->cant_autores; j++)
        {
            printf("Autor %d\n",i+1);
            mi_fflush();
            printf("Digite id: ");
            gets((libros+i)->autores[j].id);
            printf("Digite nombre: ");
            gets((libros+i)->autores[j].nombre);
        }
    }
    return libros;
}
void print_libros(LIBRO *libros, int n)
{
    int i, j;

    for(i=0; i<n; i++)
    {
        printf("\nLibro %d: %s, %s\n",i+1,(libros+i)->isbn
               ,(libros+i)->titulo);
        printf("Autores: \n");
        for(j=0; j<(libros+i)->cant_autores; j++)
            printf("%d - %s\n",j+1,(libros+i)->autores[j].nombre);
    }
}

void mi_fflush()
{
    int c;
    while((c=getchar())!='\n' && c!=EOF) {}
}

