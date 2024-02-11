#include<stdio.h>
#define ARRAY_SIZE 10
int main(void)
{
   #if defined(ARRAY_SIZE) && ARRAY_SIZE>=1 && ARRAY_SIZE<=10
   int Arr[ARRAY_SIZE];
   for(int i=0;i<ARRAY_SIZE;i++)
   {
      Arr[i]=1;
      for(int j=0;j<i;j++)
      {
         Arr[i]=Arr[i]*2;
      }
      printf("%d\n",Arr[i]);
   }
   #else
   printf("Invalid ARRAY_SIZE value.");
   #endif
}