#include <stdio.h>

void swap(int *a, int *b) 
{
    int c = *a;
    *a = *b;
    *b = c;
}

void sort(int *arr,int arrlen,void(*swap)(int*,int*)) 
{
    int ok;
    for(int i=1;i <arrlen; i++) 
    {
        ok=1;
        for(int j=0; j<arrlen-i;j++)
        {
            if(*(arr+j) > *(arr+j+1))
            {
              swap(arr+j, arr+j+1);
              ok = 0;
            }
        }
        if(ok)
            break;
    }
}

int main(void) 
{
    int arr[] = {5,4,3,2,1};
    int arrlen = sizeof(arr) / sizeof(arr[0]);
    for(int i=0;i<arrlen;i++)
    {
        printf("arr[%d] - %d\n",i,*(arr+i));
    }
    sort(arr,arrlen,swap);
    printf("After sort:\n");
    for(int i=0;i<arrlen;i++)
    {
        printf("arr[%d] - %d\n",i,*(arr+i));
    }
}