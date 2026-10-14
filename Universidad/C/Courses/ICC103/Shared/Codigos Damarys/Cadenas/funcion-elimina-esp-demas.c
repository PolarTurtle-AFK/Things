/*Algoritmos Fundamentales
3.	(25%). Realice una función void elimina_esp_demas(char texto[])
que elimine los espacios demás de una frase excepto aquellos que delimiten una palabra.

    Ej:	texto = "La casa    azul es   bonita"

	Al ejecutar la función elimina_esp_demas (texto), el texto queda:

    "La casa azul es bonita"

*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void elimina_esp_demas(char *);

int main(void)
{
    char cadena[100];

    printf("Digite un texto: ");
    gets(cadena);

    //texto leido antes de modificar
    printf("Texto sin modificar\n\n");
    printf("\"%s\"\n\n",cadena);

    //ejecutar función eliminará despacios demás, si los hay
    elimina_esp_demas(cadena);
    //texto luego de modificado
    printf("\n\nTexto modificado\n\n");
    printf("\"%s\"\n\n",cadena);


    system("pause");
    return 0;
}

void elimina_esp_demas(char *s)
{
   int i,j;

   for(i=0;*(s+i);i++)
   {

      //Verificar si hay espacios demás entre palabras, solo dejar 1
      //o bien si hay espacios y es la primera posición,
      //eliminar dicho espacio
      //también eliminar cualquier despacio demás al final del texto, sino
      //hay otra palabra

      if(*(s+i)==' ' && (i==0 || *(s+i+1)==' '  || *(s+i+1) == '\0'))
      {
          //strcpy(&s[i],&s[i+1]);
         strcpy(s+i,s+i+1);
         --i;
      }

   }

}
