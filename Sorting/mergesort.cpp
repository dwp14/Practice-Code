#ifndef MERGESORT_CPP
#define MERGESORT_CPP
#include <iostream>

void mergesort(int *arr, int low, int high) {
    int middle = 0;

    if (low < high) {
        middle = (low + high) / 2; 

        mergesort(arr, low, middle);
        mergesort(arr, middle + 1, high);

        merge(arr, low, middle, high);
    }
}

void merge(int *arr, int low, int middle, int high) {
    int mergedSize = high - low + 1;
    int i = low;
    int j = middle + 1;
    int k = 0;
    int *newArr = new int[mergedSize];

    while(i <= middle && j <= high) {
        if(arr[i] <= arr[j]) {
            newArr[k] = arr[i];
            ++i;
            ++k;
        }
        else {
            newArr[k] = arr[j];
            ++k;
            ++j;
        }
    }
    while(i <= middle) {
        newArr[k] = arr[i];
        ++k;
        ++i;
    }
    while(j <= high) {
        newArr[k] = arr[j];
        k++;
        j++;
    }

    for(int i = 0; i < k; ++i) {
        arr[low + i] = newArr[i];
    }
}

#endif 