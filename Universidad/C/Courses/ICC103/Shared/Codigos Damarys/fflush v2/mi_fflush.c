#include<stdio.h>
#include<stdlib.h>

void mi_fflush();

int main()
{


    system("PAUSE");
    return 0;
}
//Funcion: mi_fflush
//Limpiar el buffer
void mi_fflush()
{
    int c;
    while((c=getchar())!='\n' && c!=EOF)
    {
    }
}


