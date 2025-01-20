#include"RBTree.h"
#include<stdio.h>
#include<stdlib.h>

int main()
{
    Node * tree = NULL;
    for(int i = 1;i<10; i++)
    {
        bst_insert(&tree, i);
    }
    printTreeInorder(tree);
    printf("tree b h = %d\n", get_B_height(tree));
    printTreeInorder(tree);
    printf("\n%d\n", is_rb_tree(tree));


}

