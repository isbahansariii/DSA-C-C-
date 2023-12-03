#include <stdio.h>
// #include <conio.h>
#include <iostream>

using namespace std;

int linearSearch(int arr[], int size, int find)
{
    for (int i=0; i<size; i++) //5<5
    {
        if (arr[i] == find)
        {
            return i;
        }
    }
    return -1;
}

int main (){
    int arr[] = {17, 19, 27, 28, 199};
    int size = sizeof(arr) / sizeof(arr[0]);
    int find;
    cout << "Enter a value to find: ";
    cin >> find;
    int result = linearSearch(arr, size, find);
    if(result != -1)
        cout << "Value is founded at " << result << " index.";
    else
        cout << "Value is not found.";
}