#include <stdio.h>
#include "quadraticroots.h"

int main() {

    QuadraticRootsResult result_int = findroots(1, 0, -4); 
    if (result_int.norealroots == 0)
        printf("x1, x2 = %.2Lf, %.2Lf\n", result_int.x1, result_int.x2);
    else
        printf("no real roots\n");

    QuadraticRootsResult result_float = findroots(1.0, 5.0, -2.75); 
    if (result_float.norealroots == 0)
        printf("x1, x2 = %.2Lf, %.2Lf\n", result_float.x1, result_float.x2);
    else
        printf("no real roots\n");

    return 0;
}