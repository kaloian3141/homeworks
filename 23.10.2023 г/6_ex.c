#include <stdio.h>

#define SWAP(A,B,TYPE) TYPE temp =A;\
    A=B;\
    B=temp; 
#define SORT(ARRAY, SIZE, TYPE, COMPARE) for(int i=0; i<SIZE-1; i++){\
        for (int j=0; j<SIZE-i-1; j++) {\
        if (ARRAY[j] COMPARE ARRAY[j+1]) {\
            SWAP(ARRAY[j],ARRAY[j+1],TYPE);\
        }\
        }\
    } 
int main(void)
{
  int arr[6]={7,3,7,2,1,2};
  SORT(arr,6,int,>)
  for(int i=0;i<6;i++)
  {
    printf("%d",arr[i]);
  }
}