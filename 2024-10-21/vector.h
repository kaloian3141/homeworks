#ifndef H_VECTOR
#define H_VECTOR

typedef struct vector {
    int *arr;
    int size;  
    int capacity;  
} vector;

vector* init_vector(int initialCapacity);
void push(vector* v, int val);
int pop(vector *v);
int getAt(vector *v, int i);
void print_vector(vector *v) ;
void clear_vector(vector *v);
void free_vector(vector *v);
#endif