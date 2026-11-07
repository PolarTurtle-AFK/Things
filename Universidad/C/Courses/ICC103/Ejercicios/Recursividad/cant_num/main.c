#include <stdio.h>
#include <stdlib.h>
int cdig_rec(int n,int d);

int main()
{
    int n=56887;
    int d=8;

    int cant = cdig_rec(n,d);
    printf("%d",cant);
    return 0;
}

int cdig_rec(int n,int d){
    if(n==0){
        return 0;
    }
    if (n%10==d){
        return 1+(cdig_rec(n/10,d));
    }else{
        return cdig_rec(n/10,d);
    }
}
