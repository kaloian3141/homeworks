#include "vector.h"
#include <stdio.h>
#include <stdlib.h>

vector* init_vector(int initialCapacity) {
    vector* v = (vector*)malloc(sizeof(vector));
    v->arr = (int*)malloc(initialCapacity * sizeof(int));
    v->size = 0; 
    v->capacity = initialCapacity;

    return v;
}

void push(vector *v, int val) {
    if (v->size + 1 > v->capacity) {
        v->capacity = v->size * 2;
        int *tmp = (int*)realloc(v->arr, v->capacity);
        if (tmp == NULL) {
            exit(0);
        }
        v->arr = tmp;    
    }

    v->size++;
    v->arr[v->size - 1] = val;
}

int pop(vector *v) {
    if (v->size == 0)
    {
        printf("cannot pop from empty array");
        exit(0);
    }

    int tmp = v->arr[v->size - 1];
    v->size--;

    return tmp;
}

int getAt(vector *v, int i) {
    if (i >= v->size)
    {
        exit(1);
    }
    return v->arr[i];
}

void print_vector(vector *v) {
    for (int i = 0; i < v->size; i++) {
        printf("%d ", getAt(v, i));
    }
    printf("\n");
}

void clear_vector(vector *v) {
    v->size = 0;
    free(v->arr);
    v->arr = (int*)malloc(2 * sizeof(int));
    v->capacity = 2;
}

void free_vector(vector *v) {
    free(v->arr);
    free(v);
}