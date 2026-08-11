#include <stdio.h>

// Partition / Sorting
void negativePartition(int arr[], int size);
void sortArray(int arr[], int size);

// Search / Statistics
int findMaxMin(int arr[], int size);
int sumArray(int arr[], int size);
float averageArray(int arr[], int size);
int count(int arr[], int size);
int findValue(int arr[], int size, int value);

// Manipulation
void reverseArray(int arr[], int size);
void copyArray(int original[], int copia[], int size);
void removeDuplicates(int arr[], int size);
void rotateLeft(int arr[], int size);
void rotateRight(int arr[], int size);

// Frequency
int countOccurrences(int arr[], int size, int value);

// Advanced
int secondLargest(int arr[], int size);

int main(){
    int arr[25] = {42, -17, 8, -63, 91, -4, 27, -88, 15, 73, -29, 56, -11, 34, -95, 6, -48, 82, -22, 19, -71, 3, 64, -36, 50};
    int num = 0;
    // Partition / Sorting
    // printf("\n\n==== ORDENAR NEAGTIVO-POSITIVO ====\n");
    // negativePartition(arr,25);
    // printf("\n\n==== ORDENAR MENOR-MAYOR ====\n");
    // sortArray(arr,25);

    // Search / Statistics
    // num = findMaxMin(arr,25);
    // printf("\nFound number": %d",num);
    // num = sumArray(arr,25);
    // printf("\nSum of numbers: %d", num);
    // int avg = averageArray(arr,25);
    // printf("\nThe average is %d", avg);
    // num = count(arr,25);
    num = findValue(arr,25,0);
    if (num>=0) printf("Pos of the number = %d", num);

    // Manipulation


    return 0;
}

void negativePartition(int arr[], int size){
    printf("\nArray before the changes: \n");
    for (int i = 0; i<size; i++){
        printf("%4d ", arr[i]);
    }

    int temp = 0;
    int cont = 0;
    for (int i = 0; i < size; i++){
        if (arr[i] < 0){
            temp = arr[cont];
            arr[cont] = arr[i];
            arr[i] = temp;
            cont++;
        }
    }

    printf("\nArray after the changes: \n");
    for (int i = 0; i<size; i++){
        printf("%4d ", arr[i]);
    }
}

void sortArray(int arr[], int size){
    printf("\nArray before the changes: \n");
    for (int i = 0; i<size; i++){
        printf("%4d ", arr[i]);
    }

    int temp=0;
    
    for (int i = 0; i <size-1; i++){
        for (int j = 0; j<size-i-1; j++){
            if (arr[j] > arr[j + 1]){
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    printf("\nArray after the changes: \n");
    for (int i = 0; i<size; i++){
        printf("%4d ", arr[i]);
    }
}

int findMaxMin(int arr[], int size){
    int num = 0;
    int option=0;
    printf("Select orientation (Min = -1, Max = 1): ");
    scanf("%d",&option);
    
    for (int i = 0; i<size; i++){
        if (option == 1){
            if(arr[i]>=num){
            num = arr[i]; 
            }
        }else if (option ==-1){
            if(arr[i]<=num){
            num = arr[i]; 
            }
        }else return 0;
    }
    return num;
}

int sumArray(int arr[], int size){
    int num = 0;
    for (int i =0; i<size; i++){
        num =+ arr[i];
    }
    return num;
}

float averageArray(int arr[], int size){
    int num = sumArray(arr,size);
    int avg = num/size;
    return avg;
}

int count(int arr[], int size){
    int count=0;
    int option=0;
    printf("Select type of number (Negative = -1, Odd = 1, Even = 2): ");
    scanf("%d",&option);
    if (option == -1){
        for (int i = 0; i < size; i++){
            if (arr[i] < 0){
                count++;
            }
        }
        printf("Amount of negative numbers in the array: %d", count);
        return count;
    }else if (option == 1){
        for (int i = 0; i < size; i++){
            if (arr[i] % 2 != 0){
                count++;
            }
        }
        printf("Amount of odd numbers in the array: %d", count);
        return count;
    }else if (option == 2){
        for (int i = 0; i < size; i++){
            if (arr[i] % 2 == 0){
                count++;
            }
        }
        return count;
        printf("Amount of even numbers in the array: %d", count);

    }
    return count;
}

int findValue(int arr[], int size, int value){
    printf("What number are you looking for?: ");
    scanf("%d", &value);
    for (int i=0; i<size; i++){
        if (arr[i] == value){
            return i+1;
        }
    }
    printf("Number not found");
    return -1;
}

