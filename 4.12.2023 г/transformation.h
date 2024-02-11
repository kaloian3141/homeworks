#ifndef TRANSFORMATION_H
#define TRANSFORMATION_H

struct transformation {
    long result;
    char error[100];
};
struct transformation transform(char* input);

#endif  
