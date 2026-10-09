1. Se desea verificar si una matriz cuadrada está colocada correctamente, para esto los valores por encima de la diagonal superior de la matriz deben estar entre cero y la traza, y los valores por debajo de la diagonal superior de la matriz deben estar entre la traza y el doble de la traza. La traza de una matriz es la sumatoria de los valores en la diagonal superior.
Realice la función int es_correcta(int *m, int orden) que retorne 1 si la matriz cumple con la condición antes planteada y 0 si no cumple con dicha condición.
Ej:
5 3 10
20 6 2
25 30 9

Acá la traza es 5 + 6 + 9 = 20 
3, 10 y 2 cumplen con la 1ra regla
25, 20, 9 con la 2da regla

2. Realice una función void elimina_esp_demas(char *s) que elimine los espacios demás de una frase excepto aquellos que delimiten una palabra. 
Ej: texto = “La casa azul es bonita”

Al ejecutar la función elimina_esp_demas (texto), el texto queda:
“La casa azul es bonita”

3. Dadas las siguientes estructuras:

typedef struct
{
int dia, mes, agno;
}Fecha;

typedef struct
{ 
char CodCliente[5];
Fecha Fec_factura;
float monto;
char CodCondPago[3];
}Factura;

typedef struct
{
char CodCliente [5];
char nombre[50];
char telefono[11];
Fecha Fec_Ingreso;
}Cliente; 

a) Realizar la función void oldest_customers (Cliente cl[MAX], int cantcl) la cual imprime los datos de los clientes con más de 10 años de fecha de ingreso al sistema al comparar con el año de la fecha actual.

b) Realizar la función customer_most_purchases (Factura *fact, int cantf, Cliente *cl, int cantcl) la cual imprime los datos del cliente que más ha comprado, es decir, el que tiene el monto acumulado mayor en facturas, no importa si se pagó o no.