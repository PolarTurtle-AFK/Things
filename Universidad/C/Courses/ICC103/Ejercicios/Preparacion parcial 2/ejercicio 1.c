/*
Simulacro 3 (estilo Parcial 1)

1. Recursividad
Un sistema de seguridad valida códigos numéricos. Un código es válido si, leyendo sus dígitos de izquierda a derecha, 
cada dígito es mayor que el anterior o es el mismo dígito repetido exactamente una vez seguida (nunca tres veces seguidas). 
Realice un programa en C con una función recursiva int validar(int codigo) que retorne 1 si el código es válido y 0 si no. 
No se permiten ciclos ni arreglos.

Código: 1224   Resultado: 1   (el 2 se repite 2 veces)
Código: 1222   Resultado: 0   (el 2 aparece 3 veces seguidas)
Código: 1325   Resultado: 0   (3 > 2 rompe el orden)
Código: 7      Resultado: 1
*/

#include <stdio.h>

int validar(int codigo);

int main(){
    int res;
    res = validar(1224);
    printf("RESULTADO: %d\n", res);
    res = validar(1222);
    printf("RESULTADO: %d\n", res);
    res = validar(1325);
    printf("RESULTADO: %d\n", res);
    res = validar(7);
    printf("RESULTADO: %d\n", res);
    return 0;
}

int validar(int codigo){
    if (codigo <100){
        return 1;
    }

    int ultimo = codigo%10;
    int anterior = (codigo/10)%10;
    int anteanterior = (codigo/100)%10;

    if (ultimo < anterior){
        return 0;
    }
    if (ultimo == anterior && anterior == anteanterior){
        return 0;
    }
    return validar(codigo/10);
}
