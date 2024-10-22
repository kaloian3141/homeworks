#ifndef H_LIST_
#define H_LIST_

typedef struct Node {
    int val;
    struct Node* next;
    struct Node* prev;    
} Node;

typedef struct LList {
    Node* head;
    Node*tail;
} LList;

Node* init_node(int val);
LList* init_llist();
void insertEnd(LList* list, int val);
void insertBegin(LList* l, int val);

int popEnd(LList* list);
int popBegin(LList* l);
Node* getAt(LList* l, int i);
int getSize(LList * list);
void printList(LList *l);
void clear(LList* l);
void freeList(LList* l);

#endif