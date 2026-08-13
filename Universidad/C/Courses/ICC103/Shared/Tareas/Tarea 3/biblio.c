#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char codigo[10];
    char nombre[40];
    char tipo_membresia[15];
    int meses_pagados;
    float monto;
} SOCIO;

typedef struct Nsocio
{
    SOCIO s;
    struct Nsocio *prox;
    struct Nsocio *ant;
} NODOSOCIO;

int agregar_socio(NODOSOCIO **cabeza, SOCIO socio);

int drop_socio_menor(NODOSOCIO **cabeza, SOCIO *eliminado);

typedef struct Nomoroso
{
    SOCIO s;
    struct Nomoroso *prox;
} NODOMOROSO;

void crear_archivo_prueba();

void guardar_activos(char *tipo_excluido);

int main()
{
    NODOSOCIO *cabeza = NULL;
    SOCIO s = {"S010", "Juan Perez", "Basica", 3, 900.00};
    /*{"S020", "Maria Gomez", "Premium", 6, 1500.00},
    {"S030", "Pedro Diaz", "VIP", 1, 2500.00},
    {"S040", "Juan Perez", "Premium", 5, 1200.00}
    };*/
    SOCIO s2 = {"S020", "Maria Gomez", "Premium", 6, 600.00};
    SOCIO s3 = {"S030", "Pedro Diaz", "VIP", 1, 300.00};


    agregar_socio(&cabeza, s);
    agregar_socio(&cabeza, s2);
    agregar_socio(&cabeza, s3);
    /*
    int i;
    for(i = 0; i < 4; i++)
    {

    }*/

    int i = 0;
    NODOSOCIO *IND = cabeza;


    while(IND != NULL)
    {
        printf("usuario %d: meses:%d %s [monto %.2f]\n", i+1, IND->s.meses_pagados, IND->s.nombre, IND->s.monto);
        i++;
        system("pause");
        IND = IND->prox;
    }


    /* crear_archivo_prueba();
     guardar_activos("Basica");*/
    return 0;
}

int agregar_socio(NODOSOCIO **cabeza, SOCIO socio)
{
    NODOSOCIO *nv = (NODOSOCIO *) calloc(1, sizeof(NODOSOCIO));
    if(nv == NULL)
    {
        puts("no se pudo asignar memoria xd");
        return 0;
    }

    nv->s = socio;
    nv->prox = NULL;
    nv->ant = *cabeza;

    if(*cabeza == NULL)
    {
        *cabeza = nv;
        return 1;
    }
    else
    {
        NODOSOCIO *IND = *cabeza;
        while(IND != NULL)
        {
            if(IND->s.monto > nv->s.monto)
            {
                if(IND->ant == NULL)
                {
                    IND->ant = nv;
                    nv->prox = IND;
                    nv->ant = NULL;
                    *cabeza = nv;
                }
                else if(IND->prox == NULL)
                {
                    IND->ant = nv;
                    nv->ant = IND;
                    nv->prox = NULL;
                }
                else
                {
                    IND->ant->prox = nv;
                    nv->ant = IND->ant;
                    IND->ant = nv;
                    nv->prox = NULL;

                }

                break;

            }


            IND = IND->prox;
        }

    }
    return 1;
}


int drop_socio_menor(NODOSOCIO **cabeza, SOCIO *eliminado)
{
    if(*cabeza == NULL)
    {
        return 0;
    }

    NODOSOCIO *IND = *cabeza;

    int i = 0, pos = 0, meses = 1;
    while(IND != NULL)
    {
        if(IND->s.meses_pagados <= meses)
        {
            meses = IND->s.meses_pagados;
            pos = i;
        }
        i++;
        IND = IND->prox;
    }

    IND = *cabeza;
    for(int j = 0; j < i; j++)
        IND = IND->prox;


    if(IND->ant == NULL)
    {
        IND->prox->ant = NULL;

        *cabeza = IND->prox;

        IND->prox = NULL;

        *eliminado = IND->s;

        free(IND);
    }
    else
    {
        IND->prox->ant = IND->ant;

        IND->ant->prox = IND->prox;

        *eliminado = IND->s;

        free(IND);
    }


    return 1;
}

NODOMOROSO *filtrar_morosos(NODOSOCIO **cabeza, int meses_limite)
{
    if(*cabeza == NULL)
    {
        puts("esta vacia");
        return NULL;
    }

    NODOMOROSO *AMOROSO_cabeza = NULL;
    NODOMOROSO *AMOROSO_cola = NULL;

    NODOSOCIO *IND = *cabeza;
    int cont = 0;
    while(IND != NULL)
    {
        if(IND->s.meses_pagados < meses_limite)
        {
            NODOMOROSO *nv = (NODOMOROSO *) calloc(1, sizeof(NODOMOROSO));

            nv->s = IND->s;

            if(AMOROSO_cabeza == NULL)
            {
                AMOROSO_cabeza = nv;
                AMOROSO_cabeza->prox = AMOROSO_cola;
            }
            else if(AMOROSO_cola == NULL)
            {
                AMOROSO_cola = nv;
                AMOROSO_cabeza->prox = AMOROSO_cola;
            }
            else
            {
                AMOROSO_cola->prox = nv;
                nv->prox = NULL;
                AMOROSO_cola = nv;
            }
            cont++;
        }

        IND = IND->prox;
    }

    if(cont == 0)
    {
        return NULL;
    }
    else
    {
        return AMOROSO_cabeza;
    }

}

void crear_archivo_prueba()
{
    SOCIO s1[4] =
    {
        {"S010", "Juan Perez", "Basica", 3, 900.00},
        {"S020", "Maria Gomez", "Premium", 6, 1500.00},
        {"S030", "Pedro Diaz", "VIP", 1, 2500.00},
        {"S040", "Juan Perez", "Premium", 5, 1200.00}
    };

    FILE *arch = fopen("archivosocios.dat", "wb");
    if(arch == NULL)
    {
        puts("no se pudo crear el archivo");
        return;
    }

    SOCIO s2 = *(s1);
    int i = 1;
    while(fwrite(&s2, sizeof(SOCIO), 1, arch))
    {
        SOCIO s2 = *(s1+i);
        i++;
    }


}

void guardar_activos(char *tipo_excluido)
{
    FILE *arch_og = fopen("archivosocios.dat", "rb");
    if(arch_og == NULL)
    {
        puts("no se pudo crear el archivo");
        return;
    }

    FILE *arch = fopen("socios.dat", "wb");
    if(arch == NULL)
    {
        puts("no se pudo crear el archivo");
        fclose(arch_og);
        return;
    }

    SOCIO s;
    while(fread(&s, sizeof(SOCIO), 1, arch_og))
        if(strcmp(s.tipo_membresia, tipo_excluido) != 0)
            fwrite(&s, sizeof(SOCIO), 1, arch);

}



