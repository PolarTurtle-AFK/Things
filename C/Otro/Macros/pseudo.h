/* pseudo.h
 * ------------------------------------------------------------------
 * Este archivo contiene macros para escribir pseudocodigo en C.
 * ------------------------------------------------------------------
 */
#ifndef PSEUDO_H
#define PSEUDO_H

#include <stdio.h>

/* ---------- Estructura del programa ---------- */
#define inicio   int main(void) {
#define fin      return 0; }

/* ---------- Entrada / salida ---------- */

#define imprimir(x) printf(_Generic((x), \
        int:         "%d\n",  \
        long:        "%ld\n", \
        float:       "%f\n",  \
        double:      "%f\n",  \
        char:        "%c\n",  \
        char*:       "%s\n",  \
        const char*: "%s\n"), (x))

#define ingresar(x) scanf(_Generic((x), \
        int:    "%d",  \
        long:   "%ld", \
        float:  "%f",  \
        double: "%lf", \
        char:   " %c"), &(x))

/* ---------- Condicionales ---------- */

#define si         if (
#define entonces   ) {
#define sino       } else {
#define finsi      }

/* ---------- Operaciones ---------- */
#define suma(a, b) ((a) + (b))

/* ---------- Tipos (para que se lea como pseudocodigo) ---------- */
#define entero     int
#define real       double
#define caracter   char
#define cadena     char*

#endif /* PSEUDO_H */