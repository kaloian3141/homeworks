#include<stdio.h>
#include"tree.h"

Node * postporder_to_Tree(int * arr, int size);
Node * postporder_to_Tree_R(int * arr, int size, int l,int r);
int main()
{
    int arr[] = {0,1,4,6,9,5,17,16,25,27,44,42,56,34,20,10};
    int size = sizeof(arr)/sizeof(arr[0]);
    postporder_to_Tree(arr);
}

Node * postporder_to_Tree(int * arr, int size)
{
    return postporder_to_Tree_R(arr, size, 0, size-1);
}

Node * postporder_to_Tree(int * arr, int size, int l, int r)
{
    
}