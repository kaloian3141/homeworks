#include <stdio.h>

void swap(int *a, int *b);
void printArray(int *arr, int size);
void quickSort(int *arr, int size);
void quickSortR(int *arr, int l, int r);
int partition(int *arr, int l, int r);

int main() {
    int arr[10] = {2,5,1,6,4,8,4,10,3,1 };
    int size = sizeof(arr) / sizeof(arr[0]);
    printArray(arr, size);
    quickSort(arr, size);
    printArray(arr, size);
    return 0;
}

void swap(int *a, int *b) {
    int c = *a;
    *a = *b;
    *b = c;
}

void printArray(int *arr, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void quickSort(int *arr, int size) {
    int l = 0, r = size - 1;
    quickSortR(arr, l, r);
}

void quickSortR(int *arr, int l, int r) {
    if (l >= r) 
    {
        return;
    }    
    int pivot = partition(arr, l, r);
    quickSortR(arr, l, pivot);   
    quickSortR(arr, pivot + 1, r);  
    
}

int partition(int *arr, int l, int r) {
    int pivot = arr[l]; 
    int i = l - 1,j = r + 1;
        while(1)
        {
            do
            {
                i++;
            }
            while(arr[i]<pivot);
            
            do
            {
                j--;
            }
            while(arr[j]>pivot);
                
            if(i >= j)
            {
              return j;
            }

            swap(&arr[i], &arr[j]);
        }
        return j;
    

    
}