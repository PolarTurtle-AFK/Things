#include <stdio.h>
#include <stdlib.h>
void suavizar (int filas, int columnas, int *M, int *R);
int main()
{
    int filas=3;
    int columnas=3;
    int M[3][3] ={10,20,30,40,50,60,70,80,90};

    int R[3][3];
    suavizar(filas,columnas,&M[0][0],&R[0][0]);
    return 0;
}

void suavizar (int filas, int columnas, int *M, int *R){
    float promedio=0;
    for(int i=0; i<filas; i++){
        promedio=0;
        for (int j=0; j<columnas; j++){

            promedio += *(M+i*columnas+j+columnas);
            promedio += *(M+i*columnas+j-columnas);
            promedio += *(M+i*columnas+j+1);
            promedio += *(M+i*columnas+j-1);
            for (int f=0; f<filas; f++){
                promedio += *(M+i*columnas+i);
                promedio += *(M+i*columnas-i);
            }
            promedio /= 8;

            *(R+i*columnas+j) = promedio;
            printf("%d ",*(R+i*columnas+j));

        }
        printf("\n");
    }
}

