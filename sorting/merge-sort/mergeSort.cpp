#include <bits/stdc++.h>
#include <iostream>

using std::cout;
using std::cin;
using std::endl;


/* void merge(int arr[], int low, int high) {
    int i = 0, j = 0, k = 0;

    int mid = low + (high - low)/2;
    int firstHalf[mid - low + 1];
    int secondHalf[mid - high];

    for (int count = 0; count <= high; ++count) {
        if (count <= mid) {
            firstHalf[count] = arr[count];
        } else {
            secondHalf[count % mid] = arr[count];
        }
    }

    int p = mid - low + 1;
    int q = high - mid;
    

    while ((i < p) && (j < q)) {
        if (firstHalf[i] < secondHalf[j]) {
            arr[k] = firstHalf[i];
            i++;
        } else {
            arr[k] = secondHalf[j];
            j++
        }
        k++;
    }
    
    if (i == p) {

    }
} */

void merge(int arr[], int low, int high) {
    int tempArr[high - low];

    for( int count = low; count < high; count++ ) {
        tempArr[count] = arr[count];
    }

    int mid = low + (high - low)/2;

    int i = low;
    int j = mid + 1;

    for (int cursor = low; cursor < high; cursor++) {
        if ( tempArr[i] <= tempArr[j] ) {
            arr[cursor] = tempArr[i++];
        } else if ( tempArr[i] > tempArr[j] ) {
            arr[cursor] = tempArr[j++];
        } else if ( i == (mid+1) ) {
            arr[cursor] = tempArr[j++];
        } else if ( j > high ) {
            arr[cursor] = tempArr[i++];
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
