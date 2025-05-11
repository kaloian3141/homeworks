#include "vector.h"
#include <stdio.h>
#include <stdlib.h>
#include "graph.h"

vector* init_vector(int initialCapacity) {
    vector* v = (vector*)malloc(sizeof(vector));
    v->arr = (Vertex**)malloc(initialCapacity * sizeof(Vertex*));
    v->size = 0; 
    v->capacity = initialCapacity;

    return v;
}

void push(vector *v, Vertex* val) 
{

    if (v->size + 1 > v->capacity) 
    {
        v->capacity = v->capacity * 2;
        Vertex **tmp = (Vertex**)realloc(v->arr, sizeof(Vertex*) * v->capacity);
        if (tmp == NULL) 
        {
            exit(0);
        }
        v->arr = tmp;    
    }

    v->size++;
    v->arr[v->size - 1] = val;
}

Vertex* pop(vector *v) 
{
    if (v->size == 0)
    {
        printf("cannot pop from empty array");
        exit(0);
    }

    Vertex* tmp = v->arr[v->size - 1];
    v->size--;

    return tmp;
}

Vertex * getAt(vector *v, int i) 
{
    if (i >= v->size)
    {
        exit(1);
    }
    return v->arr[i];
}



void free_vector(vector *v) 
{
    if(v->arr)
        free(v->arr);
    free(v);
}