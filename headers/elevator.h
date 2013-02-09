#ifndef ELEVATOR_H 
#define ELEVATOR_H

#include "person.h"

#define MAX_LEVEL 7

typedef struct elevator_ elevator;

struct elevator_{
    int capacity;
    int maxWt;
    int isMov;          //0 if not moving, 1 moving down, 2 moving up
    int curLevel;
    int curCount;
    int curWt;

    personList* passengerList;    
};

#endif

