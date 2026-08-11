#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int es_subsecuencia(char *s1, char *s2);

int main()
{
    char s1[] = "acz";
    char s2[] = "abcde";

    printf("s1 = \"%s\" | s2 = \"%s\"\n", s1, s2);
    if(es_subsecuencia(s1, s2))
        puts("SI es subsecuencia");
    else
        puts("NO es subsecuencia");

    system("pause");

    return 0;
}

int es_subsecuencia(char *s1, char *s2)
{
    if(*s1 == '\0')
        return 1;
    else if(*s2 == '\0')
        return 0;

    if(strchr(s2, *s1) != NULL)
        return es_subsecuencia(s1+1, s2+1);
    else
        return es_subsecuencia(s1, s2+1);
}
