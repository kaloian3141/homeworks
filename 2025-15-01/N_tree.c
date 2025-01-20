#include "N_tree.h"
#include <stdio.h>
#include <stdlib.h>

Node * init_node(int val, int children_count)
{
    Node * node = (Node*)malloc(sizeof(Node));
    node->val = val;
    node->children_count = children_count;
    if(children_count != 0)
    {
        node->children = (Node**)malloc(children_count * sizeof(Node*));
        if(node->children == NULL)
        {
            printf("error alocating memory\n");
            exit(1);
        }
        for(int i = 0; i<children_count; i++)
        {
            node->children[i] = NULL;
        }
    }
    return node;
}


void inorder(Node * root)
{
    if(root == NULL)
        return;

    for(int i = 0; i<root->children_count-1;i++)
    {
        inorder(root->children[i]);
    }

    printf("%d ", root->val);   
    if(root->children_count > 0)
        inorder(root->children[root->children_count-1]);
}

int get_height(Node * root)
{
    if(root == NULL)
        return 0;

    int max_h = 0;
    for (int i = 0; i < root->children_count; i++) {
        int child_h = get_height(root->children[i]);
        if (child_h > max_h) {
            max_h = child_h;
        }
    }

    return max_h + 1;
}

void BFS_R(Node * root, int current_level)
{
    if (root == NULL) {
        return;
    }
    if (current_level == 1) 
    {
        printf("%d ", root->val);
        return;
    } 
    else 
    {
        for(int i = 0; i<root->children_count;i++)
        {
            BFS_R(root->children[i], current_level-1);
        }
    }
}

void BFS(Node * root)
{
    int h = get_height(root);
    for (int i = 1; i<=h; i++) 
    {
        BFS_R(root, i);  
        printf("\n");
    }
}


void DFS(Node * root)
{
    if(root == NULL)
        return;
    printf("%d ", root->val);  

    for(int i = 0; i<root->children_count;i++)
    {
        inorder(root->children[i]);
    }

}


