#include <bits/stdc++.h>
#include <iostream>

using std::cout;
using std::cin;
using std::endl;

void merge(int arr[], int low, int high) {
        
    int tempArr[high + 1];

    for( int count = low; count <= high; count++ ) {
        tempArr[count] = arr[count];
    }

    int mid = low + (high - low)/2;

    int i = low;
    int j = mid + 1;

    for (int cursor = low; cursor <= high; cursor++) {

        if ( i == (mid+1) ) {
            arr[cursor] = tempArr[j++];
        } else if ( j > high ) {
            arr[cursor] = tempArr[i++];
        } else if ( tempArr[i] <= tempArr[j] ) {
            arr[cursor] = tempArr[i++];
        } else if ( tempArr[i] > tempArr[j] ) {
            arr[cursor] = tempArr[j++];
        }

    }
}

void mergeSort(int arr[], int low, int high) {

    if ( low < high ) {

        int mid = low + (high - low)/2;
        mergeSort(arr, low, mid);
        mergeSort(arr, mid + 1, high);
        merge(arr, low, high);
    }
}

void printArray(int arr[], int arrSize){
    for(int i = 0; i < arrSize; i++) {
        cout << arr[i] << ' ';
    }
    cout << endl;
}

int main() {
    int totalCases = 0, arrSize = 0;
    
    cin >> totalCases;

    for(int i = 0; i < totalCases; i++) {
        cin >> arrSize;
        int arr[arrSize];

        for(int j = 0; j < arrSize; j++) {
            cin >> arr[j];
        }

        mergeSort(arr, 0, arrSize - 1);
        printArray(arr, arrSize);
        
    }

    return 0;
}
