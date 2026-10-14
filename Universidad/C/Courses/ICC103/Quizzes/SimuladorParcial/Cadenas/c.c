#include <stdio.h>
#include <string.h>

void elimina_esp_demas(char *s){
    char *r=s;
    char *p=s;
    int espacio =0;
    while(*r!='\0'){
        if(*r ==' '){
            if(!espacio){
            *p = *r;
            p++;
            espacio=1;
            }
        }else{
            *p = *r;
            p++;
            espacio=0;
        }
        r++;
    }
    *p='\0';
    printf("%s",s);
}

void delete_Word(char *s, char *w){

    char *p = s;

    while(*p != '\0'){

        if(*(p-1) == ' ' || p == s){
            char inicio = p;
            char *q = p;

            while(*q != ' ' && *q != '\0'){
                q++;
            }

            int iguales = 1;
            char *a = inicio;
            char *b = w;
        }
        p++;
    }
}
int son_Anagramas(char *s1, char *s2){

}

int main(){

    char texto1[100] = "La    casa     azul   es bonita";
    char texto2[100] = "La casa amarilla";
    char palabra[20] = "la";

    char s1[100] = "Tom Marvolo Riddle";
    char s2[100] = "I am lord Voldemort";

    printf("1. Eliminar espacios de mas:\n");
    elimina_esp_demas(texto1);

    printf("\n2. Eliminar palabra:\n");
    delete_Word(texto2, palabra);
    printf("%s\n", texto2);

    printf("\n3. Anagramas:\n");
    if(son_Anagramas(s1, s2)){
        printf("Son anagramas\n");
    }
    else{
        printf("No son anagramas\n");
    }

    return 0;
}
