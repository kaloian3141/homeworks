#include <stdio.h>
int compareasc(const void *const a,const void *const b) {
    int result= 0;
    if(*(int*)a > *(int*)b)
        result =1;
    else if(*(int*)a < *(int*)b)
        result =-1;
    else
        result =0;
    return result;
}

int comparedesc(const void *const a,const void *const b) {
    int result= 0;
    if(*(int*)a < *(int*)b)
        result =1;
    else if(*(int*)a < *(int*)b)
        result =-1;
    else
        result =0;
    return result;
}

int main(void) {
    int a = 10, b = 20;
    printf("%d\n", compareasc(&a,&b));
    printf("%d\n", comparedesc(&a,&b));
}