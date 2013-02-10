/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.

* File Name : elevator.c

* Purpose : Software Engineering Assignment 

* Creation Date : 09-02-2013

* Last Modified : Sunday 10 February 2013 11:16:17 PM IST

* Created By : npsabari

_._._._._._._._._._._._._._._._._._._._._.*/

#include <stdlib.h>
#include <string.h>
#include "elevator.h"
#include "person.h"

elevator* create_new _elevator(int _capacity, int _maxwt){
    elevator* tmp = (elevator *)malloc(sizeof(elevator));
    tmp->capacity = _capacity;
    tmp->maxWt = _maxwt;
    tmp->passengerList = NULL;
    tmp->curLevel = 0;
    tmp->isMov = 0;
    tmp->curCount = 0;
    tmp->curWt = 0;
    return tmp;
}

void move_up(elevator* elv){
    if(elv->curLevel < MAX_LEVEL){
        elv->curLevel += 1;
        elv->isMov = 2;
    }
}

void move_down(elevator* elv){
    if(elv->curLevel > 0){
        elv->curLevel -= 1;
        elv->isMov = 1;
    }
}

void stop_elv(elevator* elv){
    if(isMov != 0){
        isMov = 0;
    }
}

void unload_person(elevator* elv, person* _perv){
    if(delete_elmt(&(elv->passengerList), _perv)){
        elv->curWt -= _perv->wt;
        elv->curCount -= 1;
    }
}

void add_person(elevator* elv, person* _perv){
    add_elmt(&(elv->passengerList), _perv);
    elv->curWt = _prev->wt;
    elv->curCount += 1;
}

