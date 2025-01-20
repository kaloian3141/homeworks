#include "tree.h"
#include <stdio.h>
#include <stdlib.h>


Node* create_node(int val) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->left = NULL;
    node->right = NULL;
    node->val = val;

    return node;
}


Node* bst_insert(Node* root, int v) {
    if (root == NULL) {
        return create_node(v);
    }
    
    if (root->val > v) {
        root->left = bst_insert(root->left, v);
    }
    else {
        root->right = bst_insert(root->right, v);
    }

    return root;
}


void printTree(Node* root) {
    if (root == NULL) {
        return;
    }


    printTree(root->left);
    printf("%d ", root->val);
    printTree(root->right);
}

void print_current_level(Node* root, int level) {
    if (root == NULL) {
        return;
    }
    if (level == 1) 
    {
        printf("%d ", root->val);
        return;
    } 
    else 
    {
        print_current_level(root->left, level-1);
        print_current_level(root->right, level-1);
    }
}

void print_tree_in_levels(Node* root) {
    int h = get_height(root);  
    for (int i = 1; i<=h; i++) 
    {
        print_current_level(root, i);  
        printf("\n");
    }
}

int get_height(Node * root)
{
    if(root == NULL)
    return 0;
    int left_h = get_height(root->left);
    int right_h = get_height(root->right);
    if(left_h > right_h)
    return 1 + left_h;
    else
    return 1 + right_h;
}
