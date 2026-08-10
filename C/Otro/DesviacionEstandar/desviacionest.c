#include <stdio.h>
#include <stdlib.h>
#include <math.h> //libreria para sqrt
#define MAX 100

//Asignacion#4
//Programa modular para calculo de desviacion estandar.
//Trabajo realizado con orgullo :)
//profe arregleme la nota en los otros ejercicios porfavor speed i need this


/*leer datos
calcular suma
calcular promedio
calcular desviacion
calcular sumacuadrados
imprimir resultados*/

float calcularSuma(float numeros[], int n);
float calcularPromedio(float suma, int n);
float calcularDesviacion(float numeros[], int n, float promedio);
float calcularSumaCuadrados(float numeros[], int n, float promedio);
void imprimir(float suma, float sumaCuadrados, float promedio, float desviacionest);

int main(){ //variables

    float numeros[MAX];
    int n = 0;
    char respuesta;

    float suma = 0;
    float promedio = 0;

    float sumaCuadrados = 0;
    float desviacionest;

//Ingresar numeros mientras la respuesta sea "s" o "S"
    do{
        if (n>=MAX) { //limite
            printf("\nLimite alcanzado!\n");
            break;
        }

        printf("Ingrese un numero\n");
        scanf("%f", &numeros[n]);
        n++; //a�adir al array
        printf("desea continuar? (s/n) \n");
        scanf(" %c", &respuesta);

    } while (respuesta == 's' || respuesta == 'S');

//llamar funciones
    suma = calcularSuma(numeros, n);
    promedio = calcularPromedio(suma, n);
    desviacionest = calcularDesviacion(numeros, n, promedio);
    sumaCuadrados = calcularSumaCuadrados(numeros,n,promedio);
    imprimir(suma, sumaCuadrados, promedio, desviacionest);
}

float calcularSuma(float numeros[], int n){ //suma numeros a variable
    float suma = 0;
    for (int i = 0; i < n; i++){
        suma += numeros[i];
    }
    return suma;
}

float calcularPromedio(float suma, int n) { //suma entre n = promedio
    if (n == 0) {
        return 0;   // evitar division entre cero
    }
    return suma / n;
}

float calcularDesviacion(float numeros[], int n, float promedio) { //calcula con sqrt varianza
    if (n == 0) //por si n = 0 para evitar errores
        return 0;
    float cuadrado = 0;
    float sumaCuadrados = 0;

    for (int i = 0; i < n; i++) {

        float diferencia = numeros[i] - promedio;
        cuadrado = (diferencia * diferencia);
        sumaCuadrados += cuadrado;

        printf("\nEntrada %d \nN�mero = %g\n", (i+1), numeros[i]);
        printf("Ni-Prom es %.2f\n", diferencia);
        printf("(Ni-Prom)^2 es %.2f\n", cuadrado);
        }


    float varianza = sumaCuadrados / n;
    return sqrt(varianza); //sqrt = square root
}

float calcularSumaCuadrados(float numeros[], int n, float promedio) { //calcula suma total de (ni-prom)^2
    float sumaCuadrados = 0;

    for (int i = 0; i < n; i++) {
        float diferencia = numeros[i] - promedio;
        sumaCuadrados += diferencia * diferencia;
    }

    return sumaCuadrados;
}

void imprimir(float suma, float sumaCuadrados, float promedio, float desviacionest){ //imprime resultados
    printf("\nResultados:\n");
    printf("Suma total: %g\n", suma);
    printf("Suma total cuadrados: %g\n", sumaCuadrados);
    printf("Promedio: %.2f\n", promedio);
    printf("Desviacion estandar: %.2f\n", desviacionest);
}
