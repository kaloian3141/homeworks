#include <stdio.h>
#define PRINT(x) printf("%s\n",#x);\
printf("%d\n",x);\
printf("%s\n",__FILE__);\
printf("%d\n",__LINE__);
int main(void)
{
    int a=3;
    PRINT(a)
}