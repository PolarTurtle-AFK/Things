#include "pseudo.h"

inicio
    entero edadHombre;
    entero edadMujer;

    imprimir("Ingrese edad del hombre:");
    ingresar(edadHombre);

    imprimir("Ingrese edad de la mujer:");
    ingresar(edadMujer);

    si edadMujer < 18 entonces
        imprimir("NO");
    sino
        imprimir("SI");
    finsi
fin