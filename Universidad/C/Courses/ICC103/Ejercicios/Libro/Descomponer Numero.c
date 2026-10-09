#include <stdio.h>

int main() {
    int numero, digito, contador = 0;

    printf("Ingrese un numero entero: ");
    scanf("%d", &numero);

    printf("Los digitos del numero %d son:\n", numero);
    
    while (numero > 0) {
        digito = numero % 10;
        printf("%d\n", digito);
        numero /= 10; 
        contador++;
    }

    printf("Y tiene: %d digitos\n", contador);
    return 0;
}
