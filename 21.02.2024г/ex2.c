#include <stdio.h>
#include <string.h>
int main(void)
{
    char name[20];
    fgets(name,20,stdin);
    char *p = strchr(name,'\n');
    if (p != NULL) {
        *p = '\0';
    }
    printf("%s\n", name);
}