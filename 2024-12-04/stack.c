#include "stack.h"
#include <stdlib.h>
#include <stdio.h>

stack_Node* init_node(Node * val) {
    stack_Node* node = (stack_Node*)malloc(sizeof(stack_Node));
    node->next = NULL;
    node->val = val;

    return node;
};

Stack* init_stack() {
    Stack* l = (Stack*)malloc(sizeof(Stack));

    l->top = NULL;

    return l;
};

void push(Stack* l, Node * val) {
    stack_Node* newNode = init_node(val);

    newNode->next = l->top;
    l->top = newNode;
};

int isEmpty(Stack *l) {
    return l->top == NULL;
}

Node * pop(Stack* l) {
    if (isEmpty(l)) {
        printf("Cannot pop from empty list");
        exit(1);
    }

    Node * val = l->top->val;
    stack_Node* tmp = l->top;
    l->top = l->top->next;

    free(tmp);

    return val;
}