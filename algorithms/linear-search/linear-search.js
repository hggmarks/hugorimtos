"use strict";
exports.__esModule = true;
function linearSearch(arr, value) {
    for (var i = 0; i < arr.length; i++) {
        if (arr[i] === value) {
            return true;
        }
    }
    return false;
}
exports["default"] = linearSearch;

var testArr = [1, 2, 2311, 2674, 98, 1265, 8712, 3605, 61, 28, 73, 56, 912, 835, 4, 5, 6, 7];

console.log(linearSearch(testArr, 31));
