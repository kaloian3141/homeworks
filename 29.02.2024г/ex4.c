#include <stdio.h>
#define MAX_ROWS 20

void print_t(int (*arr)[4], int rows) 
{
  for (int i=0;i<rows;i++) 
  {
    printf("%d",i);
    for (int j=0;j<4;j++) 
    {
      printf("%d ",*(*(arr+i)+j));
      
    }
    printf("\n");
  }
}

int main(void) {
    int arr[MAX_ROWS][4] = 
    {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}
    };
    int rows = 3;

    print_t(arr, rows);
    return 0;
}