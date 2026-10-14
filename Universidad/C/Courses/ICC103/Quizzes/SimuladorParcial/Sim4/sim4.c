/*
Defina un tipo de datos para almacenar la siguiente información y realice la función solicitada.
 
(5%) Un candidato tiene: ID del candidato de 9 caracteres, nombre de 50 caracteres, edad, puesto de trabajo de 30 caracteres, una lista de exámenes que debe aplicar y la cantidad de dichos exámenes registrados.
(5%) Un examen tiene, ID de 4 caracteres, nombre de 30 caracteres, puntuación y aprobado: indicador 'A' o 'F' según la puntuación
(20%) Desarrolle la función void imprimir_mejor_candidato que recibe un listado de candidatos y la cantidad de estos y e imprimirá toda la información (incluyendo información de exámenes) del mejor candidato o sea, con mejor promedio.
 
Ej:
=== Lista de Candidatos ===
ID: 20250001 Nombre: Juan Perez Edad: 25 Puesto: Analista
Exámenes:
 ID: EX1 | Nombre: Matemeticas | Nota: 85.00 | Aprobado: A
 ID: EX2 | Nombre: Logica | Nota: 90.00 | Aprobado: A
 ID: EX3 | Nombre: Programacion | Nota: 80.00 | Aprobado: A
 
ID: 20250002 Nombre: Ana Lopez Edad: 27 Puesto: Desarrolladora
Exámenes:
 ID: EX1 | Nombre: Matematicas | Nota: 95.00 | Aprobado: A
 ID: EX2 | Nombre: Logica | Nota: 95.00 | Aprobado: A
 ID: EX3 | Nombre: Programacion | Nota: 95.00 | Aprobado: A
 
 
=== Mejor Candidato ===
ID: 20250002
Nombre: Ana Lopez
Edad: 27
Puesto: Desarrolladora
Promedio: 95.00
Exámenes:
 ID: EX1 | Nombre: Matematicas | Nota: 95.00 | Aprobado: A
 ID: EX2 | Nombre: Logica | Nota: 95.00 | Aprobado: A
 ID: EX3 | Nombre: Programacion | Nota: 95.00 | Aprobado: A
*/

#include <stdio.h>

typedef struct examen
{
    char ID[5];
    char Nombre[30];
    float Puntuacion;
    char Aprobado;
} examen;

typedef struct candidato
{
    char ID[10];
    char Nombre[50];
    int Edad;
    char Puesto[30];
    examen examenes[10];
    int cantExamenes;
} candidato;

void imprimir_mejor_candidato(candidato *candidatos, int cantidad);

int main(){

    candidato c1 = {
        "1235789",
        "Tung tung sahur",
        67,
        "brainrot",
        {
            {"EX1", "Quiz1", 30.0, 'A'},
            {"EX2", "Quiz2", 70.0, 'A'},
            {"EX3", "Quiz3", 100.0, 'A'},
        },
        3
    };

    imprimir_mejor_candidato(&c1, 1);
    return 0;
}

void imprimir_mejor_candidato(candidato *candidatos, int cantidad){
    int mejor = -1;
    float suma, promedio, mayorpromedio = -1;
    for(int i=0; i<cantidad;i++){
        suma = 0;
        for (int j = 0; j < (candidatos+i)->cantExamenes; j++){
            suma += candidatos[i].examenes[j].Puntuacion;
        }
        promedio = suma/candidatos[i].cantExamenes;
        if (promedio > mayorpromedio){
            mejor=i;
        }
    }
    if (mejor!=-1){
        printf("MEJOR CANDIDATO:\nID: %s\nNOMBRE: %s\nEDAD: %d\nPUESTO: %s\nPROMEDIO: %f\n",
            candidatos[mejor].ID, candidatos[mejor].Nombre, candidatos[mejor].Edad, candidatos[mejor].Puesto, promedio);
        
        printf("EXAMENES:\n");
        for(int k=0; k<candidatos[mejor].cantExamenes; k++){
            printf("\nID: %s\nNombre: %s\nPuntuacion: %f\nAprobado: %c\n",
                    candidatos[mejor].examenes[k].ID, candidatos[mejor].examenes[k].Nombre, candidatos[mejor].examenes[k].Puntuacion, candidatos[mejor].examenes[k].Aprobado);
            
            
        }
    }
}