#include "RBTree.h"
#include <stdio.h>
#include <stdlib.h>


Node* create_node(int val) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->left = NULL;
    node->right = NULL;
    node->parent = NULL;
    node->val = val;
    node->color = RED;

    return node;
}

void left_rotation(Node **root, Node *x) {
    Node* y = x->right;
    Node* T2 = y->left;

    y->left = x;
    x->right = T2;

    y->parent = x->parent;

    if (x->parent == NULL) {
        *root = y;
    } else if (x->parent->left == x) {
        x->parent->left = y;
    } else {
        x->parent->right = y;
    }

    x->parent = y;

    if (T2 != NULL) {
        T2->parent = x;
    }   
}

void right_rotation(Node **root, Node *y) {
    Node* x = y->left;
    Node* T2 = x->right;

    x->right = y;
    y->left = T2;

    x->parent = y->parent;

    if (y->parent == NULL) {
        *root = x;
    } else if (y->parent->left == y) {
        y->parent->left = x;
    } else {
        y->parent->right = x;
    }

    y->parent = x;

    if (T2 != NULL) {
        T2->parent = y;
    }    
}

void treeFixup(Node **root, Node *z) {
    while (z->parent != NULL && z->parent->color == RED) 
    {
        Node *gp = z->parent->parent;
        if (gp->left == z->parent) 
        {
            Node *uncle = gp->right;

            if (uncle != NULL && uncle->color == RED) 
            {
                gp->color = RED;
                uncle->color = BLACK;
                z->parent->color = BLACK;

                z = gp;
            } 
            else 
            { 
                if (z->parent->right == z) 
                {
                    left_rotation(root, z->parent);
                    z = z->left;
                }

                right_rotation(root, gp);
                gp->color = RED;
                z->parent->color = BLACK;
            }
        } 
        else 
        {
            Node *uncle = gp->left;

            if (uncle != NULL && uncle->color == RED) 
            {
                gp->color = RED;
                uncle->color = BLACK;
                z->parent->color = BLACK;

                z = gp;
            } 
            else 
            { 
                if (z->parent->left == z) 
                {
                    right_rotation(root, z->parent);
                    z = z->right;
                }

                left_rotation(root, gp);
                gp->color = RED;
                z->parent->color = BLACK;
            }
        }
    }

    (*root)->color = BLACK;
}

void bst_insert(Node** root, int v) {
    if (*root == NULL) {
        *root = create_node(v);
        (*root)->color = BLACK;
        return;
    }
    
    Node* it = *root;
    while (1) {
        if (it->val > v) 
        {
            if (it->left == NULL) 
            {
                it->left = create_node(v);
                it->left->parent = it;
                it = it->left;
                break;
            }

            it = it->left;
        } 
        else 
        {
            if (it->right == NULL) 
            {
                it->right = create_node(v);
                it->right->parent = it;
                it = it->right;
                break;
            }

            it = it->right;
        }
    }

    treeFixup(root, it);
}

void printTree(Node* root) {
    if (root == NULL) {
        return;
    }
    printf("%d(%c) ", root->val, root->color == BLACK ? 'B' : 'R');
    printTree(root->left);
    printTree(root->right);
}

void printTreeInorder(Node* root) {
    if (root == NULL) {
        return;
    }

    printTreeInorder(root->left);
    printf("%d(%c) ", root->val, root->color == BLACK ? 'B' : 'R');
    printTreeInorder(root->right);



}

int get_B_height(Node* root)
{
    if(root == NULL)
    return 0;
    int left_h = get_B_height(root->left);
    int right_h = get_B_height(root->right);
    if(left_h > right_h)
    {
        if(root->color == BLACK)
            return 1 + left_h;
        else 
            return left_h;
    }
    else
    {
        if(root->color == BLACK)
            return 1 + right_h;
        else 
            return right_h;
    }
}

void free_tree(Node* root)
{
    if (root == NULL) {
        return;
    }
    free_tree(root->left);
    free_tree(root->right);
    free(root);
}

int is_balanced_b_height(Node * root)
{
    if(root == NULL)
        return 1;
    if(get_B_height(root->left) != get_B_height(root->right))
        return 0;
    else 
        return is_balanced_b_height(root->left) && is_balanced_b_height(root->right);
}

int is_root_B(Node * node)
{ 
    Node * current = node;
    while(current->parent != NULL)
    {
        current = current->parent;
    }
    if(current->color == BLACK)
        return 1;
    else
        return 0;
}   

int are_2_reds_not_consecutive(Node * root)
{
    if(root == NULL)
        return 1;
    
    
    if(root->color == RED)
    {
        if((root->left != NULL && root->left->color == RED) || (root->right != NULL && root->right->color == RED))
        {
            return 0;
        }
    }
    return are_2_reds_not_consecutive(root->left) && are_2_reds_not_consecutive(root->right);
    
}
int is_rb_tree(Node* root) 
{
    if(root == NULL)
    return 1;

    if(!is_balanced_b_height(root) || !is_root_B(root) || !are_2_reds_not_consecutive(root))
    {
        return 0;
    }
    else 
    {
        return 1;
    }
}