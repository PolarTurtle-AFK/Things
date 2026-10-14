#include<stdio.h>
#include<stdlib.h>
#define MAX 100

typedef struct
{
    char titulo[50];
    char autor[50];
    char editorial[50];
    int agnopub;
} INFOLIBROS;

void leer_libros(INFOLIBROS [], int);
void print_libro(INFOLIBROS);
void mi_fflush();

int main()
{
    INFOLIBROS libros[MAX];
    int n, i;

    printf("Cuantos libros desea capturar? ");
    scanf("%d",&n);

    leer_libros(libros,n);
    for(i=0; i<n; i++)
    {
        print_libro(libros[i]);
    }

    system("PAUSE");
    return 0;
}
void leer_libros(INFOLIBROS libros[], int n)
{
    int i;
    for(i=0; i<n; i++)
    {
        printf("\nDatos libro %d\n",i+1);

        getchar(); //equivalente a fflush
        printf("Digite titulo: ");
        fgets(libros[i].titulo,50,stdin);

        printf("Digite autor: ");
        fgets(libros[i].autor,50,stdin);

        printf("Digite editorial: ");
        fgets(libros[i].editorial,50,stdin);

        printf("Digite a%co publicacion: ",164);
        scanf("%d",&libros[i].agnopub);
    }

}
void print_libro(INFOLIBROS libro)
{
    printf("\nDatos libro\n");
    printf("%s %s %s %d\n\n",libro.titulo, libro.autor, libro.editorial, libro.agnopub);
}
void mi_fflush()
{
    int c;
    while((c=getchar())!='\n' && c!=EOF)
    {
    }
}

