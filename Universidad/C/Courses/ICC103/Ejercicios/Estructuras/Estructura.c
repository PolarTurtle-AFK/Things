#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char Nombre[20];                //1
} Universidad;
    
typedef struct{
    char Nombre[20];                //1
    char Apellido[20];              //2
    Universidad Universidad;        //3

} Datos;

void print_persona(Datos);

int main(){
    Datos Persona;

    printf("Nombre: ");
    gets(Persona.Nombre);
    printf("Apellido: ");
    gets(Persona.Apellido);
    printf("Universidad: ");
    gets(Persona.Universidad.Nombre);

    print_persona(Persona);
    return 0;
}

void print_persona(Datos p){
    printf("\nUsuario: %s %s, Estudia en: %s", p.Nombre, p.Apellido, (strcmp(p.Universidad.Nombre, "PUCMM") == 0 ? "PUCAMAIMA" : p.Universidad.Nombre));
}