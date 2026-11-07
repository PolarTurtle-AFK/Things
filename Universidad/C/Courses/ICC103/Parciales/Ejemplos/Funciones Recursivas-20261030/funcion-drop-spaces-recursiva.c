#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void drop_spaces(char *s);

int main(void)
{
    char cadena[] = "   Este    texto    no puede tener espacios     demas    ";

    printf("Texto Original: \"%s\"",cadena);

    drop_spaces(cadena);
    printf("\n\nTexto modificado: \"%s\"\n\n",cadena);

    system("pause");
    return 0;
}

void drop_spaces(char *s)
{
    if (*s == '\0')
        return;

    if (*s == ' ' && *(s-1) == '\0')
    {
        strcpy(s, s + 1);
        drop_spaces(s);
    }
    if (*s == ' ' && (*(s + 1) == ' ' || *(s + 1) == '\0'))
    {
        strcpy(s, s + 1);
        drop_spaces(s);
    }
    else
        drop_spaces(s + 1);
}
