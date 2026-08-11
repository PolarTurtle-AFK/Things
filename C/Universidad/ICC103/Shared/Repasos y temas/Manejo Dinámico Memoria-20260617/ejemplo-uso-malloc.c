#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
    char *s;
    int *num;

    num=(int *)malloc(10*sizeof(int));
    //*num=100;
    printf("\nDireccion en Memoria: %d\n",num);

    s=(char *)calloc(10,sizeof(char));
    strcpy(s,"Mauricio");

    puts(s);

    free(s);
    free(num);
    system("PAUSE");
    return 0;
}
