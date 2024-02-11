#include <stdio.h>
#define SQUARE(A,B) A*A+2*A*B+B*B

int main(void)
{
    int a=4,b=3;    
    printf("%d",SQUARE(a,b));
}