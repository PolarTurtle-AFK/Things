#include <stdio.h>
#include <string.h>
#define MAX 100

void eliminar_repetidos_consecutivos(char *s){
    char *p=s;
    char *e = s+1;
    while (*p != '\0'){
        if(*p != *e){
            p++;
            *p = *e;
        }
        e++;
    }
    *(p+1)='\0';
}

int reemplazar_subcadena(char *s, char *sub, char c){
    int long_sub = strlen(sub);

    char *p = s;

    while (*p != '\0')
    {
        if(strncmp(p,sub,long_sub)==0){
            *p = c;
            strcpy(p+1,p+long_sub);
        }
        p++;
    }
}

void eliminar_subcadena(char *s, char *sub){
    char *p = s;
    while (*p != '\0')
    {
        if(strncmp(p,sub,strlen(sub))==0){
            strcpy(p,p+strlen(sub));
        }
        else{
            p++;
        }
    }
    
}

void agregar_subcadena(char *s, char *sub, int n){
    char *p = s;
    char *r = s;

    for (int i=0; i<n; i++){
        *r++;
    }
    while (*p != '\0')
    {
        p++;
    }
    while (p>=r){
        *(p + strlen(sub)) = *p;
        p--;
    }
    strncpy(r, sub, strlen(sub));
}
int main(){

    char s[MAX] = {"HOLA MUNDOOOOOOOO CRUEL"};

    puts(s);
    reemplazar_subcadena(s,"CRUEL",'X');
    eliminar_subcadena(s,"HOLA");
    agregar_subcadena(s,"XD",5);    
    puts(s);


    // for (i = 0; *(s + i) != '\0'; i++)
    // {
    //     return 1;
    // }

    // char *p = s;
    // while (*p != '\0')
    // {
    //     // hacer algo con *p
    //     p++;
    // }
}
