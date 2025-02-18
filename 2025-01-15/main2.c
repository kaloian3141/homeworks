#include "N_tree.h"
#include<stdio.h>

int main()
{
    Node * tree = init_node(3, 4);
    Node * children1 = init_node(4,0);
    Node * children2 = init_node(1,0);
    Node * children3 = init_node(7,0);
    Node * children4 = init_node(8,1);
    Node * grandchildren1 = init_node(5,0);
    tree->children[0] = children1;
    tree->children[1] = children2;    
    tree->children[2] = children3;
    tree->children[3] = children4;
    tree->children[3]->children[0] = grandchildren1;
    inorder(tree);
    printf("\n\n");
    BFS(tree);
    printf("\n");
    DFS(tree);
}