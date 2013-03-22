#ifndef FLOOR_H
#define FLOOR_H

#include "person.h"

typedef struct floor_ floor;

struct floor_{
    int levelNo;
    personList* listGoingUp,* listGoingDown;
};

floor* create_new_floor(int );

#endif
