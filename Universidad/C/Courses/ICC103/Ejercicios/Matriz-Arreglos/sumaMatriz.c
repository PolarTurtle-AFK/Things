#include <stdio.h>

void sumar_matrices(int *, int *, int *, int);
int main(){
    int M1[3][3] = {{8, 9, 1},
                        {7, 2, 3},
                        {5, 4, 0}};
    int M2[3][3] = {{1, 4, 7},
                         {6, 5, 9},
                         {11, 4, 0}};
    int M3[3][3];

    sumar_matrices(&M1[0][0],&M2[0][0],&M3[0][0], 3);
}

void sumar_matrices(int *m1, int *m2, int *m3, int n){
    int f,c;

    for (f=0;f<n;f++){
        for(c=0;c<n;c++){
            *(m3+f*n+c) = *(m1+f*n+c) + *(m2+f*n+c);
        }
    }

    for (f=0;f<n;f++){
        printf("\n");
        for(c=0;c<n;c++){
            printf("%d ", *(m3+f*n+c));
        }
    }

}