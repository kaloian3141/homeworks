#include "tree.h"
#include<stdio.h>
int is_heap(Node * root);
int is_leaf(Node * root);
int main()
{
    Node * tree = create_node(5);
    tree->left = create_node(4);
    tree->right = create_node(3);
    tree->left->left = create_node(2);
    tree->left->right = create_node(1);


}
int is_heap(Node * root)
{
    if(root == NULL)
    {
        return 1;
    }

    if(root->left->val < root->val && root->right->val < root->val)
    {
        return is_heap(root->left) && is_heap(root->right);
    } 
    else 
    {
        return 0;
    }  
         
 
    
    
  
}
int is_leaf(Node * root)
{
    if(root->left == NULL && root->right == NULL)
    return 1;
    else return 0;

}