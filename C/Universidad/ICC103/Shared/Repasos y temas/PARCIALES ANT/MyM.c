#include <stdio.h>

int EncontrarElMayor(int arr[10]);
int EncontrarElMenor(int arr[10]);

void main()
{
 int numero[10];
 int R;
 do{
    printf("\nque desea hacer?\n");
    printf("1: buscar el numero mayor\n");
    printf("2: buscar el numero menor\n");
    printf("3: salir\n");
    printf("elige: ");
    scanf("%d", &R);

    if(R == 1 || R == 2)
        {
         for(int c=0; c<10;c++)
         {
          printf("\nescribe tu %d numero: ", c+1);
          scanf("%d", &numero[c]);
         }
        }

    switch(R)
    {
    case 1:
        printf("\nel numero mayor es: %d\n", EncontrarElMayor(numero));
        break;

    case 2:
        printf("\nel numero menor es: %d\n", EncontrarElMenor(numero));
        break;

    case 3:
        printf("\nsaliendo...\n");
        break;

    default:
        printf("\nopcion no valida\n");
    }
 }while(R != 3);
}

int EncontrarElMayor(int arr[10])
{
 int i = 0;
 int mayor = arr[i];
 for(i; i < 10; i++)
    {
     if(arr[i] > mayor)
        {
         mayor = arr[i];
        }
    }
 return mayor;
}

int EncontrarElMenor(int arr[10])
{
 int i = 0;
 int menor = arr[i];
 for(i; i < 10; i++)
    {
     if(arr[i] < menor)
        {
         menor = arr[i];
        }
    }

 return menor;
}
