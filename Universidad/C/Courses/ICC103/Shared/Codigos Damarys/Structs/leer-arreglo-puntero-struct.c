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

void leer_libros(INFOLIBROS *, int);
void print_libros(INFOLIBROS *, int);

int main()
{
    INFOLIBROS libros[MAX];
    int n, i;

    printf("Cuantos libros desea capturar? ");
    scanf("%d",&n);

    leer_libros(libros,n);
    print_libros(libros,n);

    system("PAUSE");
    return 0;
}

void leer_libros(INFOLIBROS *libros, int n)
{
    int i;
    for(i=0; i<n; i++)
    {
        printf("\nDatos libro %d\n",i+1);

        getchar(); //equivalente a fflush
        printf("Digite titulo: ");
        gets((libros+i)->titulo);
        //fgets((libros+i)->titulo,50,stdin);

        printf("Digite autor: ");
        gets((libros+i)->autor);
        //fgets((libros+i)->autor,50,stdin);

        printf("Digite editorial: ");
        gets((libros+i)->editorial);
       // fgets((libros+i)->editorial,50,stdin);

        printf("Digite a%co publicacion: ",164);
        scanf("%d",&(libros+i)->agnopub);
    }

}
void print_libros(INFOLIBROS *libros, int n)
{
    int i;

    printf("\nNo. Titulo    Autor    Editorial    A%co\n\n",164);
    for(i=0; i<n; i++)
    {
        printf("%d%-10s%10s%10s%5d\n",i+1
                                   ,(libros+i)->titulo
                                   ,(libros+i)->autor
                                   ,(libros+i)->editorial
                                   ,(libros+i)->agnopub);
    }
}


