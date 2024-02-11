#include<stdio.h>
#define DEBUG 
void sort_and_sum(int Arr[],int n,int *sum);
int main(void)
{
    int arr[6]={7,3,7,2,1,2};
    int sum=0;
    
    sort_and_sum(arr,6,&sum);
    #ifdef DEBUG
    for(int i=0;i<6;i++) 
      {
        printf("Arr[%d]=%d\n",i,arr[i]);
      }
    for(int j=3;j<6;j=j+3)
    {
        printf("  Arr[%d]=%d\n",j,arr[j]);
    }
   
    #endif
    printf("sum=%d",sum);
}
void sort_and_sum(int Arr[],int n,int *sum)
{
    int i,min,mini,k;
    for(i=0;i<n;i++)
    {
      min=Arr[i];
      mini=i;
        for(k=i+1;k<n;k++)
          {
            if(Arr[k]<min)
            {
              min=Arr[k];
              mini=k;
            }
          }
      Arr[mini]=Arr[i];
      Arr[i]=min;
    }
    for(int j=3;j<6;j=j+3)
    {
      *sum=*sum+Arr[j];
    }
    
}