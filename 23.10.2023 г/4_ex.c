
#include <stdio.h>
#define COMMAND(NAME,TYPE) TYPE ##_ ##NAME##_command
#define DEFINE_COMMAND(NAME,TYPE) void COMMAND(NAME,TYPE)(){\
printf("something");\
}
DEFINE_COMMAND(internal,quit)
int main(void) 
{
    COMMAND(internal,quit)();
}