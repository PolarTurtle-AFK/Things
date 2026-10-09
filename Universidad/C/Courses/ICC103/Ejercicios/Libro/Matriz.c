#include <stdio.h>

void mostrar(int *matriz, int filas, int columnas) {
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            printf("%d ", *(matriz + i * columnas + j));
        }
        printf("\n");
    }
}


void espejo(int *matriz, int filas, int columnas, int tipo) {
    if (tipo ==1){
        for (int i =0; i<filas/2; i++){
            for (int j=0; j<columnas; j++){
                int temp = *(matriz+i*columnas+j);
                *(matriz+i*columnas+j) = *(matriz+(filas-1-i)*columnas+j);
                *(matriz+(filas-1-i)*columnas+j) = temp;
            }
        }
    }else{
        for (int i = 0; i < filas; i++) {
            for (int j = 0; j < columnas / 2; j++) {

                int temp = *(matriz + i * columnas + j);

                *(matriz + i * columnas + j) =
                    *(matriz + i * columnas + (columnas - 1 - j));

                *(matriz + i * columnas + (columnas - 1 - j)) = temp;
            }
        }
    }

}

void espejoHorizontal(int *matriz, int filas, int columnas) {
    for (int i = 0; i < filas / 2; i++) {
        for (int j = 0; j < columnas; j++) {

            int temp = *(matriz + i * columnas + j);

            *(matriz + i * columnas + j) =
                *(matriz + (filas - 1 - i) * columnas + j);

            *(matriz + (filas - 1 - i) * columnas + j) = temp;
        }
    }
}

void sumar(int *matriz1, int *matriz2, int *resultado,
           int filas, int columnas) {

    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {

            *(resultado + i * columnas + j) =
                *(matriz1 + i * columnas + j) +
                *(matriz2 + i * columnas + j);
        }
    }
}

int main() {

    int matriz1[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    int matriz2[3][3] = {
        {9, 8, 7},
        {6, 5, 4},
        {3, 2, 1}
    };

    int resultado[3][3];

    printf("MATRIZ 1\n");
    mostrar(&matriz1[0][0], 3, 3);

    printf("\nMATRIZ 2\n");
    mostrar(&matriz2[0][0], 3, 3);

    printf("\nESPEJO VERTICAL DE MATRIZ 1\n");
    espejo(&matriz1[0][0], 3, 3,1);
    mostrar(&matriz1[0][0], 3, 3);

    printf("\nESPEJO HORIZONTAL DE MATRIZ 1\n");
    espejo(&matriz1[0][0], 3, 3,-1);
    mostrar(&matriz1[0][0], 3, 3);

    printf("\nSUMA DE MATRICES\n");
    sumar(
        &matriz1[0][0],
        &matriz2[0][0],
        &resultado[0][0],
        3,
        3
    );

    mostrar(&resultado[0][0], 3, 3);

    return 0;
}