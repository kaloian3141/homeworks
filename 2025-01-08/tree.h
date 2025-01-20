#ifndef TREE_H
#define TREE_H

struct Node {
    int val;
    struct Node* left;
    struct Node* right;
} typedef Node;

Node* create_node(int);
Node* bst_insert(Node*, int);
void printTree(Node*);
Node * bst_balanced_insert(Node*root, int val);
int get_height(Node * root);
void print_tree_in_levels(Node* root);
void print_current_level(Node* root, int level);
#endif

