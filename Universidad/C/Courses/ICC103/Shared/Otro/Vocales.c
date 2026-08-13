#include <stdio.h>
#include <stdlib.h>

char *extract_vowels(char *s);

int main()
{
    char s[] = "auiou";
    char *c = extract_vowels(s);

    printf("Texto: \"%s\"\n", s);
    printf("Resultado dinamico: \"%s\"\n", c);

    system("pause");

    return 0;
}

char *extract_vowels(char *s)
{
    char *c = (char *) calloc(1, sizeof(char));

    int i, j;
    for(i = 0, j = 0; *(s+i) != '\0'; i++)
        if(*(s+i) == 'a' || *(s+i) == 'e' || *(s+i) == 'i' || *(s+i) == 'o' || *(s+i) == 'u' || *(s+i) == 'A' || *(s+i) == 'E' || *(s+i) == 'I' || *(s+i) == 'O' || *(s+i) == 'U')
        {
            c = (char *) realloc(c, j+1 * sizeof(char));
            *(c+j++) = *(s+i);
        }

    *(c+j) = '\0';

    return c;
}
