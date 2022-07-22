#include <bits/stdc++.h>

using std::cin;
using std::cout;
using std::endl;

int binSearch(int sortedArr[], int low, int high, int term){

    int idx = 0, mid = 0;

    if (low <= high) {

        mid = low + (high - low)/2;
    
        if (term == sortedArr[mid]) {
            return mid;

        } else if (term > sortedArr[mid]) {
            return binSearch(sortedArr, mid+1, high, term);
        }

        return binSearch(sortedArr, low, mid-1, term);
    } else {
        return -1;
    }
}

int main() {
    int arrSize = 0, totalNumbers = 0, num = 0;

    cin >> arrSize;

    int sortedArr[arrSize];

    for (int i = 0; i < arrSize; i++) {
        cin >> sortedArr[i];
    }

    cin >> totalNumbers;

    for (int j = 0; j < totalNumbers; j++) {
        cin >> num;

        int result = binSearch(sortedArr, 0, arrSize - 1, num);

        result != -1 ? cout << result << endl : cout << 'x' << endl;
    }

    return 1;
}