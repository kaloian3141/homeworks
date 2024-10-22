#include "linked_list.h"
#include <stdio.h>
void insertion_sort_array(int * arr, int n)
{
  for(int i = 1; i < n; i++)
  {
    int key = arr[i];
    int j = i - 1;
    while (j >= 0 && arr[j] > key) 
    {
        arr[j + 1] = arr[j];
        j = j - 1;
    }
    arr[j + 1] = key;
  }
}
void insertion_sort_list(LList * list)
{
  
}
int main(void)
{
    LList *list = init_llist();
    insertBegin(list, 3);
    insertBegin(list, 31);
    insertEnd(list, 4);
    printList(list);
    popEnd(list);
    printList(list);
    printf("\n");
    int arr1[5] = {5,4,3,2,1};
    int n = 5;
    insertion_sort_array(arr1, n);
    for(int i = 0; i<n; i++)
    {
        printf("arr[%d] = %d\n",i+1, arr1[i]);
    }
}