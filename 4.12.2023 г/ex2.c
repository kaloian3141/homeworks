#include <stdio.h>
int main() 
{
  int a=15,b=18,result=a*b;
  
  for(int i=2;i<b;i++)
  {
    if(b%i==0&&a%i==0)
    result=result/i;
  }
  printf("%d",result);
}