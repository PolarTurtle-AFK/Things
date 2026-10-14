#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int count_lines_starting_with(char *filename, char *prefijo);

int main()
{
    char bien[] = "Parcial";
    char mal[] = "Examen";

    printf("El prefijo \"%s\" aparece al inicio de %d lineas del archivo.\n", bien, count_lines_starting_with("datos.txt", bien));
    printf("El prefijo \"%s\" aparece al inicio de %d lineas del archivo.\n", mal, count_lines_starting_with("datos.txt", mal));
    system("pause");

    return 0;
}

int count_lines_starting_with(char *filename, char *prefijo)
{
    FILE *ach = fopen(filename, "r");

    if(ach == NULL)
    {
        puts("No se pudo abrir el archivo");
        system("pause");
        return -1;
    }

    char *s;
    s = (char *) malloc(50 * sizeof(char));

    int c = 0;

    while(fgets(s, 50, ach) != NULL)
    {
        if(strncmp(s, prefijo, strlen(prefijo)) == 0)
        {
            c++;
        }

    }

    fclose(ach);
    free(s);

    return c;
}
