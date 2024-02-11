#include "mystring.h"
#include <stdio.h>

int main(int argc, char *argv[]) {
    int length = strlength(argv[1]);
    printf("Length of the string: %d\n", length);

    return 0;
}