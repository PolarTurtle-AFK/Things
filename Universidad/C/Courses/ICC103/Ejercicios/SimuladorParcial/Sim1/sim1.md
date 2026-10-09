Se desea validar si una matriz cuadrada cumple con ciertas condiciones de seguridad. 
Para considerarse segura, los elementos en la diagonal principal deben ser números pares, los elementos por encima de la diagonal deben estar en el intervalo (0, promedio de la diagonal), y los elementos por debajo de la diagonal deben estar en el intervalo (promedio de la diagonal, 2 × promedio de la diagonal).
Realice la función int matriz_Es_Segura(int *m, int orden) que retorne 1 si la matriz cumple con la condición antes planteada y 0 si no cumple con dicha condición.
Ej:
4   3   5
12  6   5
10   12  8
   
Diagonal: 4, 6, 8 todos son pares
Promedio de la diagonal: (4 + 6 + 8) / 3 = 6
Valores por encima de la diagonal: 3, 5, 5, todos están entre 0 y 6
Valores por debajo de la diagonal: 12, 10, 12, todos están entre 6 y 12
La matriz es segura la función debe retornar 1.
 
4   3    7
12  5    9
13  14   6
El 5 no es par, ya con esto la matriz no es segura la función debe retornar 0.