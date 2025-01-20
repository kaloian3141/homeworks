#ifndef H_STACK_
#define H_STACK_
#include "tree.h"
typedef struct stack_Node {
    Node * val;
    struct stack_Node* next;
} stack_Node;

typedef struct Stack {
    stack_Node* top; 
} Stack;

stack_Node* init_node(Node * val);
Stack* init_stack();

void push(Stack* l, Node * val);
Node * pop(Stack* l);
int isEmpty(Stack *);

#endif