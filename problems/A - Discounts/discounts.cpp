#include <bits/stdc++.h>
#include <ostream>

using std::cin;
using std::cout;
using std::endl;

void tempSwap(long long* a, long long* b) {

    long long temp = *a;
    *a = *b;
    *b = temp;

}

long long hoarePartition(long long arr[], long long low, long long high) {
    
    long long pivot = arr[low];
    long long i = low, j = high+1;

    do {

        do {
            i++;
        }while (arr[i] < pivot);

        do {
            j--;
        } while (arr[j] > pivot);

        tempSwap(&arr[i], &arr[j]);

    } while(i < j);

    tempSwap(&arr[i], &arr[j]);
    tempSwap(&arr[low], &arr[j]);

    return j;
}

void quickSort(long long arr[], long long low, long long high) {

    if (low < high) {
        long long splitPos = hoarePartition(arr, low, high);
        quickSort(arr, low, splitPos-1);
        quickSort(arr, splitPos+1, high);
    }
}

void fillArray(long long arr[], long long arrSize) {
    for (long long i = 0; i < arrSize; i++) {
        cin >> arr[i];
    }
}

int main() {

    long long numChocos, totalCost=0, numCoupons;

    cin >> numChocos;

    long long chocosArr[numChocos];

    fillArray(chocosArr, numChocos);

    cin >> numCoupons;

    long long valCoupons[numCoupons];

    fillArray(valCoupons, numCoupons);

    quickSort(chocosArr, 0, numChocos - 1);

    for (long long i = 0; i < numChocos; i++) {
        totalCost += chocosArr[i];
    }
    
    for (long long j = 0; j < numCoupons; j++) {
        cout << totalCost - chocosArr[numChocos - valCoupons[j]] << endl;
    }

    return  0;
}