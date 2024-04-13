#include <stdio.h>

typedef union {
    long odd;
    short even;
} NumberUnion;

int main(void) 
{
  NumberUnion arr_of_union[10];
     for(int i=0;i<10;i++)
      {
        if (i%2 == 0) 
        {
            arr_of_union[i].even = i;
        } 
        else 
        {
            arr_of_union[i].odd = i;
        }
      }
     for(int i = 1;i<10;i+=2) 
     {
        printf("Index %d: %ld\n", i, arr_of_union[i].odd);
     }
     for(int i=0;i<10;i+=2) 
     {
        printf("Index %d: %hd\n", i, arr_of_union[i].even);
     }
}