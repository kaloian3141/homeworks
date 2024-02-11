#include "mystring.h"
#include <stdio.h>
#include <string.h>
int main(int argc, char *argv[]) 
{
    char end_string[50];
    if (strlen(argv[1]) + strlen(argv[2]) > 50) {
        printf("too big strings.\n");
    }
    else
    {
      strcpy(end_string, argv[1]);
      strconcat(end_string, argv[2]);

      printf("%s\n", end_string);
    
    }
    return 0;
}