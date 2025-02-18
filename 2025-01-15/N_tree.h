#ifndef N_TREE_H
#define N_TREE_H

struct Node
{
    int val;
    int children_count;
    struct Node ** children; 
} typedef Node;

Node * init_node(int val, int children_count);
void inorder(Node * root);
void DFS(Node * root);
void BFS(Node * root);
int get_height(Node * root);
#endif