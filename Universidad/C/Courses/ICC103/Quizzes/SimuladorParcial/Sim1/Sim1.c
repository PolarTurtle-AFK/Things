#include <stdio.h>
int matriz_Es_Segura(int *m, int orden);

int main(){
    int orden=3;
    int m1[3][3] = {{4,3,5},{12,6,5},{10,12,8}};
    int m2[3][3] = {{4,3,7},{12,5,9},{13,15,6}};
    matriz_Es_Segura(&m1[0][0], orden);
    matriz_Es_Segura(&m2[0][0], orden);
    
    return 0;
}

int matriz_Es_Segura(int *m, int orden){
    int promedio=0;
    for(int i = 0; i<orden; i++){
        if((*(m+i*orden+i))%2 == 0){
            promedio+=(*(m+i*orden+i));
        }else{
            printf("NO");
            return 0;
        }
    }
    promedio=promedio/3;
    for(int i = 0; i<orden; i++){
        for(int j=0; i<orden; i++){
            if(j>i){
                if ((*(m+i*orden+j) <= promedio || (*(m+i*orden+j) < 0)))
                {
                    printf("NO");
                    return 0;
                }
            }
            if(j<i){
                if ((*(m+i*orden+j) < promedio && (*(m+i*orden+j) > promedio*2)))
                {
                    printf("NO");
                    return 0;
                }
            }
        }
    }
    printf("SI");
    return 1;
}