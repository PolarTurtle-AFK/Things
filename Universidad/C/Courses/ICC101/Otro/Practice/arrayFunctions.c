#include <stdio.h>
// Printf
void printArray(int arr[], int size, int opt);


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
int removeDuplicates(int arr[], int size);
void rotateLeftRight(int arr[], int size, int side);

// Frequency
int countOccurrences(int arr[], int size, int value);

// Advanced
int secondLargest(int arr[], int size);

int main(){
    int arr[25] = {42, -17, 8, -63, 91, -4, 27, -88, 15, 73, -29, 56, -11, 34, -95, 6, -48, 82, -22, 19, -71, 3, 64, -36, 50};
    int arr2[25] = {1,1,3,3,2,5,5,6,7,8,7,6,5,5,5,4,2,1,2,3,4,5,7,8,9};
    int num = 0;

    //printArray(arr,25,1);
    //printArray(arr2,25,1);
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
    // num = findValue(arr,25,0);
    // if (num>=0) printf("Pos of the number = %d", num);

    // Manipulation
    // reverseArray(arr,25);
    // copyArray(arr,arr,25);
    // int newsize = removeDuplicates(arr2,25);
    // printArray(arr2,newsize,2);
    // rotateLeftRight(arr,25,-1);
    // printArray(arr,25,2);
    // rotateLeftRight(arr,25,1);


    // Frequency
    // num = countOccurrences(arr2,25,5);
    // printf("\nAmount of times that value appeared: %d", num);

    // Advanced
    // num = secondLargest(arr,25);
    // printf("\n The second biggest number is: %d", num);
    //i should make it that you ask for what the N biggest number is
    //printArray(arr,25,2);
    //printArray(arr2,25,2);
    return 0;
}
void printArray(int arr[], int size, int opt){
    if (opt==1){
        printf("\nArray before the changes: \n");
        for (int i = 0; i<size; i++){
            printf("%4d ", arr[i]);
        }
    }else if (opt==2){
        printf("\nArray after the changes: \n");
        for (int i = 0; i < size; i++){
            printf("%4d ", arr[i]);
        }
    }
}

void negativePartition(int arr[], int size){
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
}

void sortArray(int arr[], int size){
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

void reverseArray(int arr[], int size){
    int temp = 0;
    for (int i = 0; i<size/2; i++){
        temp = arr[i];
        arr[i] = arr[size-1-i];
        arr[size-1-i] = temp;
    }
}

void copyArray(int original[], int copia[], int size){
    for (int i = 0; i<size; i++){
        copia[i] = original[i];
    }
}

int removeDuplicates(int arr[], int size){
    for (int i = 0; i<size; i++){
        for (int j = i+1; j<size; j++){
            if (arr[i] == arr[j]){
                for (int k = j; k<size-1; k++){
                    arr[k] = arr[k+1];
                }
                size--;
                j--;
            }
        }
    }
    return size;
}

void rotateLeftRight(int arr[], int size, int side){
    int temp = 0;
    if (side == 1){
        temp = arr[0];
        for (int i = 0; i < size-1; i++){
            arr[i] = arr[i+1];
        }
        arr[size-1] = temp;
    }else if (side == -1){
        temp = arr[size-1];
        for (int i = size-1; i > 0; i--){
            arr[i] = arr[i-1];
        }
        arr[0] = temp;
    }
}

int countOccurrences(int arr[], int size, int value){
    int cont = 0;
    for(int i=0; i<size; i++){
        if (arr[i]==value){
            cont++;
        }
    }
    return cont;
}

int secondLargest(int arr[], int size){
    int num = 0;
    int num2 = 0;
    for (int i = 0; i < size; i++){
        if (arr[i] >= num){
            num2 = num;
            num = arr[i];
        }else if (arr[i] > num2 && arr[i] != num){
            num2 = arr[i];
        }
    }
    return num2;
}