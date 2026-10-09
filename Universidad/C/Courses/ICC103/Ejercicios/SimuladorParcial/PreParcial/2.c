#include <stdio.h>

void elimina_esp_demas(char *s){
    char *p = s;
    char *q = s;
    int espacio = 0;

    while (*p != '\0'){
        if (*p == ' '){
            if(!espacio){
                *q = ' ';
                q++;
                espacio=1;
            }
        }
        else{
            *q=*p;
            q++;
            espacio=0;
        }
        p++;
    }
    *q = '\0';
    printf("%s\n", s);
}

int main(){
    char s[] = {"La    casa   azul   es    bonita   \0"};
    elimina_esp_demas(s);
    return 0;
}