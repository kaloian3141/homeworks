#include<stdio.h>
#include"tree.h"
#include"stack.h"
Node * bst_insert_without_recurtion(Node * root, int val);
Node * left_rotation(Node* x);
Node * right_rotation(Node* y);
Node * AVL_insert_without_recurtion(Node * root, int val);
int main()
{
    Node * tree = create_node(5);
    bst_insert_without_recurtion(tree, 6);
    bst_insert_without_recurtion(tree, 3);
    bst_insert_without_recurtion(tree, 4);
    bst_insert_without_recurtion(tree, 2);
    tree = AVL_insert_without_recurtion(tree, 1);
    print_tree_in_levels(tree);
    
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

Node * AVL_insert_without_recurtion(Node * root, int val)
{
    Node * new_node = create_node(val);
    if (root == NULL)
    {
        return new_node;
    }
    Stack * stack = init_stack();
    Node * current = root;
    Node * prev;
    while (current != NULL)
    {   push(stack, current);
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

    while (!isEmpty(stack)) 
    {
        Node* node = pop(stack);
        int balance = get_height(node->left) - get_height(node->right);
        if(balance > 1)
        {
            if(val > node->left->val)
            {
                node->left = left_rotation(node->left);
            }
            if (!isEmpty(stack)) 
            {
                Node* parent = stack->top->val;
                if (parent->left == node) 
                {
                    parent->left = right_rotation(node);
                } 
                else 
                {
                    parent->right = right_rotation(node);
                }
            } 
            else 
            {  
                root = right_rotation(node);
            }
        }
        if(balance < -1)
        {
            if(val < node->right->val)  
            {
                node->right = right_rotation(node->right);
            }
            
            if (!isEmpty(stack)) 
            {
                Node* parent = stack->top->val;
                if (parent->left == node) 
                {
                    parent->left = left_rotation(node);
                } 
                else 
                {
                    parent->right = left_rotation(node);
                }
            } 
            else 
            {

                root = left_rotation(node);
            }
        }
        
    }
    
    return root;

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