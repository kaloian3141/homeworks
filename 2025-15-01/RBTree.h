#ifndef RBTREE_H
#define RBTREE_H

enum Color {
    RED,
    BLACK
} typedef Color;

struct Node {
    int val;
    struct Node* left;
    struct Node* right;
    struct Node * parent;
    Color color;
    
} typedef Node;

Node* create_node(int v);
void bst_insert(Node**root, int v);
void printTree(Node*root);
void left_rotation(Node**root, Node *x);
void right_rotation(Node**root, Node *y);
void treeFixup(Node **root, Node *z);
void printTreeInorder(Node* root);
void free_tree(Node* root);
int get_B_height(Node * root);
int is_rb_tree(Node* root);
int is_balanced_b_height(Node * root);
int is_root_B(Node * root);
int are_2_reds_not_consecutive(Node * root);
#endif
