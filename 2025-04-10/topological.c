#include<stdio.h>
#include <stdlib.h>

typedef struct StackNode
{
    void * val;
    struct StackNode *next;
} StackNode;

typedef struct Stack
{
    StackNode *top;
} Stack;

StackNode* create_node(void *val) 
{
    StackNode * new_node = (StackNode*)malloc(sizeof(StackNode));
    new_node->next = NULL;
    new_node->val = val;
    return new_node;
}

Stack *init_stack()
{
    Stack *stack = (Stack *)malloc(sizeof(Stack));
    stack->top = NULL;
}

void push(Stack *stack, void * val)
{
    StackNode *node = create_node(val);
    node->next = stack->top;
    stack->top = node;
}

void * pop(Stack *stack)
{
    if (stack->top == NULL)
    {
        printf("Stack is empty.\n");
        exit(1);
    }

    void * val = stack->top->val;
    StackNode *tmp = stack->top;
    stack->top = stack->top->next;
    free(tmp);

    return val;
}

void clear_stack(Stack *stack)
{
    while (stack->top != NULL)
    {
        pop(stack);
    }

    free(stack);
}

typedef struct Edge{
    int from;
    int to;
}Edge;

void topological_search(Edge * edges[], int E, int V)
{
    
}



int main()
{

}

