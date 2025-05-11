#ifndef H_VECTOR
#define H_VECTOR
#include "graph.h"
typedef struct Vertex Vertex;
typedef struct vector {
    Vertex ** arr;
    int size;  
    int capacity;  
} vector;

vector* init_vector(int initialCapacity);
void push(vector* v, Vertex * val);
Vertex * pop(vector *v);
Vertex * getAt(vector *v, int i);
void free_vector(vector *v);
#endif