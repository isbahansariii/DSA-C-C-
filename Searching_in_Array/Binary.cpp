#include <stdio.h>
// #include <conio.h>
#include <iostream>

using namespace std;

int binarySearch(int arr[], int n, int find)
{
    int l=0, r=n-1;

    while(l<=r){
        int mid = (l+r)/2;
        if(find == arr[mid])
            return mid; //mid has index of the value
        else if(find > arr[mid])
            l = mid+1;
        else
            r = mid-1;
    }
    return -1;
}

int main (){
    int arr[] = {17, 19, 27, 28, 199};
    int n = sizeof(arr) / sizeof(arr[0]);
    int find;
    cout << "Enter a value to find: ";
    cin >> find;
    int result = binarySearch(arr, n, find);
    if(result != -1)
        cout << "Value is founded at " << result << " index.";
    else
        cout << "Value is not found.";
    return 0;
}
