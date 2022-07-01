#include <bits/stdc++.h>
#include <iostream>

using std::cout;
using std::endl;

void merge(int arr[], int low, int mid, int high) {
    int i = 0, j = 0, k = 0;

    int firstHalf[mid - low + 1];
    int secondHalf[mid - high];

    for (int count = 0; count <= high; ++count) {
        if (count <= mid) {
            firstHalf[count] = arr[count];
        } else {
            secondHalf[count % mid] = arr[count];
        }
    }

    while ((i < mid) && (j < high)) {
        if ( arr[i] <= arr[mid + j] )
    }
}

void mergeSort(int arr[], int low, int high) {

    int arrSize = sizeof(&arr) / sizeof(arr[0]);
    if ( arrSize > 1 ) {
        mergeSort(arr, low, arrSize/2);
        mergeSort(arr, (arrSize/2)+1, high);
        merge(arr, low, arrSize/2, high);
    }
}

int main() {
    int test[] = {1,2,3};
    cout << sizeof(test)/sizeof(test[0]) << endl;

    return 0;
}