#include <bits/stdc++.h>

using std::cout;
using std::cin;
using std::endl;

void swap(int *a, int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

int hoarePartition(int arr[], int low, int high){
    int pivot = arr[low];
    int i = low, j = high + 1;

    do {
        do {
            i++;
        } while (arr[i] < pivot);
        
        do {
            j--;
        } while (arr[j] > pivot);
        swap(&arr[i], &arr[j]);
        
    } while (i < j);
    swap(&arr[i], &arr[j]);
    swap(&arr[low], &arr[j]);

    return j;
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int splitPos  = hoarePartition(arr, low, high);
        quickSort(arr, low, splitPos-1);
        quickSort(arr, splitPos+1, high);
    }
}

void printArray(int arr[], int arrSize) {
    for (int i = 0; i < arrSize; i++) {
        cout << arr[i] << ' ';
    }
    cout << endl;
}

int main(){
    int totalCases = 0, arrSize = 0;
    
    cin >> totalCases;

    for(int i = 0; i < totalCases; i++) {
        cin >> arrSize;
        int arr[arrSize];

        for(int j = 0; j < arrSize; j++) {
            cin >> arr[j];
        }

        quickSort(arr, 0, arrSize - 1);
        printArray(arr, arrSize);
        
    }

    return 0;
}