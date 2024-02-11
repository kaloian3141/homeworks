#include<stdio.h>
#define COMPERE(x,y) if(x>y)printf("a is greater");\
else if(x==y)printf("a is equal to b");\
else printf("b is greater");
int main(void)
{
   int a,b;
   printf("a=");
   scanf("%d",&a);
   printf("b=");
   scanf("%d",&b);
   COMPERE(a,b)
}