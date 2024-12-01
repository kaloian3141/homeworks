#include<stdio.h>
#include<stdlib.h>
#include"tree.h"

int find_max(Node * tree);
int find_min(Node * tree);
int is_bst(Node * tree);
void put_bst_in_arr(Node *current, int *arr, int *index);
int get_height(Node * root);
int get_bst_size(Node * root);
Node * delete_node_from_bst(Node * root, int val_for_delete);
Node * find_min_node(Node * current);
void print_tree_in_levels(Node* root);
void print_current_level(Node* root, int level);
void sum_root_to_leaf(Node * root, int sum);
int sum_root_to_leaf_R(Node * root, int sum);
void delete_all_leaves(Node * root);
Node * delete_all_leaves_R(Node * root);
int get_k_th_biggest(Node * root, int k);
int get_k_th_smallest(Node * root, int k);
void have_same_structure(Node * root1, Node * root2);
int have_same_structure_R(Node * root1, Node * root2);
Node * arr_to_balanced_bst(int * arr, int size);
Node * arr_to_balanced_bst_R(int * arr, int l, int r);

int main()
{
    Node * tree1 = create_node(5);
    bst_insert(tree1, 2);
    bst_insert(tree1, 3);
    bst_insert(tree1, 4);
    bst_insert(tree1, 1);
    bst_insert(tree1, 6);
    print_tree_in_levels(tree1);
    printf("min = %d, max = %d, height = %d, size = %d\n",find_min(tree1), find_max(tree1), get_height(tree1), get_bst_size(tree1));
    Node * deleted_node = delete_node_from_bst(tree1, 3);
    print_tree_in_levels(tree1);
    int k = 2;
    printf("%dth smallest element = %d\n", k, get_k_th_smallest(tree1, k));
    printf("%dth biggest element = %d\n", k, get_k_th_biggest(tree1, k));
    sum_root_to_leaf(tree1, 11);
    Node * tree2 = create_node(7);
    bst_insert(tree2, 11);
    bst_insert(tree2, 12);
    bst_insert(tree2, 3);
    bst_insert(tree2, 2);
    bst_insert(tree2, 1);
    bst_insert(tree2, 5);
    bst_insert(tree2, 6);
    print_tree_in_levels(tree2);
    delete_all_leaves(tree2);
    print_tree_in_levels(tree2);
    have_same_structure(tree1, tree2);
    
}

int find_max(Node * current)
{
    if(current == NULL)
    {
        printf("Empty tree\n");
        return 0;
    }
   if(current ->right == NULL)
    return current->val;
   return find_max(current->right);
}

int find_min(Node * current)
{
    if(current == NULL)
    {
        printf("Empty tree\n");
        return 0;
    }
   if(current ->left == NULL)
    return current->val;
   return find_min(current->left);
}

void put_bst_in_arr(Node *current, int *arr, int *index) {
    if (current == NULL) {
        return;
    }
    put_bst_in_arr(current->left, arr, index);
    arr[(*index)++] = current->val;
    put_bst_in_arr(current->right, arr, index);
}

int get_bst_size(Node * root)
{
    if(root == NULL)
    return 0;

    return 1 + get_bst_size(root->left) + get_bst_size(root->right);
} 

int get_height(Node * root)
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

int is_bst(Node *root) 
{
    if (root == NULL) {
        return 1; 
    }
    int * arr = (int*)malloc(get_bst_size(root) * sizeof(int));
    if (arr == NULL) {
        printf("Error alocating memory\n");
        exit(1);
    }
    int index = 0;
    put_bst_in_arr(root, arr, &index);
    for (int i=1;i<index;i++) {
        if (arr[i]<=arr[i-1]) {
            free(arr);
            return 0; 
        }
    } 
    free(arr);
    return 1;
}

Node * find_min_node(Node * current)
{
    if(current == NULL)
    {
        printf("Empty tree\n");
        return 0;
    }
   if(current->left == NULL)
    return current;
   return find_min_node(current->left);

}

Node * delete_node_from_bst(Node * root, int val_for_delete)
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

void delete_all_leaves(Node * root)
{
    Node * a = delete_all_leaves_R(root);
    free(a);
}

int is_leaf(Node * root)
{
    if(root->left == NULL && root->right == NULL)
    return 1;
    else return 0;

}

Node* delete_all_leaves_R(Node* root) 
{
    if (root == NULL) {
        return NULL;
    }

    if (is_leaf(root)) {
        free(root);
        return NULL;
    }

    root->left = delete_all_leaves_R(root->left);
    root->right = delete_all_leaves_R(root->right);

    return root;

}

void sum_root_to_leaf(Node * root, int sum)
{
    if(sum_root_to_leaf_R(root, sum))
    printf("Yes\n");
    else
    printf("No\n");

}

int sum_root_to_leaf_R(Node * root, int sum)
{
    if (root == NULL || root->val > sum) 
    {
        return 0;
    }
    sum-=root->val;

    if(is_leaf(root)) 
    {
        if(sum == 0)
        return 1;
        else 
        return 0;
    }
    return sum_root_to_leaf_R(root->left, sum) || sum_root_to_leaf_R(root->right, sum);
}

int get_k_th_biggest(Node * root, int k)
{

    if (root == NULL || k > get_bst_size(root) || k<=0) {
        return -1; 
    }
    int * arr = (int*)malloc(get_bst_size(root) * sizeof(int));
    if (arr == NULL) {
        printf("Error alocating memory\n");
        exit(1);
    }
    int index = 0;
    put_bst_in_arr(root, arr, &index);
    int result = arr[index-k];
    free(arr);
    return result;
}

int get_k_th_smallest(Node * root, int k)
{
    if (root == NULL || k > get_bst_size(root) || k<=0) {
        return -1; 
    }
    int * arr = (int*)malloc(get_bst_size(root) * sizeof(int));
    if (arr == NULL) {
        printf("Error alocating memory\n");
        exit(1);
    }
    int index = 0;
    put_bst_in_arr(root, arr, &index);
    int result = arr[k-1];
    free(arr);
    return result;
}

void have_same_structure(Node * root1, Node * root2)
{
    if(have_same_structure_R(root1, root2))
    printf("Yes\n");
    else 
    printf("No\n");
}

int have_same_structure_R(Node* root1, Node* root2) 
{
    if (root1 == NULL && root2 == NULL) 
        return 1; 
    
    if ((root1 != NULL && root2 == NULL) || (root1 == NULL && root2 != NULL)) 
       return 0;
    
    return have_same_structure_R(root1->left, root2->left) && have_same_structure_R(root1->right, root2->right);
}

Node * arr_to_balanced_bst(int * arr, int size)
{
    int l = 0,r = size-1;
    return arr_to_balanced_bst_R(arr, l, r);
}

Node * arr_to_balanced_bst_R(int * arr, int l, int r)
{
    if(l>r)
        return NULL;
    int mid = (l+r)/2;
    Node* root = create_node(arr[mid]);
    root->left = arr_to_balanced_bst_R(arr, l, mid - 1);
    root->right = arr_to_balanced_bst_R(arr, mid + 1, r);
    return root;
}