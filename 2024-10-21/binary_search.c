#include<stdio.h>

void sort_array(int * arr,int size);
void print_arr(int *arr,int size);
int binary_search_recurtion(int * arr, int size, int val);
int binary_search_rec_1(int * arr,int l,int r,int mid,int val);
int binary_search(int * arr, int size, int val);

int main()
{
    int arr[10] = {10,9,8,7,6,5,4,3,2,1};
    int size = 10;
    printf("\n %d",binary_search(arr, size, 10));
    printf("\n %d",binary_search_recurtion(arr, size, 6));
    return 0;
}

void sort_array(int * arr,int size)
{
    for(int i = 0; i<size-1; i++) {
      
        for(int j = 0; j<size-i-1; j++) {
            if(arr[j]>arr[j+1])
            {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }  
}

void print_arr(int *arr,int size)
{
    printf("\n");
    for(int i = 0; i<size; i++)
    {
        printf("%d, ",arr[i]);
    }
    printf("\n");
}

int binary_search(int * arr, int size, int val)
{
    sort_array(arr, size);
    print_arr(arr, size);
  
    int mid = size/2, left = 0, right = size-1;
    while(left != right)
    {
        if(arr[mid] == val)
        {
            return mid;
        }
        else if (arr[mid] > val)
        {
            right = mid;
            mid = (right+left)/2; 
        }
        else if (arr[mid-1] < val)
        {
            left = mid;
            mid = (right+left)/2; 
        }
        if (left + 1 == right)
        {
            if(arr[left] == val)
            return left;
            else if (arr[right] == val)
            {
                return right;
            }
            else return -1;
            
        }
        
    }
}

int binary_search_rec_1(int * arr,int l,int r,int mid,int val)
{
 
  if (l + 1 == r)
        {
            if(arr[l] == val)
            return l;
            else if (arr[r] == val)
            {
                return r;
            }
            else return -1;
        }
        if(arr[mid] == val)
        {
            return mid;
        }
        else if (arr[mid] > val)
        {
            return binary_search_rec_1(arr, l, mid, (r+l)/2, val);
        }
        else if (arr[mid-1] < val)
        {
            return binary_search_rec_1(arr, mid, r, (r+l)/2, val);
        }
        
            
}

int binary_search_recurtion(int * arr, int size, int val)
{
    sort_array(arr,size);
    print_arr(arr, size);
    int mid = size/2, left = 0, right = size-1;
    return binary_search_rec_1(arr, left, right, mid, val);
}