#include <stdio.h>

void reverseArray(int *, int); 
int main(){
    int arr[5]={1,2,3,4,5};
    reverseArray(&arr[0],5);
    return 0;
};

void reverseArray(int *arr, int size){
    printf("BEFORE\n");
    for (int i=0;i<size;i++){
        printf("%d ", *(arr+i));
    }
//
    int temp = 0;
    for (int i = 0; i<size/2; i++){
        temp = *(arr+i);
        *(arr+i) = *(arr+size-1-i);
        *(arr+size-1-i) = temp;
    }
//
    printf("\nAFTER\n");
    for (int i=0;i<size;i++){
        printf("%d ", *(arr+i));
    }
}