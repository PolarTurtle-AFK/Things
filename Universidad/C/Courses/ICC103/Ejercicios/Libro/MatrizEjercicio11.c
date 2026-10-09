#include <stdio.h>
#define MAX 2
//int matriz_numerica(char mat[][MAX],int filas, int columnas);
int matriz_numerica(char *,int filas, int columnas);
int main(){
    return 0;
}
int matriz_numerica(char *mat,int filas, int columnas){
//    *(M+F*COLS+C)
    for(int f=0;f<filas;f++){
        for(int c=0;c<columnas;c++){
            if(*mat+f+columnas+c);
        }
    }
}