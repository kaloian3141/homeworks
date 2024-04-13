#include <stdio.h>
typedef unsigned long long unll;
typedef unll(*unllfunctionptr)(unll,unll);

unll add(unll a,unll b)
{
    return a+b;
}
unll reduce(unll * arr,unll arrlen, unllfunctionptr foo , unll a)
{
    unll result = a;
    for(int i=0;i<arrlen;i++)
    {
        result = foo(result,arr[i]);
    }
    return result;
}
int main(void)
{
   unll arr[] = {1,2,3,4,5};
   unll size = sizeof(arr)/sizeof(arr[0]);
   unll result = reduce(arr,size,add,0);
   printf("\n%llu",result);
}