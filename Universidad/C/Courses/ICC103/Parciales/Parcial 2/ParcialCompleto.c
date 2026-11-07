#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct
{
    char titulo[50];
    char autor[40];
    int anio;
    int disponible;
}LIBRO;

char *cutword(char *, int i, int f);
int strcmp_ignore_spaces(char *s1, char *s2);
LIBRO *buscar_disponibles(LIBRO *, int n, char *autor, int *cant);
int count_word_in_file(char *filename, char *word);

int main(){

    char *palabra;
    palabra = cutword("Hola Mundo", 5,9);
    if (palabra != NULL){
        printf("%s bytes: %zu\n", palabra, strlen(palabra));
        free(palabra);
    }


    int num = strcmp_ignore_spaces("Buena Suerte en el parcial de Fundamentos", "BuenaSuerteenelparcialdeFundamentos");
    printf("%d\n",num);

    LIBRO catalogo[3] = {
        {"Skibidi","Tung",1967,1},
        {"Skibidi toilet","Skibidi",1967,1},
        {"toilet","Tung",1967,1}
    };

    LIBRO *libautor;
    int cant = 0;
    libautor = buscar_disponibles(catalogo, 3, "Tung", &cant);
    if (libautor!=NULL)
    {
        printf("%d libros\n", cant);
    }

    int retorna = count_word_in_file("texto.txt", "parcial");
    if (retorna ==-1){
        printf("No se pudo abrir el archivo");
    }else{
        printf("Cantidad de palabra: %d", retorna);
    }

    return 0;
}

char *cutword(char *word, int i, int n){

    if (i<0 || i > n || n >= strlen(word)){
        return NULL;
    }

    char *palabra;
    palabra = (char *)calloc(n-i+2,sizeof(char));

    strncpy(palabra,word+i,n-i+1);
    puts(palabra);
    *(palabra+n-1+2) = '\0';
    return palabra;
}

int strcmp_ignore_spaces(char *s1, char *s2){
    if (*(s1+1)=='\0' && *(s2+1)=='\0'){
        return 0;
    }

    if (*(s1) == ' '){
        return strcmp_ignore_spaces(s1+1,s2);
    }else if (*(s1)==*(s2)){
        return strcmp_ignore_spaces(s1+1,s2+1);
    }else return 1;
}

LIBRO *buscar_disponibles(LIBRO *catalogo, int n, char *autor, int *cant){
    LIBRO *libautor;
    *cant=0;
    for (int i = 0; i < n; i++)
    {
        if ((catalogo+i)->disponible == 1){
            if(strcmp((catalogo+i)->autor,autor)==0){
                (*cant)++;
            }
        }
    }

    if (*cant==0){
        return NULL;
    }
    libautor = (LIBRO *)calloc(*cant,sizeof(LIBRO));
    if(libautor==NULL){
        *cant=0;
        return NULL;
    }

    for (int j = 0, i = 0; i < n; i++)
    {
        if ((catalogo+i)->disponible == 1){
            if((strcmp((catalogo+i)->autor,autor)==0)){
                *(libautor+j) = *(catalogo+i);
                j++;
            }
        }
    }
    return libautor;
}

int count_word_in_file(char *filename, char *word){
    FILE *archivo;
    char s[512], *p, antes, desp;//
    int tam = strlen(word);//
    archivo = fopen(filename, "r");
    if (archivo==NULL){
        return -1;
    }

    int cont=0;
    while (fgets(s,sizeof(s),archivo)){
        p = s;
        while ((p=strstr(p,word)) != NULL)
        {
            if(p==s){
                antes = ' ';
            }else
                antes = *(p-1);
            desp = *(p+tam);
            if ((antes == ' ' || antes == ',' || antes == '.' || antes== ';' || antes== ':') &&
                 (desp == ' ' || desp == ',' || desp == '.' || desp== ';' || desp== ':' || desp== '\n' || desp== '\0'))
            {
                cont++;
            }
            p+=tam;
        }
    }
    fclose(archivo);
    return cont;
}
