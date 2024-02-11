#ifndef SCHOOLROOM_H
#define SCHOOLROOM_H

#include "person.h"

struct SchoolRoom {
    int room_number;
    struct Person people_in_room[50];
};

#endif