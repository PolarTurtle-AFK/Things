/*
Escriba una función void clean_echo(char *s) que reciba una cadena de caracteres
y elimine cualquier letra que aparezca de forma consecutiva e idéntica,
dejando únicamente una sola ocurrencia de dicho carácter.

Por ejemplo:

"preeeettttyy"   --> "pretty"

"waaalkkiing"    --> "walking"

"hheellllooooo" --> "hello"



Está estrictamente prohibido utilizar corchetes [] dentro de la función.
No está permitido declarar arreglos secundarios.  
Se debe modificar el string sobre su propio bloque de memoria.


*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void clean_echo(char *);

int main()
{
    char mensaje[100] = "preeeettttyy";

    printf("Original: %s\n", mensaje);
    clean_echo(mensaje);
    printf("Limpio:   %s\n\n", mensaje);

    strcpy(mensaje,"waaalkkiing");
    printf("Original: %s\n", mensaje);
    clean_echo(mensaje);
    printf("Limpio:   %s\n\n", mensaje);

    strcpy(mensaje,"hheellllooooo");
    printf("Original: %s\n", mensaje);
    clean_echo(mensaje);
    printf("Limpio:   %s\n\n", mensaje);

    system("PAUSE");
    return 0;
}
void clean_echo(char *s)
{
    if (*s == '\0')
        return;

    int i, j = 1;

    for (i = 1; *(s + i) != '\0'; i++)
    {
        if (*(s + i) != *(s + (j - 1)))
        {
            *(s + j) = *(s + i);
            j++;
        }
    }

    *(s + j) = '\0';
}
