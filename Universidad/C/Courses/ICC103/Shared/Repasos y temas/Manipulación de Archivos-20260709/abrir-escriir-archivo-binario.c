/*Se dispone de una muestra de las coordenadas de puntos de un plano representada por pares de números enteros (x,y). Se desea guardar en un archivo binario estos puntos.
*/

#include <stdio.h>
struct punto
{
    int x,y;
};
typedef struct punto PUNTO;
int main()
{
    PUNTO p;
    char *nom="puntos.DAT";
    FILE *pp;

    if ((pp=fopen(nom,"a+b"))==NULL)
    {
        puts("Error abriendo archivo");
        return 0;
    }
    puts("\n Introduce las coordenadas, para finalizar (0 0) ");
    do
    {
        scanf("%d %d",&p.x,&p.y);
        while(p.x <0 || p.y <0)
        {
            printf("\n Coordenadas deben ser >=0 ");
            scanf("%d %d",&p.x,&p.y);
        }
        if( p.x >0 || p.y >0)
        {
            fwrite(&p,sizeof(PUNTO),1,pp);
        }
    } while (p.x >0 || p.y >0);

    fclose(pp);

    if ((pp=fopen(nom,"rb"))==NULL)
    {
        puts("\n Error abriendo archivo");
        return 0;
    }
    else
    {
        //mientras no sea fin de archivo
        while(!(feof(pp)))
        {
            //leer el contenido del archivo y asignar
            //a la estructura p, en este caso las coordenadas
            //x,y
            if(fread(&p,sizeof(PUNTO),1,pp))
            {
                printf("Coordenadas: %d, %d\n",p.x,p.y);
            }
        }
    }
    fclose(pp);
    return 0;
}


