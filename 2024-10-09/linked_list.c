#include "linked_list.h"
#include <stdlib.h>
#include <stdio.h>

Node* init_node(int val) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->next = NULL;
    node->prev = NULL;
    node->val = val;

    return node;
};
LList* init_llist() {
    LList* l = (LList*)malloc(sizeof(LList));
    l->head = NULL;
    l->tail = NULL;
    return l;
};

void insertBegin(LList* l, int val) {
    Node* newNode = init_node(val);
    if (isEmpty(l))
    {
        l->head = newNode;
        l->tail = newNode;
    }
    else{
    l->head->prev = newNode;
    newNode->next = l->head;
    l->head = newNode;
    }
};
void insertEnd(LList* list, int val)
{
    Node* newNode = init_node(val);
    if (isEmpty(list))
    {
        list->head = newNode;
        list->tail = newNode;
    }
    else{
        list->tail->next = newNode;
        newNode->prev = list->tail;
        list->tail = newNode;
    }

}
int popEnd(LList* list){
    if (isEmpty(list)) {
        printf("Cannot pop from empty list");
        exit(1);
    }
    int val = list->tail->val;
    Node * tmp = list->tail;
    list->tail = list->tail->prev;
    list->tail->next = NULL;
    free(tmp);
    
    return val;
}

int isEmpty(LList *l) {
    return l->head == NULL;
}

int popBegin(LList* l) {
    if (isEmpty(l)) {
        printf("Cannot pop from empty list");
        exit(1);
    }

    int val = l->head->val;
    Node* tmp = l->head;
    
    l->head = l->head->next;
    l->head->prev = NULL;
    free(tmp);

    return val;
}

Node* getAt(LList* l, int index) {
    Node *it = l->head;

    if (it == NULL) {
        printf("Cannot get from empty list");
        exit(0);
    }

    for (int i = 0; i < index; i++) {
        if (it == NULL) {
            printf("index bigger than list size\n");
            exit(0);    
        }
        
        it = it->next;
    }

    return it;
}

void printList(LList *l) {
    Node *it = l->head;

    if (it == NULL) {
        printf("Empty list.\n");
        return;
    }

    while (it != NULL) {
        printf("%d ", it->val);

        it = it->next;
    }
}

void clear(LList* l) {
    Node *it = l->head;

    while (it != NULL) {
        Node* tmp = it;

        it = it->next;

        free(tmp);
    }

    l->head = NULL;
}

void freeList(LList* l) {
    clear(l);
    free(l);
}