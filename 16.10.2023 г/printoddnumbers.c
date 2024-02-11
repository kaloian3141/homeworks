#include <stdio.h>

int main() 
{

  int arr[2][3] = {{1, 7, 6}, {5, 2, 3}};

  for (int i = 0; i < 3; i++) 
  {
    for (int j = 0; j < 2; j++) 
    {
      if (arr[j][i] % 2 == 1) 
      {
        printf("%d ", arr[j][i]);
      }
    }
  }

  return 0;
}