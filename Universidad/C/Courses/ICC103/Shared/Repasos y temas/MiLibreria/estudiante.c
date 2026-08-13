#include<stdio.h>
#include<stdlib.h>
#include "estudiante.h"

void print_mensaje()
{
    printf("\nBienvenidos estudiantes de Fundamentos\n");
    system("PAUSE");
}
float promedio(float promparcial, float exfinal)
{
    return (promparcial*.7) + (exfinal *.3);
}
