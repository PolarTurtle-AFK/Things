#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 1000

void cadenas(char *, char *);

void min(char *, char *);

void confirmar(char *, char *, char *);

void repetidas(char *);

void alfabeto(char *);

void permutaciones(char *, char *, char *);

int main()
{
    char str_a[MAX];
    char str_b[MAX];
    char abec[26];

    cadenas(str_a, str_b);

    /*for(int i = 0; *(str_a+i) != '\0'; i++)
        {
         printf("%c ", *(str_a+i));
        }*/

    /*
    printf("%s", str_a);

    printf("\n");

    printf("%s", str_b);
    */

    //min(str_a, str_b);

    /*
    printf("%s", str_a);

    printf("\n");

    printf("%s", str_b);
    */

    confirmar(str_a, str_b, abec);

    for(int i = 0; *(abec+i) != '\0'; i++)
    {
        printf("%c ", *(abec+i));
    }

    printf("\n");
    repetidas(abec);

    for(int i = 0; *(abec+i) != '\0'; i++)
    {
        printf("%c ", *(abec+i));
    }

    printf("\n");
    alfabeto(abec);

    for(int i = 0; *(abec+i) != '\0'; i++)
    {
        printf("%c ", *(abec+i));
    }

    printf("\n");

    permutaciones(str_a, str_b, abec);


    /*for(int i = 0; *(str_b+i) != '\0'; i++)
        {
         printf("%c ", *(str_b+i));
        }*/

    return 0;
}

void cadenas(char *a, char *b)
{
    int i;
    do
    {
        printf("Digite una cadena: ");
        fgets(a, MAX+1, stdin);

        if(*a == '\n')
        {
            puts("debes digitar algo");
            system("pause");
            system("cls");


            continue;
        }

        for(i = 0; *(a+i) != '\n' && *(a+i) != '\0'; i++);
        *(a+i) = '\0';
        //while(*a != '\n' && *a != '\0') *a++; *a = '\0';
        //strcpy(a+strlen(a)-1, "\0");
    }
    while(*a == '\n');

    do
    {
        printf("Digite otra cadena: ");
        fgets(b, MAX+1, stdin);

        if(*b == '\n')
        {
            puts("debes digitar algo");
            system("pause");
            system("cls");
            continue;
        }

        for(i = 0; *(b+i) != '\n' && *(b+i) != '\0'; i++);
        *(b+i) = '\0';
        //while(*b != '\n' && *b != '\0') *b++; *b = '\0';
        //strcpy(b+strlen(b)-1, "\0");
    }
    while(*b == '\n');
}
/*
void min(char *a, char *b)
{
    int i;

    for(i = 0; *(a+i) != '\0'; i++)
        if( *(a+i) >= 'A' && *(a+i) <= 'Z' )
            *(a+i) += 32;

    for(i = 0; *(b+i) != '\0'; i++)
        if( *(b+i) >= 'A' && *(b+i) <= 'Z' )
            *(b+i) += 32;
}
*/

void confirmar(char *a, char *b, char *c)
{
    int i, j, k = 0;

    for(i = 0; *(a+i) != '\0'; i++)
    {
        if( (*(a+i) < 'a' || *(a+i) > 'z') && (*(a+i) < 'A' || *(a+i) > 'Z')) continue;

        for(j = 0; *(b+j) != '\0'; j++)
            if(strncasecmp(a+i, b+j, 1) == 0)
            {
                if( *(a+i) >= 'A' && *(a+i) <= 'Z' )
                    *(c + k++) = *(a+i) + 32;
                else
                    *(c + k++) = *(a+i);

            }

    }

}

void repetidas(char *c)
{
    int i, j;


    for(i = 0; *(c+i+1) != '\0'; i++)
        for(j = i+1; *(c+j) != '\0'; j++)
            if(*(c+i) == *(c+j))
            {
                strcpy(c+j, c+j+1);
                j--;
            }

}

void alfabeto(char *c)
{
    int i, j, k;
    char temp;

    for(j = 0; j < strlen(c); j++)
        for(k = 0; *(c+k) != '\0'; k++)
        {
            if(k == j) continue;

            if( *(c+j) < *(c+k))
            {
                temp   = *(c+j);
                *(c+j) = *(c+k);
                *(c+k) = temp;
            }
        }

}

void permutaciones(char *a, char *b, char *c)
{
    int i, j, ia, ib;

    puts("Permutaciones Comunes");
    printf("Resultado: %s\n", c);

    while(*c)
    {
        for(i = 0, ia = 0; *(a+i) != '\0'; i++)
            if(strncasecmp(a+i, c, 1) == 0)
                ia++;

        for(i = 0, ib = 0; *(b+i) != '\0'; i++)
            if(strncasecmp(b+i, c, 1) == 0)
                ib++;

        if(ia == 1 && ib == 1)
            printf("Letra '%c': aparece %d vez en \"%s\" y %d vez en \"%s\"\n", *c, ia, a, ib, b);
        else if(ia == 1 && ib != 1)
            printf("Letra '%c': aparece %d vez en \"%s\" y %d veces en \"%s\"\n", *c, ia, a, ib, b);
        else if(ia != 1 && ib == 1)
            printf("Letra '%c': aparece %d veces en \"%s\" y %d vez en \"%s\"\n", *c, ia, a, ib, b);
        else
            printf("Letra '%c': aparece %d veces en \"%s\" y %d veces en \"%s\"\n", *c, ia, a, ib, b);

        *c++;
    }

}

