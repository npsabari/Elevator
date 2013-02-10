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

elevator* create_new_elevator(int , int);
void move_up(elevator *);
void move_down(elevator *);
void stop_elv(elevator *);
void unload_person(elevator *, person *);
void add_person(elevator *, person *);

#endif

