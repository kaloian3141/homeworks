#include <stdio.h>

void swap(void *a, void *b) {
    int c = *(int *)a;
    *(int *)a = *(int *)b;
    *(int *)b = c;
}

void bubblesort(int arr[], int arlen, int (*compare)(void *, void *), void (*swapelements)(void *, void *)) {
    int ok;
    for (int i = 1; i < arlen; i++) {
        ok = 1;
        for (int j = 0; j < arlen - i; j++) {
            if (compare(&arr[j], &arr[j + 1]) > 0) {
                swapelements(&arr[j], &arr[j + 1]);
                ok = 0;
            }
        }
        if (ok)
            break;
    }
}

int compareasc(const void *const a, const void *const b) {
    int result = 0;
    if (*(int *)a > *(int *)b)
        result = 1;
    else if (*(int *)a < *(int *)b)
        result = -1;
    else
        result = 0;
    return result;
}

int comparedesc(const void *const a, const void *const b) {
    int result = 0;
    if (*(int *)a < *(int *)b)
        result = 1;
    else if (*(int *)a > *(int *)b)
        result = -1;
    else
        result = 0;
    return result;
}

int main(void) {
    int arr[5] = {5, 4, 3, 2, 1};
    

    bubblesort(arr, 5, compareasc, swap);
   
    for (int i = 0; i < 5; i++)
        printf("[%d] - %d ", i, arr[i]);
    printf("\n");
    bubblesort(arr, 5, comparedesc, swap);
    for (int i = 0; i < 5; i++)
        printf("[%d] - %d ", i, arr[i]);
    printf("\n");

    return 0;
}