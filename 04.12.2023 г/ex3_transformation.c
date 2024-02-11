#include "transformation.h"
#include <stdio.h>

int main() {
    char string[] = "123";
    struct transformation result = transform(string);
    printf("\n%ld\n%s", result.result, result.error);
    return 0;
}