#include <stdio.h>
#include "tree.h"
Node * postorder_to_tree(int *arr, int size);
Node * bst_insert_without_recurtion(Node * root, int val);
int main(void)
{
    int postorder[] = {0,1,4,6,9,5,17,16,25,27,44,42,56,34,20,10};
    int size = sizeof(postorder) / sizeof(postorder[0]);
    //left , right , root
    Node * tree = postorder_to_tree(postorder, size);
    print_tree_in_levels(tree);
    int inorder[] = {1, 10, 9, 11, 8, 6, 7, 0, 4, 5, 2, 14, 13, 17, 16, 15, 3, 12};
    int preorder[] = {0, 1, 6, 8, 9, 10, 11, 7, 2, 4, 5, 3, 13, 14, 15, 16, 17, 12};
    int size1 = sizeof(inorder) / sizeof(inorder[0]);
    bst_insert_without_recurtion(tree, 5);
    print_tree_in_levels(tree);
}

Node * postorder_to_tree(int *arr, int size)
{
    Node * tree = create_node(arr[size-1]);
    for(int i = size-2; i>0;i--)
    {
        bst_insert(tree, arr[i]);   
    }
    return tree;
}


Node * bst_insert_without_recurtion(Node * root, int val)
{
    Node * new_node = create_node(val);
    if(root == NULL)
    {
        return new_node;
    }
    Node * current = root;
    Node * prev;
    while (current != NULL)
    {
        prev = current;
        if (val < current->val) 
        {
            current = current->left;
        } 
        else 
        {
            current = current->right;
        }
    }
    if(val < prev->val)
    {
        prev->left = new_node;
    }
    else
    {
        prev->right = new_node;
    }

    return root;
}