#include <iostream>

using namespace std;

void mergesort(int *arr, int low, int high);
void merge(int *arr, int low, int middle, int high);
void print(int *arr, int size);

int main() {
    int arr[] = {1,4,3,2,5};
    int size = 5; 

    cout << "Unsorted" << endl;
    for(int i = 0; i < size; ++i) {
        cout << arr[i] << endl;
    }
    mergesort(arr, 0, size - 1);

    cout << "Sorted" << endl;
    for(int i = 0; i < size; ++i) {
        cout << arr[i] << endl;
    }
    return 0;
}

void mergesort(int *arr, int low, int high) {
    int middle = 0;

    if (low < high) {
        middle = (low + high) / 2; 

        //cout << "Dividing array from " << low << " to " << high << " with middle at " << middle << endl;

        mergesort(arr, low, middle);
        mergesort(arr, middle + 1, high);

        //cout << "Merging array from " << low << " to " << high << endl;

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
        cout << "Left position: " << i << ", Right position: " << j << ", Merge position: " << k << endl;
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

void print(int *arr, int size)  {
    for(int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}