#include <stdio.h>
#include <stdlib.h>
#include <String.h>

#define MAX 67

void stuff(char *texto, int inicio, int cantidad, char *insertar, char *resultado);

int main()
{
    char texto[MAX] = {"Hola desde el Mundo del Reves"};
    //char texto[MAX] = {"Numero: 000-1234"};
    char insertar[MAX] = {"Hawkins"};
    //char insertar[MAX] = {"809"};
    int inicio = 11;
    //int inicio = 8;
    int cantidad = 18;
    //int cantidad = 3;

    char resultado[MAX];
    printf("%s\n",texto);
    stuff(texto,inicio,cantidad,insertar,resultado);
    printf("%s\n",resultado);
    return 0;
}

void stuff(char *texto, int inicio, int cantidad, char *insertar, char *resultado){
    strcpy(resultado,texto);
    strncpy(resultado+inicio,insertar,cantidad);
}
