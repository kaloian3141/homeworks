#include<stdio.h>
#include"vector.h"

void swap(int* a, int *b);
void siftUp(vector*v, int i);
void siftUp(vector*v, int i);
void insert(vector* v, int val);
int extractMax(vector* v);
void heapify(vector *v);
void heap_sort(vector * v);

int main()
{
    vector * v = init_vector(2);
    for(int i = 0;i<10;i++)
    {
        insert(v, i);
    }
    print_vector(v);
    heap_sort(v);
    print_vector(v);
}

void swap(int* a, int *b) 
{
    int c = *b;
    *b = *a;
    *a = c;
}

void siftUp(vector*v, int i) 
{
    int parent = 0;
    if (i % 2 == 1) 
    {
        parent = i / 2;
    } else if (i > 0) 
    {
        parent = i / 2 - 1;
    }

    if (v->arr[parent] < v->arr[i]) 
    {
        swap(&v->arr[parent], &v->arr[i]);
        siftUp(v, parent);
    }
}

void siftDown(vector* v, int i) 
{
    int left = 2*i + 1;
    int right = 2*i + 2;
    int maxIndex;    

    if (left < v->size) 
    {
        maxIndex = left;
    }
    if (right < v->size && v->arr[right] > v->arr[maxIndex]) 
    {
        maxIndex = right;
    }

    if (v->arr[i] < v->arr[maxIndex]) 
    {
        swap(&v->arr[i], &v->arr[maxIndex]);
        siftDown(v, maxIndex);
    }
}

int extractMax(vector* v) 
{
    int val = v->arr[0];

    v->arr[0] = v->arr[v->size-1];
    pop(v);
    siftDown(v, 0);

    return val;
}

void insert(vector* v, int val) 
{
    push(v, val);
    siftUp(v, v->size - 1);
}

void heapify(vector *v) 
{
    for (int i = 0; i < v->size; i++) 
    {
        siftUp(v, i);
    }
}

void heap_sort(vector *v)
{
    heapify(v);

    int original_size = v->size;
    for (int i = v->size - 1; i > 0; i--)
    {
        swap(&v->arr[0], &v->arr[i]);
        v->size--;
        siftDown(v, 0);
    }
    v->size = original_size;
}