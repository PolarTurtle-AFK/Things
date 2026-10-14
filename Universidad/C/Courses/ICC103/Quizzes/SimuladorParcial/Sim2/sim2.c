/*Realice una función void delete_Word(char *s, char *w) que eliminará la palabra W del texto S. Tomar en cuenta las palabras solo se separan por espacio en blanco.  (Ignorar mayúsculas y minúsculas).
Ej:
 
Si s = "La casa amarilla", y w="la"
delete_Word (s, w) el texto cambiará y quedará " casa amarilla", nótese que "la" de amarilla no se elimina.*/

#include <stdio.h>
#include <string.h>

void delete_Word(char *s, char *w);

int main(){
    char s[67] = "La casa amarilla";
    char w[20] = "la";

    printf("Antes: %s\n", s);

    delete_Word(s, w);

    printf("Despues: %s\n", s);
    return 0;
}

void delete_Word(char *s, char *w){
    char *p=s;
    char *f;

    while (*p != '\0'){
        while (*p == ' '){
            p++;
        }
        f = p;

        while(*f != '\0' && *f != ' '){
            f++;
        }
        p = f;
    }
}