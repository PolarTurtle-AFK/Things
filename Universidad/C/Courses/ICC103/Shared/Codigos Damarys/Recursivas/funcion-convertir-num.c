#include<stdio.h>
#include<stdlib.h>

int convertir(int, int);
int convertir_rec_pot(int, int, int);
int convertir_rec(int, int);
int main()
{
    int num=317, base=3;

    printf("Numero convertido: %d\n",convertir(num,base));
    printf("Numero convertido recursiva (enviando potencia): %d\n",convertir_rec_pot(num,base,1));
    printf("Numero convertido recursiva: %d\n",convertir_rec(num,base));
    system("PAUSE");
    return 0;
}
int convertir(int num, int base)
{
    int residuo, acum=0, potencia=1;

    while(num > 0)
    {
        residuo = num%base;
        acum += residuo * potencia; //acum + residuo * potencia;
        potencia *= 10; //potencia = potencia * 10;
        num = num/base;
    }
    return acum;
}
int convertir_rec_pot(int num, int base, int pot)
{
    if(num == 0)
        return 0;

    return num % base * pot + convertir_rec_pot(num/base,base, pot*10);
}
int convertir_rec(int num, int base)
{
    if(num == 0)
        return 0;

    // return convertir_rec(num/base,base) *10 + (num%base);
    return (num%base) + 10 * convertir_rec(num/base,base) ;
}
