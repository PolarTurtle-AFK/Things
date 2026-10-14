#include<stdio.h>
#include<stdlib.h>

typedef struct
{
    char titulo[50];
    char autor[50];
    char editorial[50];
    int agnopub;
}INFOLIBROS;

void print_libro(INFOLIBROS *);

int main()
{
    INFOLIBROS libro1, libro2, *libropuntero;

    printf("Digite titulo: ");
    fgets(libro1.titulo,50,stdin);

    printf("Digite autor: ");
    fgets(libro1.autor,50,stdin);

    printf("Digite editorial: ");
    fgets(libro1.editorial,50,stdin);

    printf("Digite a%co publicacion: ",164);
    scanf("%d",&libro1.agnopub);

    print_libro(&libro1);

    libropuntero = &libro2;

    getchar();
    printf("Digite titulo: ");
    fgets(libropuntero->titulo,50,stdin);

    printf("Digite autor: ");
    fgets(libropuntero->autor,50,stdin);

    printf("Digite editorial: ");
    fgets(libropuntero->editorial,50,stdin);

    printf("Digite a%co publicacion: ",164);
    scanf("%d",&libropuntero->agnopub);

    print_libro(libropuntero);

    system("PAUSE");
    return 0;
}
void print_libro(INFOLIBROS *libro)
{
    printf("\nDatos libro\n");
    printf("%s %s %s %d\n\n",libro->titulo, libro->autor, libro->editorial, libro->agnopub);
}
