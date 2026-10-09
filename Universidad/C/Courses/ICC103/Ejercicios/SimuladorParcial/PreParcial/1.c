#include <stdio.h>

int es_correcta(int *m, int orden){
int diagonal=0;
    for(int i=0; i<orden;i++){
        diagonal += *(m+i*orden+i);
    }

    for(int fil=0; fil<orden; fil++){
        for(int col=0; col<orden; col++){
            if (col>fil){
                if(*(m+fil*orden+col) <0 || *(m+fil*orden+col) > diagonal)
                return 0;
            }else if (fil>col)
            {
                if(*(m+fil*orden+col) < diagonal || *(m+fil*orden+col) > diagonal*2)
                return 0;
            }
            
        }
    }
    return 1;
}

int main(){

    int m[3][3] = {
        {5,  3, 10},
        {20, 6,  2},
        {25, 30, 9}
    };
    int res= es_correcta(&m[0][0],3);
    printf("%d", res);
    return 0;
}