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

int get_height(Node* root)
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

Node * left_rotation(Node* x)
{
    Node* y = x->right;
    Node* T2 = y->left;
    y->left = x;
    x->right = T2;
    return y;
}

Node * right_rotation(Node* y)
{
    Node* x = y->left;
    Node* T2 = x->right;
    x->right = y;
    y->left = T2;
    return x;
}

Node * bst_balanced_insert(Node* root, int v)
{
    if (root == NULL) 
    {
        return create_node(v);
    }
    
    if (root->val > v) 
    {
        root->left = bst_balanced_insert(root->left, v);
    }
    else if(root->val < v) 
    {
        root->right = bst_balanced_insert(root->right, v);
    }
    
    int balance = get_height(root->left) - get_height(root->right);
    if (balance > 1)
    {
        if(v > root->left->val)
        {
            root->left = left_rotation(root->left);
        }
        return right_rotation(root);
    }
    if(balance < -1)
    {
        if(v < root->right->val)
        {
            root->right = right_rotation(root->right);
        }
        return left_rotation(root);
    }
    return root;
}



