#include <stdio.h>
#include <stdlib.h>

#define MAX_TEXTO 100
#define CLAVE 1
#define MENSAJE 2
/*
a.  Para validar si un carácter es una letra (no usar ctype.h).
b.  Para convertir un carácter a mayúscula (no usar toupper).
c.  Para validar que la clave contenga únicamente letras y no esté vacía.
d.  Para leer el mensaje y la clave por teclado (fgets deben eliminar el \0).

e.  Para cifrar el mensaje aplicando el algoritmo de Vigenère.
f.  Para descifrar el mensaje aplicando el proceso inverso.

g.  Para mostrar el menú principal.
*/
int esLetra(char);     
void tomayuscula(char *);          
int validar_clave(char *);         
void scanmc(char *, int);          
void cifrar(char *, char *, char *);            
void descifrar(char *, char *, char *);         
void mostrar_menu();                  
int soloLetras(char *);


int main()
{

    char clave[MAX_TEXTO] = {'\0'};
    char mensaje[MAX_TEXTO] = {'\0'};
    char mensaje_cifrado[MAX_TEXTO] = {'\0'};
    char mensaje_descifrado[MAX_TEXTO] = {'\0'};

    int clave_lista = 0;
    int mensaje_listo = 0;
    int cifrado_listo = 0;

    int opcion;
    do
    {
        mostrar_menu();
        scanf("%d", &opcion);
        while (getchar() != '\n')
            ;
        printf("\n");

        switch (opcion)
        {

        case 1: /* Ingresar clave */
        {
            scanmc(clave, CLAVE);
            tomayuscula(clave);
            clave_lista = 1;
            cifrado_listo = 0;
            break;
        }
        case 2: /* Ingresar mensaje */
        {
            if (!clave_lista)
            {
                printf("Debe ingresar la clave primero (opcion 1).\n");
                break;
            }
            scanmc(mensaje,MENSAJE);
            tomayuscula(mensaje);
            
            mensaje_listo = 1;
            cifrado_listo = 0;

            break;
        }

        case 3: /* Cifrar mensaje */
        {
            if (!mensaje_listo)
            {
                printf("Debe ingresar un mensaje primero (opcion 2).\n");
                break;
            }
            cifrar(clave,mensaje,mensaje_cifrado);
            printf("\nMensaje cifrado: %s \n", mensaje_cifrado);
            cifrado_listo = 1;
            break;
        }
        case 4: /* Descifrar mensaje */
        {
            if (!cifrado_listo)
            {
                printf("Debe de cifrar el mensaje primero (opcion 3).\n");
                break;
            }
            descifrar(clave,mensaje_cifrado,mensaje_descifrado);
            printf("\nMensaje descifrado: %s \n", mensaje_descifrado);
            break;
        }

        case 5: /* Salir */
        {
            printf("Saliendo del programa...\n");
            break;
        }

        default:
        {
            printf("Opcion invalida. Intente de nuevo.\n\n");
            break;
        }
        }

        if (opcion != 5)
        {
            system("PAUSE");
        }
    }
    while (opcion != 5);

    return 0;
}

/*
Funcion: esLetra
Proposito: Verificar si un caracter es una letra mayuscula o minuscula.
Uso: Se utiliza para validar los caracteres de la clave y del mensaje.
Retorno: 1 si es una letra y 0 si no lo es.
*/
int esLetra(char c)
{
    return (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z');
}

/*
Funcion: tomayuscula
Proposito: Convertir todas las letras minusculas de una cadena a mayusculas.
Uso: Se utiliza antes de cifrar o descifrar el mensaje y la clave.
*/
void tomayuscula(char *clave)
{
    for (; *clave != '\0'; clave++)
    {
        if (*clave >= 'a' && *clave <= 'z')
            *clave = *clave - 32;
    }
}

/*
Funcion: validar_clave
Proposito: Verificar que la clave no este vacia y que contenga solamente letras.
Uso: Se utiliza al momento de ingresar una clave.
Retorno: 1 si la clave es valida y 0 si no lo es.
*/
int validar_clave(char *clave)
{
    if (*clave == '\0')
        return 0;

    return soloLetras(clave);
}

/*
Funcion: scanmc
Proposito: Leer una clave o un mensaje utilizando fgets y eliminar el salto de linea.
Uso: Si opcion es CLAVE, valida la clave hasta que sea correcta.
       Si opcion es MENSAJE, solamente lee el mensaje.
*/
void scanmc(char *string, int opcion)
{
    char *p;

    if (opcion == CLAVE)
    {
        do
        {
            printf("Ingrese la clave (solo letras, sin espacios): ");
            fgets(string, MAX_TEXTO, stdin);

            p = string;

            while (*p != '\0')
            {
                if (*p == '\n')
                {
                    *p = '\0';
                    break;
                }
                p++;
            }

            if (!validar_clave(string))
            {
                printf("Clave invalida. Debe contener solo letras y no estar vacia.\n");
            }

        } while (!validar_clave(string));
    }
    else if (opcion == MENSAJE)
    {
        printf("Ingrese el mensaje: ");
        fgets(string, MAX_TEXTO, stdin);

        p = string;

        while (*p != '\0')
        {
            if (*p == '\n')
            {
                *p = '\0';
                break;
            }
            p++;
        }
    }
}

/*
Funcion: soloLetras
Proposito: Recorrer una cadena y verificar que todos sus caracteres sean letras.
Uso: Se utiliza dentro de validar_clave.
Retorno: 1 si todos los caracteres son letras y 0 si encuentra otro caracter.
*/
int soloLetras(char *clave)
{
    while (*clave != '\0')
    {
        if (!esLetra(*clave))
        {
            return 0;
        }
        clave++;
    }

    return 1;
}

/*
Funcion: cifrar
Proposito: Cifrar el mensaje utilizando el algoritmo de Vigenere.
Uso: Utiliza la clave para transformar cada letra del mensaje.
       Los caracteres que no son letras se copian sin modificarse y no consumen
       una posicion de la clave.
Formula: C = (M + K) % 26
*/
void cifrar(char *clave, char *mensaje, char *resultado)
{
    char *inicio_clave = clave;

    for (; *mensaje != '\0'; mensaje++)
    {
        if (!esLetra(*mensaje))
        {
            *resultado = *mensaje;
        }
        else
        {
            int M = *mensaje - 'A';
            int K = *clave - 'A';
            int C = (M + K) % 26;

            *resultado = C + 'A';

            clave++;

            if (*clave == '\0')
            {
                clave = inicio_clave;
            }
        }

        resultado++;
    }

    *resultado = '\0';
}

/*
Funcion: descifrar
Proposito: Recuperar el mensaje original utilizando la misma clave del cifrado.
Uso: Aplica el proceso inverso del algoritmo de Vigenere.
       Los caracteres que no son letras se copian sin modificarse.
Formula: M = (C - K + 26) % 26
*/
void descifrar(char *clave, char *mensaje, char *resultado)
{
    char *inicio_clave = clave;

    for (; *mensaje != '\0'; mensaje++)
    {
        if (!esLetra(*mensaje))
        {
            *resultado = *mensaje;
        }
        else
        {
            int C = *mensaje - 'A';
            int K = *clave - 'A';
            int M = (C - K + 26) % 26;

            *resultado = M + 'A';

            clave++;

            if (*clave == '\0')
            {
                clave = inicio_clave;
            }
        }

        resultado++;
    }

    *resultado = '\0';
}

/*
Funcion: mostrar_menu
Proposito: Mostrar las opciones disponibles del sistema.
Uso: Se ejecuta al inicio de cada ciclo del programa.
*/
void mostrar_menu()
{
    printf("===== SMS - SISTEMA DE MENSAJERIA SEGURA =====\n");
    printf("1. Ingresar clave \n");
    printf("2. Ingresar mensaje \n");
    printf("3. Cifrar mensaje \n");
    printf("4. Descifrar mensaje \n");
    printf("5. Salir\n");
    printf("Seleccione una opcion: ");
}