#ifndef SCHOOLCLASS_H
#define SCHOOLCLASS_H

#include "person.h"

struct SchoolClass {
    struct Person students[26];
    char parallel;
    int class_number;
    struct Person class_teacher;
};

#endif