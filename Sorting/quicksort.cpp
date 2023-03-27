
void quicksort(int *arr, int size);
void quicksortHelper(int *arr, int low, int high);
int quickPartition(int *arr, int low, int high);

void quicksort(int *arr, int size) {
    quicksortHelper(arr, 0, size - 1);
}
void quicksortHelper(int *arr, int low, int high) {
    if(low >= high)
        return;
    int part = quickPartition(arr, low, high);
    quickPartition(arr, low, part);
    quickPartition(arr, part + 1, high);
}
int quickPartition(int *arr,int low,int high) {
    int mid = (low + high) / 2;
    int pivot = arr[mid];
    while(true) {
        while(arr[low] < pivot) 
            ++low;
        while(arr[high] > pivot)
            --high;
        if(low >= high)
            break;
        int temp = arr[low];
        arr[low] = arr[high];
        arr[high] = temp;
        ++low;
        --high;
    }
    return high;
}
