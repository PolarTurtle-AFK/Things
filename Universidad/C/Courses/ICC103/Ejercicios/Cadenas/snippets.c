#include <stdio.h>
#include <stdlib.h>

#define MAX 200

// ============================================================================
// 1. COMPRIMIR CADENA (Run-Length Encoding)
// Ejemplo: "aaabbc" -> "a3b2c1"
// ============================================================================
void comprimir_cadena_punteros(char *destino, char *origen) {
    while (*origen != '\0') {
        char c = *origen;
        int contador = 0;

        // Contar repeticiones consecutivas con punteros
        while (*origen != '\0' && *origen == c) {
            contador++;
            origen++;
        }

        // Guardar el carácter
        *destino = c;
        destino++;

        // Guardar la cantidad (convertir entero a caracteres)
        if (contador >= 10) {
            *destino = (contador / 10) + '0';
            destino++;
        }
        *destino = (contador % 10) + '0';
        destino++;
    }
    *destino = '\0'; // Fin de cadena
}

// ============================================================================
// 2. EXPANDIR CADENA COMPRIMIDA
// Ejemplo: "a3b2c1" -> "aaabbc"
// ============================================================================
void descomprimir_cadena_punteros(char *destino, char *origen) {
    while (*origen != '\0') {
        char c = *origen;
        origen++;

        if (*origen >= '0' && *origen <= '9') {
            int repeticiones = *origen - '0';
            
            // Copiar el carácter 'repeticiones' veces
            while (repeticiones > 0) {
                *destino = c;
                destino++;
                repeticiones--;
            }
            origen++;
        }
    }
    *destino = '\0';
}

// ============================================================================
// 3. EXPANDIR ESPACIOS (ESPACIAR DUP-LETRA)
// Ejemplo: "hola" -> "h o l a "
// ============================================================================
void expandir_espacios_punteros(char *destino, char *origen) {
    while (*origen != '\0') {
        *destino = *origen;
        destino++;
        *destino = ' '; // Inserta un espacio entre cada carácter
        destino++;
        origen++;
    }
    *destino = '\0';
}

// ============================================================================
// 4. ELIMINAR SUBCADENA O PALABRA ESPECÍFICA
// Ejemplo: "hola mundo feo", eliminar "feo" -> "hola mundo "
// ============================================================================
void eliminar_subcadena_punteros(char *s, char *sub) {
    char *p = s;

    while (*p != '\0') {
        char *p_aux = p;
        char *sub_aux = sub;

        // Comprobar si la subcadena coincide en la posición actual
        while (*p_aux != '\0' && *sub_aux != '\0' && *p_aux == *sub_aux) {
            p_aux++;
            sub_aux++;
        }

        // Si sub_aux llegó al final, encontramos la coincidencia
        if (*sub_aux == '\0') {
            // Desplazar todo el resto de la cadena hacia la izquierda con punteros
            char *origen_resto = p_aux;
            char *destino_resto = p;

            while (*origen_resto != '\0') {
                *destino_resto = *origen_resto;
                destino_resto++;
                origen_resto++;
            }
            *destino_resto = '\0';
        } else {
            p++;
        }
    }
}

// ============================================================================
// 5. ELIMINAR CARACTERES DUPLICADOS
// Ejemplo: "bananas" -> "bans"
// ============================================================================
void eliminar_duplicados_punteros(char *s) {
    char *p = s;

    while (*p != '\0') {
        char *lectura = p + 1;
        char *escritura = p + 1;

        while (*lectura != '\0') {
            if (*lectura != *p) { // Si no es igual al carácter actual (*p), se conserva
                *escritura = *lectura;
                escritura++;
            }
            lectura++;
        }
        *escritura = '\0'; // Cortar los duplicados eliminados en esta pasada
        p++;
    }
}

// ============================================================================
// AUXILIAR: COPIAR CADENA CON PUNTEROS
// ============================================================================
void copiar_punteros(char *destino, char *origen) {
    while (*origen != '\0') {
        *destino = *origen;
        destino++;
        origen++;
    }
    *destino = '\0';
}


// ============================================================================
// PROGRAMA PRINCIPAL (MAIN)
// ============================================================================
int main() {
    char s1[MAX], res[MAX];

    printf("=== SNIPPETS: COMPRIMIR, EXPANDIR Y ELIMINAR CON PUNTEROS ===\n\n");

    // ------------------------------------------------------------------------
    // SNIPPET 1: Comprimir Cadena (Run-Length)
    // ------------------------------------------------------------------------
    /*
    copiar_punteros(s1, "aaabbcdddd");
    comprimir_cadena_punteros(res, s1);
    printf("Original: %s\n", s1);
    printf("Comprimida: %s\n\n", res); // Resultado: "a3b2c1d4"
    */

    // ------------------------------------------------------------------------
    // SNIPPET 2: Descomprimir/Expandir Cadena
    // ------------------------------------------------------------------------
    /*
    copiar_punteros(s1, "a3b2c1d4");
    descomprimir_cadena_punteros(res, s1);
    printf("Comprimida: %s\n", s1);
    printf("Expandida: %s\n\n", res); // Resultado: "aaabbcdddd"
    */

    // ------------------------------------------------------------------------
    // SNIPPET 3: Expandir añadiendo espacios
    // ------------------------------------------------------------------------
    /*
    copiar_punteros(s1, "QUIZ");
    expandir_espacios_punteros(res, s1);
    printf("Original: %s\n", s1);
    printf("Expandida con espacios: %s\n\n", res); // Resultado: "Q U I Z "
    */

    // ------------------------------------------------------------------------
    // SNIPPET 4: Eliminar una palabra/subcadena
    // ------------------------------------------------------------------------
    /*
    copiar_punteros(s1, "hola mundo cruel");
    printf("Original: %s\n", s1);
    eliminar_subcadena_punteros(s1, "mundo ");
    printf("Luego de eliminar 'mundo ': %s\n\n", s1); // Resultado: "hola cruel"
    */

    // ------------------------------------------------------------------------
    // SNIPPET 5: Eliminar caracteres duplicados
    // ------------------------------------------------------------------------
    /*
    copiar_punteros(s1, "bananas");
    printf("Original: %s\n", s1);
    eliminar_duplicados_punteros(s1);
    printf("Sin duplicados: %s\n\n", s1); // Resultado: "bans"
    */

    system("PAUSE");
    return 0;
}