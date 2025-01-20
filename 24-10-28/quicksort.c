#include <stdio.h>
#include <stdlib.h>

void quicksort(int * arr);
void quicksortR(int * arr, int l, int r);
int partition(int * arr, int l, int r);
void swap(int a, int b);

int main()
{
    int arr[8] = {8,7,6,5,4,3,2,1};
    quicksort(arr);
    for(int i = 0; i<=8; i++ )
    {
        printf("arr[%d] = %d", i+1, arr[i]);
    }
    return 0;
}

void quicksort(int * arr)
{
    int size = sizeof(arr)/sizeof(arr[0]);
    quicksortR(arr, 0, size-1);
}

void quicksortR(int * arr, int l, int r)
{
    if(l >= r)
    {
        return;
    }
    int pivot = partition(arr, l, r);
    quicksort(arr, 0, pivot-1);
    quicksort(arr, pivot+1, r);
}
int partition(int * arr, int l, int r)
{
    int pivot = r;
        
}

void swap(int a, int b)
{
    int c = a;
    a = b;
    b = c;
}