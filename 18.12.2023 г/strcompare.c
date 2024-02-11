#include "mystring.h"
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) 
{
    printf("%d\n", strcompare(argv[1], argv[2]));
    return 0;
}