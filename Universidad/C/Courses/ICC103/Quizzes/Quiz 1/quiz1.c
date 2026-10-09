#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void eliminar_fila_columna(int *M, int n, int filaEliminar, int columnaEliminar, int *MRes);
void imprimir(int *m, int mres,int n);


int main()
{
    int n=4;
    int M[n][n];
    int MRes[n-1][n-1];
    int filaEliminar, columnaEliminar;
    printf("\nIngrese la fila a eliminar: ");
    scanf("%d", &filaEliminar);
    printf("\nIngrese la columna a eliminar: ");
    scanf("%d", &columnaEliminar);

    eliminar_fila_columna(&M[0][0],n,filaEliminar,columnaEliminar, &MRes[0][0]);
    system("PAUSE");
    return 0;
}

void eliminar_fila_columna(int *M, int n, int filaEliminar, int columnaEliminar, int *MRes){
    int contador=0;
    for(int i=0; i<n;i++){
        for(int j=0; j<n; j++){
            contador++;
            *(M+i*n+j)=contador;
        }
        printf("\n");
    }
    for(int i=0; i<n;i++){
        for(int j=0; j<n; j++){
            printf("%4d ", *(M+i*n+j));
        }
        printf("\n");
    }
    printf("\n\n\n");

    int temp;
    for(int i=0; i<n;i++){
        for(int j=0; j<n; j++){
            *(MRes+i*n-1+j) = *(M+i*n+j);
            if ((i==filaEliminar) || (j==columnaEliminar)){
                *(MRes+i*n-1+j) = 0;
            }
        }
    }
    for(int i=0; i<n;i++){
        for(int j=0; j<n; j++){
            printf("%4d ", *(MRes+i*n-1+j));
        }
        printf("\n");
    }

}

void imprimir(int *m, int mres,int n){

}
