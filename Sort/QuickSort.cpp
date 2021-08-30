//
// Created by Prongs on 2021/8/30.
//

int partition(int a[], int low, int high) {
    int pivot = a[low];
    while (low < high) {
        while (low < high && pivot <= a[high])
            high--;
        a[low] = a[high];
        while (low < high && pivot >= a[low])
            low--;
        a[high] = a[low];
    }
    a[low] = pivot;
    return low;
}

void quickSort(int a[], int low, int high) {
    if (low < high) {
        int p = partition(a, low, high);
        quickSort(a, low, p - 1);
        quickSort(a, p + 1, high);
    }
}
