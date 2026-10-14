#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int son_Anagramas(char *, char *);
int son_Anagramas_arreglo(char *, char *);
char convertir_Minusculas(char);

int main()
{

    char s1[]={"Tom Marvolo Riddle"}; //"Tom Marvolo Riddle" Anita
    char s2[]={"I Am Lord Voldemort;"}; //"I Am Lord Voldemort" tania;

    puts(s1);
    puts(s2);

    if (son_Anagramas_arreglo(s1, s2))
        printf("SON anagramas.\n\n");

    else
        printf("NO son anagramas.\n\n");

    if (son_Anagramas(s1, s2))
        printf("SON anagramas.\n\n");

    else
        printf("NO son anagramas.\n\n");

    system("pause");
    return 0;
}

char convertir_Minusculas(char c)
{
    if (c >= 'A' && c <= 'Z')
        return c + 32;

    return c;
}

int son_Anagramas_arreglo(char *s1, char *s2)
{
    int contador[26], i;
    char c;

    for (i = 0; i < 26; i++)
        *(contador + i) = 0;

    for (i = 0; *(s1 + i) != '\0'; i++)
    {
        c = convertir_Minusculas(*(s1 + i));
        if (c >= 'a' && c <= 'z')
            *(contador + (c - 'a')) += 1;
    }

    for (i = 0; *(s2 + i) != '\0'; i++)
    {
        c = convertir_Minusculas(*(s2 + i));
        if (c >= 'a' && c <= 'z')
            *(contador + (c - 'a')) -= 1;
    }

    for (i = 0; i < 26; i++)
    {
        if (*(contador + i) != 0)
            return 0;
    }

    return 1;
}

int son_Anagramas(char *s1, char *s2)
{
    int i, j;
    int ya_vista;
    int en_s1, en_s2;
    int total1, total2;
    char c;

    total1 = 0;

    for (i = 0; *(s1 + i) != '\0'; i++)
    {
        c = convertir_Minusculas(*(s1 + i));

        if (c >= 'a' && c <= 'z')
        {
            total1++;

            // Revisa si esta letra ya se comparo antes (aparece en una posicion anterior de s1)
            ya_vista = 0;
            for (j = 0; j < i; j++)
            {
                if (convertir_Minusculas(*(s1 + j)) == c)
                    ya_vista = 1;
            }

            if (!ya_vista)
            {
                // Cuenta cuantas veces aparece la letra en cada cadena
                en_s1 = 0;
                en_s2 = 0;

                for (j = 0; *(s1 + j) != '\0'; j++)
                {
                    if (convertir_Minusculas(*(s1 + j)) == c)
                        en_s1++;
                }

                for (j = 0; *(s2 + j) != '\0'; j++)
                {
                    if (convertir_Minusculas(*(s2 + j)) == c)
                        en_s2++;
                }

                if (en_s1 != en_s2)
                    return 0;
            }
        }
    }

    // Si todas las letras de s1 coinciden en cantidad, s2 no puede tener letras de mas
    // si el total de letras de ambas cadenas es el mismo.
    total2 = 0;

    for (i = 0; *(s2 + i) != '\0'; i++)
    {
        c = convertir_Minusculas(*(s2 + i));

        if (c >= 'a' && c <= 'z')
            total2++;
    }

    return (total1 == total2);
}

