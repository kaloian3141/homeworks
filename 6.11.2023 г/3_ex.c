#include <stdio.h>

void bubbleSort(int arr[], int n);
void selectionSort(int arr[], int n);
void insertionSort(int arr[], int n);
void reverseArray(int arr[], int n);
int main(void) {
    int arr[6] = {1, 22, 12, 43, 21, 1};
    int n=6;
    #ifdef _WIN32
    bubbleSort(arr, n);
    #elif __linux__
    selectionSort(arr, n);
    #elif __APPLE__
    insertionSort(arr, n);
    #else
    reverseArray(arr, n);
    #endif
    for (int i=0;i<n;i++)
    {
        printf("%d\n", arr[i]);
    }
}
void bubbleSort(int arr[], int n)
{
    int i,j,c,ok=1;
      for(i=1;i<n;i++)
      {
        ok=1;
        for(j=0;j<n-i;j++)
          if(arr[j]>arr[j+1])
          {
            c=arr[j];
            arr[j]=arr[j+1];
            arr[j+1]=c;
            ok=0;
          }
        if(ok)break; 
      }
}
void selectionSort(int arr[], int n)
{
    int i,min,mini,k;
    for(i=0;i<n;i++)
    {
      min=arr[i];
      mini=i;
        for(k=i+1;k<n;k++)
          {
            if(arr[k]<min)
            {
              min=arr[k];
              mini=k;
            }
          }
      arr[mini]=arr[i];
      arr[i]=min;
    }
}
void insertionSort(int arr[], int n)
{
    int i,c,j;
     for(i=1;i<n;i++)
    {
       c=arr[i];
      for( j=i-1;j>=0;j--)
        {
          if(arr[j]>c)
            arr[j+1]=arr[j];
          else break;    
        }
      arr[j+1]=c;
    }
}
void reverseArray(int arr[], int n) 
{
    for (int i=0;i<n/2;i++)
    {
        int c = arr[i];
        arr[i] = arr[n-1-i];
        arr[n-1-i] = c;
    }
}








