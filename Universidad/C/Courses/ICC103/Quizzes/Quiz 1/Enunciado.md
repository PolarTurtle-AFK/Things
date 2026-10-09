Dada una matriz cuadrada de tamaño N x N. Realice un programa en C que contenga una función:

 

void eliminar_fila_columna (int *M, int n, int filaEliminar, int columnaEliminar, int *MRes);

 

Que permita generar en resultado la matriz de tamaño (N-1) x (N-1) resultante de eliminar la fila filaEliminar y la columna columnaEliminar de la matriz original. Cada elemento conservado debe reubicarse en su nueva posición dentro de resultado, manteniendo el orden relativo de los demás elementos.

 

Ejemplo de corrida:

 

   1   2   3   4

   5   6   7   8

   9  10  11  12

  13  14  15  16

 

Ingrese la fila a eliminar: 2

Ingrese la columna a eliminar: 1

 

Resultado de eliminar fila 2 y columna 1:

 

   1   3   4

   5   7   8

  13  15  16

 

Press any key to continue . . .