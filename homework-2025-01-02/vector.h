#ifndef H_VECTOR
#define H_VECTOR


typedef struct item
{
   char name[50];
   int count;
}item;
 
typedef struct vector {
    item *arr;
    int size;  
    int capacity;  
} vector;

vector* init_vector(int initialCapacity);
void push(vector* v, item val);
item pop(vector *v);
item getAt(vector *v, int i);
void print_vector(vector *v) ;
void clear_vector(vector *v);
void free_vector(vector *v);
#endif