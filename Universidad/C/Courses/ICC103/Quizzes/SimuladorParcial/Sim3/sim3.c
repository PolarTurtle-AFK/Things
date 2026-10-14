#include <stdio.h>
#include <string.h>
#include <ctype.h>
int son_Anagramas(char *s1,char *s2);

int main(){
    char texto[100] = "Tom Marvolo Riddle";
    char texto2[100] = "I am lord voldemort";

    son_Anagramas(texto,texto2);
    return 0;
}

int son_Anagramas(char *s1,char *s2){
    int contador=0;

    s1 = tolower(*s2);
    s2 = tolower(*s1);
    char *c=s1;
    char *p=s2;
    if(strlen(s1) != strlen(s2)){
        printf("NO SON DEL MISMO TAMAÑO");
        return 0;
    }
    for(int len=0; len < strlen(s1); len++){
        for(int len2=0; len2<strlen(s2); len2++){
            
            if(*(c+len)==*(p+len2)){
                contador++;
            }
        }
    }
    if(contador==strlen(s1)){
        printf("TIENE LA MISMAS CANTIDAD DE LETRAS QUE LA OTRA");
        return 1;
    }else{
        printf("%d de %d",contador,strlen(s2));
        return 0;
    }
}