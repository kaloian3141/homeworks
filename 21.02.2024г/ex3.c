#include <stdio.h>
void swap(void*a,void*b)
{
    int c = *(int*)a;
    *(int*)a = *(int*)b;
    *(int*)b = c;
}
int main(void)
{
    int a=5,b=6;
    swap(&a,&b);
    printf("a = %d , b = %d",a,b);
}