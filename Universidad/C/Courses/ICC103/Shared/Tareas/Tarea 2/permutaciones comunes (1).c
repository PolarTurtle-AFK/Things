
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 1000

void cadenas(char *, char *);
int permutaciones(char *, char *, char *);
void repetidas(char *);
void alfabeto(char *);
void imprimir(char *, char *, char *);
void continuar(char *);

int main()
{
    char str_a[MAX];
    char str_b[MAX];
    char abec[MAX];
    char opcion;

    do
    {
        *abec = '\0';

        cadenas(str_a, str_b);
        if(permutaciones(str_a, str_b, abec))
        {
            repetidas(abec);
            alfabeto(abec);
            imprimir(str_a, str_b, abec);
        }
        else
            puts("\nno hay letras en comun");

        continuar(&opcion);

    }
    while (opcion == 'C');

    puts("Saliendo del programa...");

    return 0;
}

/*
Funcion: cadenas
Objetivo: Lee dos cadenas de texto desde el teclado usando fgets(). Valida que no estén vacías
y elimina manualmente el salto de línea '\n' al final de cada una y si no encuentra el salto
significa que se paso y se limpia el buffer.
*/
void cadenas(char *a, char *b)
{
    int i;
    do
    {
        printf("Digite una cadena: ");
        fgets(a, MAX, stdin);

        if(*a == '\n')
        {
            puts("Debes digitar algo");
            system("pause");
            system("cls");
            continue;
        }

        for(i = 0; *(a+i) != '\n' && *(a+i) != '\0'; i++);

        if(*(a+i) == '\0')
        {
            int c;
            while ((c = getchar()) != '\n' && c != EOF);
        }

        *(a+i) = '\0';

    }
    while(*a == '\0' || *a == '\n');

    do
    {
        printf("Digite otra cadena: ");
        fgets(b, MAX, stdin);

        if(*b == '\n')
        {
            puts("Debes digitar algo");
            system("pause");
            system("cls");
            continue;
        }

        for(i = 0; *(b+i) != '\n' && *(b+i) != '\0'; i++);

        if(*(b+i) == '\0')
        {
            int c;
            while ((c = getchar()) != '\n' && c != EOF);
        }

        *(b+i) = '\0';

    }
    while(*b == '\0' || *b == '\n');
}

/*
Funcion: permutaciones
Objetivo: Compara las letras de la cadena a con la b sin importar las mayúsculas guardaando las comunes en minúscula dentro de la cadena 'c'.
Retorna 1 si encontró algo o 0 si no se encontro ninguna.
*/
int permutaciones(char *a, char *b, char *c)
{
    int i, j, k = 0;

    for(i = 0; *(a+i) != '\0'; i++)
    {

        if( (*(a+i) < 'a' || *(a+i) > 'z') && (*(a+i) < 'A' || *(a+i) > 'Z') ) continue;

        for(j = 0; *(b+j) != '\0'; j++)
            if(strncasecmp(a+i, b+j, 1) == 0)
            {
                if( *(a+i) >= 'A' && *(a+i) <= 'Z' )
                    *(c + k++) = *(a+i) + 32;
                else
                    *(c + k++) = *(a+i);

                break;
            }
    }

    if(*c == '\0')
        return 0;
    else
        *(c + k) = '\0';

    return 1;
}

/*
Funcion: repetidas
Objetivo: Elimina los caracteres duplicados en la cadena c. Al encontrar una copia,
mueve todos los caracteres siguientes un espacio a la izquierda para borrarla.
*/
void repetidas(char *c)
{
    int i, j, k;

    for(i = 0; *(c+i) != '\0'; i++)
        for(j = i+1; *(c+j) != '\0';)
            if(*(c+i) == *(c+j))
                for(k = j; *(c+k) != '\0'; k++)
                    *(c+k) = *(c+k+1);
            else
                j++;
}

/*
Funcion: alfabeto
Objetivo: aqui se organiza alfabeticamente despues de eliminar las repetidas. como el alafabeto va de menor a mayor en
valor ascii (a < b < c...) entonces va de posicion en posicion comparados con los demas y en caso de este ser menor se
cambian de lugar.
*/
void alfabeto(char *c)
{
    int j, k;
    char temp;

    for(j = 0; *(c+j) != '\0'; j++)
        for(k = j + 1; *(c+k) != '\0'; k++)
            if( *(c+j) > *(c+k))
            {
                temp   = *(c+j);
                *(c+j) = *(c+k);
                *(c+k) = temp;
            }

}

/*
Funcion: imprimir
Objetivo: se va contando cuantas veces se repite al letras en la cadena c en las cadenas a y b
y se imprime el texto dependiendo de cuantas veces se repitan.
*/
void imprimir(char *a, char *b, char *c)
{
    int i, j, ka, kb;

    puts("\nPermutaciones Comunes");
    printf("Resultado: %s\n", c);

    for(i = 0; *(c+i) != '\0'; i++)
    {
        for(j = 0, ka = 0; *(a+j) != '\0'; j++)
            if(strncasecmp(a+j, (c+i), 1) == 0)
                ka++;

        for(j = 0, kb = 0; *(b+j) != '\0'; j++)
            if(strncasecmp(b+j, (c+i), 1) == 0)
                kb++;

        if(ka == 1 && kb == 1)
            printf("Letra '%c': aparece %d vez en la cadena \"%s\" y %d vez en la cadena \"%s\"\n", *(c+i), ka, a, kb, b);
        else if(ka == 1 && kb != 1)
            printf("Letra '%c': aparece %d vez en la cadena \"%s\" y %d veces en la cadena \"%s\"\n", *(c+i), ka, a, kb, b);
        else if(ka != 1 && kb == 1)
            printf("Letra '%c': aparece %d veces en la cadena \"%s\" y %d vez en la cadena \"%s\"\n", *(c+i), ka, a, kb, b);
        else
            printf("Letra '%c': aparece %d veces en la cadena \"%s\" y %d veces en la cadena \"%s\"\n", *(c+i), ka, a, kb, b);
    }

}

/*
Funcion: continuar
Objetivo: Pide al usuario 'S' o 'C' para salir o seguir limpiando el buffer,
pasa la respuesta a mayúscula y repite el ciclo si la opción es inválida.
*/
void continuar(char *opcion)
{
    do
    {
        printf("\nPresione 'S' para salir o 'C' para continuar: ");
        scanf(" %c", opcion);

        int c;
        while ((c = getchar()) != '\n' && c != EOF);

        if (*opcion >= 'a' && *opcion <= 'z')
            *opcion -= 32;

        if (*opcion != 'S' && *opcion != 'C')
            printf("Opcion invalida. ");

    }
    while (*opcion != 'S' && *opcion != 'C');

    printf("\n");
}
