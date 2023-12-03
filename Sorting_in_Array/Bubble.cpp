#include <stdio.h>
// #include <conio.h>
#include <iostream>

using namespace std;

void bubbleSort(int arr[], int size)
{ 
    int flag, temp;

    //Outer loop for passes
    for(int i=0; i<size-1; i++){
        flag = 0;

        // Inner loop for comparisions in each pass
        for(int j=0; j<size-1-i; j++){
            if(arr[j] > arr[j+1]){
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                flag = 1;
            }
        }
        if (flag == 0)
            break;
    }
}

void print(int arr[], int size){
    for (int i=0; i<size; i++){
        cout << arr[i] << " ";
    }
}

int main (){
    int arr[] = {80, 17, 19, 6, 27, 90, 28, 199};
    int size = sizeof(arr) / sizeof(arr[0]);
    bubbleSort(arr, size);
    print(arr, size);
}