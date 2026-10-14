/*
Escriba un programa en el se pidan dos matrices de n dimensión y muestra la matriz resultado
de sumar ambas matrices y la de la resta.
*/
#include<stdio.h>
#include<stdlib.h>

void sumar_matrices(int *, int *, int *, int);
void restar_matrices(int *, int *, int *, int);
void print_matriz(int *, int);

int main()
{
    int M1[3][3] = {8,9,1,
                    7,2,3,
                    5,4,0
                   };
    int M2[3][3] = {1,4,7,
                    6,5,9,
                    11,4,0
                   };
    int M3[3][3];
    int M4[3][3];

    sumar_matrices(&M1[0][0],&M2[0][0],&M3[0][0],3);
    printf("\nResultado SUMA\n");
    print_matriz(&M3[0][0],3);

    restar_matrices(&M1[0][0],&M2[0][0],&M4[0][0],3);
    printf("\nResultado RESTA\n");
    print_matriz(&M4[0][0],3);
    system("PAUSE");
    return 0;

}
void sumar_matrices(int *M1, int *M2, int *M3, int n)
{
    int f, c;
    for(f=0;f<n;f++)
    {
        for(c=0;c<n;c++)
            *(M3+f*n+c) = *(M1+f*n+c) + *(M2+f*n+c);
    }
}
void restar_matrices(int *M1, int *M2, int *M3, int n)
{
    int f, c;
    for(f=0;f<n;f++)
    {
        for(c=0;c<n;c++)
            *(M3+f*n+c) = *(M1+f*n+c) - *(M2+f*n+c);
    }
}

void print_matriz(int *M, int n)
{
    int f, c;
    for(f=0;f<n;f++)
    {
        for(c=0;c<n;c++)
            printf("%4d",*(M+f*n+c));

        printf("\n");
    }
}
