/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.

* File Name : elevator.c

* Purpose : Software Engineering Assignment 

* Creation Date : 09-02-2013

* Last Modified : Friday 22 March 2013 04:16:23 PM IST

* Created By : npsabari

_._._._._._._._._._._._._._._._._._._._._.*/

#include <stdlib.h>
#include <string.h>
#include "../headers/elevator.h"
#include "../headers/person.h"

elevator* create_new_elevator(int _capacity, int _maxwt){
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
    if(elv->curLevel < MAXLEVEL){
        elv->curLevel += 1;
        elv->isMov = 2;
    }
    else{
        elv->curLevel = 7;
        elv->isMov = 1;
    }
}

void move_down(elevator* elv){
    if(elv->curLevel > 0){
        elv->curLevel -= 1;
        elv->isMov = 1;
    }
    else{
        elv->curLevel = 0;
        elv->isMov = 2;
    }
}

void stop_elv(elevator* elv){
    if(elv->isMov != 0){
        elv->isMov = 0;
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
    elv->curWt = _perv->wt;
    elv->curCount += 1;
}

