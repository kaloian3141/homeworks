#include "transformation.h"
#include <string.h>
struct transformation transform(char* string)
{  int ok=1;
   struct transformation a;
   a.result=0;
   
   for(int i=0 ; i<strlen(string);i++)
     {
      
      if(string[i]<'0'||string[i]>'9')
      {
        ok=0;
        break;
      }
     }
    if(ok)
    {
      strcpy(a.error, " ");
      for(int i=0;i<strlen(string);i++)
        {
          a.result = a.result * 10 + (string[i] - '0');
        }
    }
    else
    {
      a.result=0;
      strcpy(a.error, "Invalid input");
    }
   return a;
}