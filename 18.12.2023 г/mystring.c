#include "mystring.h"
#include <string.h>

int strlength(char str[]) {
    return strlen(str);
}

void strconcat(char str1[], char str2[]) {
    strcat(str1, str2);
}

int strcompare(char str1[], char str2[]) {
    return strcmp(str1, str2);
}