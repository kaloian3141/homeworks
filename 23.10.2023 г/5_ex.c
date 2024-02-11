#include <stdio.h>
#define SWAP(A,B,TYPE) TYPE temp=A;\
    A=B;\
    B=temp; 

int main(void) {
    int a = 4;
    char b = 'z';
    printf("a = %d\n", a);
    printf("b = %c\n", b);
    SWAP(a, b, char);
    printf("a = %c\n", a);
    printf("b = %d\n", b);
    

}