/*
Escriba una función filter_message(char *s) que reciba una cadena de caracteres
y elimine todos los caracteres que NO sean letras minúsculas (de la 'a' - 'z'),
modificando la cadena original directamente en la memoria.

Por ejemplo:

"p1r3e_t_t_y"       -->  "pretty"

"w4a3l_k1i_n_g"  -->  "walking"

"abc123XYZ"       -->  "abc"

Está estrictamente prohibido utilizar corchetes [] dentro de la función.
No está permitido declarar arreglos secundarios.
Se debe modificar el string sobre su propio bloque de memoria.
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void filter_message(char *);


int main()
{
    char mensaje[100] = "w4a3l_k1i_n_g";

    printf("Original: %s\n", mensaje);
    filter_message(mensaje);
    printf("Limpio:   %s\n\n", mensaje);

    strcpy(mensaje,"p1r3e_t_t_y");
    printf("Original: %s\n", mensaje);
    filter_message(mensaje);
    printf("Limpio:   %s\n\n", mensaje);

    strcpy(mensaje,"abc123XYZ");
    printf("Original: %s\n", mensaje);
    filter_message(mensaje);
    printf("Limpio:   %s\n\n", mensaje);

    system("PAUSE");
    return 0;
}
void filter_message(char *s)
{
    int i, j = 0;

    for (i = 0; i < strlen(s) ; i++)
        for (i = 0; *(s + i) != '\0'; i++)
        {
            if (*(s + i) >= 'a' && *(s + i) <= 'z')
            {
                *(s + j) = *(s + i);
                j++;
            }
        }

    *(s + j) = '\0';
}


