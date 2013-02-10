/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.

* File Name : person.c

* Purpose : Software Engineering Assignment 

* Creation Date : 10-02-2013

* Last Modified : Sunday 10 February 2013 11:22:43 PM IST

* Created By : npsabari

_._._._._._._._._._._._._._._._._._._._._.*/

#include <stdlib.h>
#include <string.h>
#include "person.h"

person* create_new_person(int _id, int _wt, int _strt, int _dest){
    person* tmp = (person *)malloc(sizeof(person));
    tmp->uniqueId = _id;
    tmp->wt = _wt;
    tmp->strt = _strt;
    tmp->dest = _dest;
    tmp->status = 2;
}

int delete_elmt(personList** _list, person* _perv){
    personList* tmp, * prevtmp;
    prevtmp = NULL;
    for(tmp = *_list; tmp != NULL; prevtmp = tmp, tmp = tmp->next){
        if(compareTo(tmp->perv, _perv)){
            if(prevtmp == NULL)
                *_list = tmp->next;
            else
                prevtmp->next = tmp->next;
            free(tmp);
            return 1;
        }
    }
    return 0;
}

void add_elmt(personList** _list, person* _perv){
    personList* tmp;
    tmp = (personList *)malloc(sizeof(personList));
    tmp->perv = _perv;
    if(*_list == NULL){
        *_list = tmp;
        tmp->next = NULL;
    }
    else{
        tmp->next = *_list;
        *_list = tmp;
    }
}

int list_length(personList* _list){
    int len = 0;
    for(; _list != NULL; _list = _list->next, ++len);
    return len;
}

int compareTo(person* a, person* b){
    return (a->uniqueId == b->uniqueId) ? 1 : 0;
}
