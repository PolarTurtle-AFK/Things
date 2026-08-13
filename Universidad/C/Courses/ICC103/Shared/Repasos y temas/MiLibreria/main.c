#include <stdio.h>
#include <stdlib.h>
#include "estudiante.h"
#include "profesor.h"

int main()
{

    print_mensaje();
    menu();
    printf("\nCalif final %.1f\n",promedio(88.5,62.3));
    return 0;
}
