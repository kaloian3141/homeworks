#include "tree.h"
#include<stdio.h>
void invert_tree(Node * root);
int get_max_sum(Node * root);
int get_max_sum_R(Node * root);


int main()
{
    Node * tree = create_node(3);
    bst_insert(tree,2);
    bst_insert(tree,5);
    bst_insert(tree,1);
    print_tree_in_levels(tree);
    printf("max sum = %d\n", get_max_sum(tree));
}

void invert_tree(Node * root)
{
    if(root == NULL)
    return;

    if(root->left == NULL && root ->right ==NULL)
        return;
    else
    {
        Node * c = root->left;
        root->left = root->right;
        root->right = c;
        invert_tree(root->left);
        invert_tree(root->right);
    }

}

int get_max_sum(Node * root)
{
    
}

int get_max_sum_R(Node * root)
{
    
  
}