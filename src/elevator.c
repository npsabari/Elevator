/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.

* File Name : elevator.c

* Purpose : Software Engineering Assignment 

* Creation Date : 09-02-2013

* Last Modified : Sunday 10 February 2013 01:25:21 AM IST

* Created By : npsabari

_._._._._._._._._._._._._._._._._._._._._.*/

#include <stdlib.h>
#include <string.h>
#include "elevator.h"

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
    personList* tmp, * prevtmp;
    prevtmp = NULL;
    for(tmp = elv->passengerList; tmp != NULL; prevtmp = tmp, tmp = tmp->next){
        if(compareTo(tmp, _perv)){
            if(prevtmp == NULL)
                elv->passengerList = tmp->next;
            else
                prevtmp->next = tmp->next;
            elv->curWt -= tmp->wt;
            elv->curCount -= 1;
            free(tmp);
            break;
        }
    }
}

void add_person(elevator* elv, person* _perv){
    personList* tmp;
    tmp = (personList *)malloc(sizeof(personList));
    tmp->perv = _perv;
    if(elv->passengerList == NULL){
        elv->passengerList = tmp;
        tmp->next = NULL;
    }
    else{
        tmp->next = elv->passengerList;
        elv->passengerList = tmp;
    }
    elv->curWt = _prev->wt;
    elv->curCount += 1;
}

