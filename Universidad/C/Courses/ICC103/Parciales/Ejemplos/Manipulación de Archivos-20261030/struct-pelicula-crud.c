#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define LEN 30

typedef struct
{
    char titulo[LEN];
    char pais[LEN];
    char genero[LEN];
    float presupuesto;
    int agno;
    int duracion;
    char estatus; //'A' -> Activo 'I' -> Inactivo
} PELICULA;

void crear_pelicula(PELICULA *, char *);
void listar_peliculas(char *);
void actualizar_pelicula(char *, char *);
void eliminar_pelicula();
void menu();

int main()
{
    menu();

    system("PAUSE");
    return 0;
}

void menu()
{
    int op;

    printf("===================================");
    printf("\n      CRUD de PELICULA\n");
    printf("===================================\n");
    printf("1- Crear pel%ccula\n",161);
    printf("2- Listar pel%cculas\n",161);
    printf("3- Inactivar pel%ccula\n",161);
    printf("4- Eliminar pel%ccula\n\n",161);
    printf("Indique una opci%cn: ",162);
    scanf("%d",&op);

    PELICULA *p;
    char *titulo_buscar;

    titulo_buscar = (char *)calloc(LEN,sizeof(char));

    p = (PELICULA *)malloc(sizeof(PELICULA));

    if(op==1)
        crear_pelicula(p,"peliculas.dat");
    else if (op==2)
        listar_peliculas("peliculas.dat");
    else if (op==3)
    {
        getchar();
        printf("Digite t%ctulo a buscar: ",161);
        gets(titulo_buscar);

        actualizar_pelicula(titulo_buscar,"peliculas.dat");
    }
    else if(op==4)
    {
        listar_peliculas("peliculas.dat");
        eliminar_pelicula();
    }

    free(p);

}
void crear_pelicula(PELICULA *p, char *nom_arch)
{
    printf("\n1- Crear Pel%ccula\n",161);
    getchar();
    printf("Digite t%ctulo: ",161);
    //gets(p->titulo,LEN,stdin);
    gets(p->titulo);
    printf("Digite pa%cs: ",161);
    //fgets(p->pais,LEN,stdin);
    gets(p->pais);
    printf("Digite g%cnero: ",130);
    //fgets(p->genero,LEN,stdin);
    gets(p->genero);
    printf("Indique presupuesto: ");
    scanf("%f",&p->presupuesto);
    printf("Indique a%co: ",164);
    scanf("%d",&p->agno);
    printf("Indique duraci%cn: ",162);
    scanf("%d",&p->duracion);
    p->estatus = 'A';

    FILE *fp;

    fp = fopen(nom_arch,"a+b");
    if(fp==NULL)
        printf("\nError abriendo archivo\n");
    else
    {
        fwrite(p,sizeof(PELICULA),1,fp);
        printf("\nPel%ccula salvada exitosamente\n",161);
    }
    fclose(fp);
}
void listar_peliculas(char *nom_arch)
{
    PELICULA *p;

    p = (PELICULA *)malloc(sizeof(PELICULA));

    FILE *fp;

    fp = fopen(nom_arch,"rb");
    if(fp==NULL)
        printf("\nEl archivo no existe\n");
    else
    {
        printf("\n\n%15s%15s%10s%15s%10s%10s%15s\n","Titulo"
               ,"Genero"
               ,"Pais"
               ,"Presupuesto"
               ,"Duracion"
               ,"Agno"
               ,"Estatus");
        printf("=============================================================================================\n");
        while(fread(p,sizeof(PELICULA),1,fp)==1) //while(!(feof(fp)))
        {
            printf("%15s%15s%10s%15.2f%10d%10d%15c\n",p->titulo
                   ,p->genero
                   ,p->pais
                   ,p->presupuesto
                   ,p->duracion
                   ,p->agno
                   ,p->estatus);
        }

    }
    printf("\n\n");
    fclose(fp);
    free(p);

}
void actualizar_pelicula(char *titulo_buscar, char *nom_arch)
{
    PELICULA *p;

    p = (PELICULA *)malloc(sizeof(PELICULA));

    FILE *fp;
    int find=0;

    fp = fopen(nom_arch,"r+b");
    if(fp==NULL)
        printf("\nEl archivo no existe\n");
    else
    {
        while(fread(p,sizeof(PELICULA),1,fp)==1)
        {
            if(stricmp(p->titulo,titulo_buscar)==0)
            {
                fseek(fp,-sizeof(PELICULA),SEEK_CUR);
                if(p->estatus == 'A')
                    p->estatus = 'I';
                else
                    p->estatus = 'A';

                fwrite(p,sizeof(PELICULA),1,fp);
                find=1;
                break;
            }
        }
    }
    fclose(fp);
    if(find)
    {
        printf("\nPelicula actualizada exitosamente\n");
        listar_peliculas(nom_arch);
    }

    free(p);
}
void eliminar_pelicula()
{
    FILE *fporig, *fptemp;
    char *titulo_buscar;
    int find=0;
    PELICULA *p;

    p = (PELICULA *)malloc(sizeof(PELICULA));
    titulo_buscar = (char *)calloc(LEN,sizeof(char));

    fptemp = fopen("temp.dat","w+b");
    if(fptemp==NULL)
    {
        printf("\nEl archivo temporal no se pudo crear\n");
        return;
    }

    fporig = fopen("peliculas.dat","rb");
    if(fporig==NULL)
        printf("\nEl archivo no existe\n");
    else
    {
        getchar();
        printf("\nDigite pel%ccula a eliminar: ",161);
        gets(titulo_buscar);


        while(fread(p,sizeof(PELICULA),1,fporig)==1)
        {
            if(stricmp(p->titulo,titulo_buscar)==0)
                find=1; //lo encontré pero no la escribo en el archivo temporal
            else
                fwrite(p,sizeof(PELICULA),1,fptemp);
        }
    }
    fclose(fporig);
    fclose(fptemp);
    if(find==1) //si eliminó una pelicula
    {
        remove("peliculas.dat"); //borramos el archivo original que tenia la pelicula a eliminar
        rename("temp.dat","peliculas.dat");
        printf("\nPel%ccula eliminada\n",161);
        listar_peliculas("peliculas.dat");
    }
    else
    {
        remove("temp.dat");
        printf("\nNo se pudo borrar la pelicula\n");
    }
}
