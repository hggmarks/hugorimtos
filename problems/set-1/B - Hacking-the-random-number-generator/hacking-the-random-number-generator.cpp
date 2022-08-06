#include <bits/stdc++.h>

using std::cin;
using std::cout;
using std::endl;

void tempSwap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int hoarePartition(int arr[], int low, int high) {
    int pivot = arr[low];
    int i = low, j = high + 1;

    do {
        do {
            i++;
        } while(arr[i] < pivot);

        do {
            j--;
        } while (arr[j] > pivot);
        tempSwap(&arr[i], &arr[j]);
    } while(i < j);
    
    tempSwap(&arr[i], &arr[j]);
    tempSwap(&arr[low], &arr[j]);

    return j;
}

void quickSort(int arr[], int low, int high) {

    if(low < high){
        int splitPos = hoarePartition(arr, low, high);
        quickSort(arr, low, splitPos-1);
        quickSort(arr, splitPos+1, high);
    }
}

bool binarySearch(int arr[], int low, int high, int term) {
    int idx = 0, mid = 0;

    if (low <= high) {
        mid = low + (high - low)/2;

        if (term == arr[mid]){
            return true;

        } else if (term > arr[mid]) {
            return binarySearch(arr, mid+1, high, term);
        }

        return binarySearch(arr, low, mid-1, term);

    } else {
	    return false;
    }
}

void fillArray(int arr[], int arrSize) {
    for (int i = 0; i < arrSize; i++) {
        cin >> arr[i];
    }
}

int main() {
    int arrSize, k, totalNum = 0;

    cin >> arrSize;
    cin >> k;

    int arr[arrSize];

    for(int j = 0; j < arrSize; j++) {
            cin >> arr[j];
        }

    quickSort(arr, 0, arrSize-1);

    for(int i = 0; i < arrSize; i++){
        totalNum += binarySearch(arr, 0, arrSize-1, arr[i]+k);
    }
    
    cout << totalNum << endl;
    
    return 0;
}
