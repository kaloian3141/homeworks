#include <stdio.h>
#include "tree.h"
void print_tree_in_levels(Node* root);
void print_current_level(Node* root, int level);
int main()
{
    Node * tree = create_node(5);
    tree = bst_balanced_insert(tree, 1);
    tree = bst_balanced_insert(tree, 2);
    tree = bst_balanced_insert(tree, 3);
    tree = bst_balanced_insert(tree, 4);
    tree = bst_balanced_insert(tree, 5);
    tree = bst_balanced_insert(tree, 6);
    tree = bst_balanced_insert(tree, 7);

    print_tree_in_levels(tree);
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

Node * delete_node_avl(Node * root, int val_for_delete)
{
 if(root == NULL)
    {
    printf("Empty list\n");
    return root;
    }
    if(val_for_delete>root->val)
        root->right = delete_node_from_bst(root->right, val_for_delete);
    else if(val_for_delete<root->val)
        root->left = delete_node_from_bst(root->left, val_for_delete);
    else if(val_for_delete==root->val)
    {
        if(root->left == NULL)
        {
            Node * tempt = root->right;
            free(root);
            return tempt;
        }
        if(root->right == NULL)
        {
            Node * tempt = root->left;
            free(root);
            return tempt;
        }
        Node * min = find_min_node(root->right);
        root->val = min->val;
        root->right = delete_node_from_bst(root->right, min->val);
    }
    return root;

}