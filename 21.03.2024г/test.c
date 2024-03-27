#include <stdio.h>
#include "stdlib.h"
int isEven(int * a)
{
  if(*a % 2 == 0)
    return 1;
  else
    return 0;
}
int isOdd(int * a)
{
  if(*a % 2 != 0)
    return 1;
  else
    return 0;
}
int *filter(int *arr,int arrlen,int (*filt)(int*))
{
  int *newarr = (int*)malloc(arrlen*sizeof(int));
  if (newarr == NULL)
  {
    printf("Error");
    exit(1);
  }
  for(int i=0;i<arrlen;i++)
    {
      if(filt(&arr[i]) == 1)
        newarr[i] = arr[i];
        
      else
        newarr[i] =0;
    }
  return newarr;
}
int main(void) 
{
  int size =0;
  printf("Enter size:");
  do
    {
      scanf("%d",&size);
    }
  while(size<=0);
  int * arr = (int *)malloc(size*sizeof(int));
  if(arr == NULL)
  {
    printf("\nError Alocating memory");
    return 1;
  }
  for(int i=0;i<size;i++)
    {
      printf("Enter arr[%d]:",i);
      scanf("%d",&arr[i]);
    }
  int * arr2 = filter(arr,size,isEven);
  for(int i=0;i<size;i++)
    {
      printf("\narr2[%d] = %d ",i,arr2[i]);
    }
  int * arr3 = filter(arr,size,isOdd);
  printf("\n");
  for(int i=0;i<size;i++)
  {
    printf("\narr3[%d] = %d ",i,arr3[i]);
  }
  free(arr);
}