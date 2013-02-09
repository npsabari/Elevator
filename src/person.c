/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.

* File Name : person.c

* Purpose : Software Engineering Assignment 

* Creation Date : 10-02-2013

* Last Modified : Sunday 10 February 2013 01:25:24 AM IST

* Created By : npsabari

_._._._._._._._._._._._._._._._._._._._._.*/

#include <stdlib.h>
#include <string.h>

person* create_new_person(int _id, int _wt, int _strt, int _dest){
    person* tmp = (person *)malloc(sizeof(person));
    tmp->uniqueId = _id;
    tmp->wt = _wt;
    tmp->strt = _strt;
    tmp->dest = _dest;
    tmp->status = 2;
}

int compareTo(person* a, person* b){
    return (a->uniqueId == b->uniqueId) ? 1 : 0;
}
