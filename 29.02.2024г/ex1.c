#include <stdio.h>  
int str_len(char *str)
{
   int i=0;
   for (char *p = str;*p !='\0';p++) 
   {
    i++;
   }
   return i;
} 
int main(void)
{
    char str[] = "example";
    int str_legth = str_len(str);
    printf("%d\n",str_legth);
    return 0;
}