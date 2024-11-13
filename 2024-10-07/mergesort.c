#include <stdio.h>

void printArray(int *arr, int size);
void merge_sort(int *arr, int size);
void merge_sort_R(int *arr, int l, int r);
void merge(int *arr, int l, int r, int mid);

int main() {
    int arr[10] = {7, 53, 1, 8, 4, 1, 9, 2, 4, 7};
    int size = sizeof(arr)/sizeof(arr[0]);
    printArray(arr, size); 
    merge_sort(arr, size);
    printArray(arr, size); 
    return 0;
}

void printArray(int *arr, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void merge_sort(int *arr, int size) {
    merge_sort_R(arr, 0, size - 1);
}

void merge_sort_R(int *arr, int l, int r) {
    if (l >= r)
        return;
    int mid = (l + r) / 2;
    merge_sort_R(arr, l, mid);
    merge_sort_R(arr, mid + 1, r);
    merge(arr, l, r, mid);
}

void merge(int *arr, int l, int r, int mid) {
    int j1 = mid - l + 1;
    int j2 = r - mid;
    int arr1[j1]; 
    int arr2[j2];

    for (int i = 0; i < j1; i++)
        arr1[i] = arr[l + i];
    for (int i = 0; i < j2; i++)
        arr2[i] = arr[mid + 1 + i];

    int i1 = 0, i2 = 0, k = l;
    while (i1 < j1 && i2 < j2) {
        if (arr1[i1] <= arr2[i2]) {
            arr[k] = arr1[i1];
            i1++;
        } else {
            arr[k] = arr2[i2];
            i2++;
        }
        k++;
    }

    while (i1 < j1) {
        arr[k] = arr1[i1];
        i1++;
        k++;
    }

    while (i2 < j2) {
        arr[k] = arr2[i2];
        i2++;
        k++;
    }


}