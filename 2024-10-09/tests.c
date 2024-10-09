#include "linked_list.h"

void insertion_sort_array(int * arr, int n)
{
  for(int i = 0; i < n; i++)
  {
    for(int j = 0; j<i; j++)
    {
        if(arr[j]>arr[i])
        {
            int tmp = arr[i];
            arr[i] = arr[j];
            arr[j] = tmp;
        }
    }
  }

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