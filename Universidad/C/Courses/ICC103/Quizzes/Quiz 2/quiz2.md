Se necesita una función que reciba un texto, una posición de inicio, una cantidad de caracteres a eliminar a partir de esa posición, y un texto a insertar en su lugar, de modo que el tramo eliminado quede reemplazado exactamente por el texto insertado, sin alterar el resto del contenido.

Por ejemplo, con texto “Hola desde el Mundo del Reves”, posición de inicio 11, cantidad a eliminar 18, e insertando "Hawkins", el resultado debe ser “Hola desde Hawkins”.

Se pide: crear una función stuff(char *texto, int inicio, int cantidad, char *insertar, char *resultado) que reciba el texto original, la posición y cantidad de caracteres a eliminar, y el texto a insertar, y construya en resultado el texto final.

Ejemplo de corrida:

 Antes: "Hola desde el Mundo del Reves"

Insertar: Hawkins

Posicion: 11

Cantidad: 18

Despues: "Hola desde Hawkins"

 

Antes: "Numero: 000-1234"

Insertar: 809

Posicion: 8

Cantidad: 3

Despues: "Numero: 809-1234"

Press any key to continue . . .