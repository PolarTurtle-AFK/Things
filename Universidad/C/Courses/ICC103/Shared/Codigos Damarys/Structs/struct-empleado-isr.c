/*
Se tiene un arreglo de n elementos. Cada elemento es una estructura que contiene los datos
nombre del empleado, ISR - Impuesto Sobre la Renta, Sueldo Neto.
a) Declare dicha estructura.
b) Realice una función que permita saber en qué posición del arreglo se encuentra el
empleado con mayor sueldo neto.
c) Realice una función que de acuerdo a un estatus sume el sueldo bruto o el descuento isr o
el sueldo neto.
d) Realice una función que le permita obtener la cantidad de empleados que tengan
sueldos netos por encima y por debajo del promedio.
*/
#include<stdio.h>
#include<stdlib.h>

typedef struct
{
    char nombre[30];
    float isr;
    float sneto;
} infoemp;

int posicion_emp_mayor_sueldo(infoemp *, int);
float sumatoria_total(infoemp *, int, int);
int cant_emp_encima_prom(infoemp *, int);

int main()
{

    infoemp emp[4] =
    {
        {"Kary Fernandez",550.25,25532.75},
        {"Adrian Artiles",850.25,50532.75},
        {"Jesus Hernandez",1050.25,75000.75},
        {"Pamela Fernandez",2050.25,35532.75}
    };

    int result = posicion_emp_mayor_sueldo(emp,4);
    printf("El empleado con mayor sueldo esta en la posicion %d\n",result+1);
    printf("Datos empleado: %s con un sueldo de %.2f\n",(emp+result)->nombre, (emp+result)->sneto);

    int estatus; //1-Sueldo Bruto o 2-Descuento ISR 3-Sumar sueldo neto
    estatus = 1;
    printf("\n\nEl sueldo bruto acumulado: %.2f\n",sumatoria_total(emp,4,estatus));
    estatus = 2;
    printf("El descuento ISR acumulado: %.2f\n",sumatoria_total(emp,4,estatus));
    estatus = 3;
    printf("El sueldo neto acumulado: %.2f\n\n",sumatoria_total(emp,4,estatus));

    printf("Cantidad de empleados con sueldo por encima del promedio %d\n\n",cant_emp_encima_prom(emp,4));
    system("PAUSE");
    return 0;
}
int posicion_emp_mayor_sueldo(infoemp *e, int n)
{
    float mayorsueldo= e->sneto; //toma el sueldo del primer empleado
    int i, pos=0; //tomar posicion del primer empleado

    for(i=0; i<n; i++)
    {
        if((e+i)->sneto > mayorsueldo)
        {
            mayorsueldo = (e+i)->sneto;
            pos = i;
        }
    }
    return pos;
}
float sumatoria_total(infoemp *e, int n, int st)
{
    int i;
    float suma=0;

    for(i=0; i<n; i++)
    {
        if(st == 1)
            suma+=(e+i)->sneto + (e+i)->isr; //sueldo bruto que seria el neto + descuento
        else if(st == 2)
            suma+=(e+i)->isr; // acumular descuento isr
        else if(st == 3)
            suma+=(e+i)->sneto; //acumular sueldo neto
    }
    return suma;
}
int cant_emp_encima_prom(infoemp *e, int n)
{
    int i, cont=0;
    float prom=0;

    //sumo todos lo sueldos para luego calcular promedio
    for(i=0; i<n; i++)
        prom+=(e+i)->sneto;

    prom/=n; //calcular el promedio

    for(i=0; i<n; i++)
    {
        if((e+i)->sneto > prom) //si el sueldo neto del empleado actual es mayor que el prom
            cont++;
    }
    return cont;
}
