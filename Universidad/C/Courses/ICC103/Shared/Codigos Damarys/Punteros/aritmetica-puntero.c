#include<stdio.h>
#include<stdlib.h>

int main()
{
    int v[10]={100,101,102,103,104,105,106,107,108,109}, *p, i;

    p=v; //p =&v[0];

    for(i=0;i<10;i++)
    {
        printf("\n%d\t",v[i]);
        printf("%d %d %d\n",*v,*(v+i),(v+i));
    }

    printf("\nAccediendo desde el puntero P\n");
    for(i=0;i<10;i++)
        printf("%d %d %d\n",*p,*(p+i),(p+i));

    //v = &i; PRUEBEN ESTO, DEBE DAR ERROR porque no se modifica
            //la dirección de memoria de un puntero y recordar
            //que el arreglo v es en sí un puntero a la dirección
            //en memoria del primer elemento, es decir --> &v[0]
    system("PAUSE");
    return 0;

}
