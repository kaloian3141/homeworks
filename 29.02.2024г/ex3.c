#include <stdio.h>
#include <string.h>
void strhalf(char *string, char **p) 
{
    int half_legth = strlen(string)/2;
    *p = string+half_legth;
}
int main(void)
{
    char string[] = "1234567890";
    char *p;
    strhalf(string,&p);
    printf("%s\n", p);

}