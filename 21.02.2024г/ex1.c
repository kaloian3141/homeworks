#include <stdio.h>

int main(void)
{
    double a, b;
    scanf("%lf %lf", &a, &b);
    double *a1 = &a, *b1 = &b;
    printf("%p %lf\n", a1, *a1);
    printf("%p %lf\n", b1, *b1);
}