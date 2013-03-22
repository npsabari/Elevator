/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.

* File Name : person.c

* Purpose : Software Engineering Assignment 

* Creation Date : 10-02-2013

* Last Modified : Friday 22 March 2013 04:16:24 PM IST

* Created By : npsabari

_._._._._._._._._._._._._._._._._._._._._.*/

#include <stdlib.h>
#include <string.h>
#include "../headers/person.h"

person* create_new_person(int _id, int _wt, int _strt, int _dest){
    person* tmp = (person *)malloc(sizeof(person));
    tmp->uniqueId = _id;
    tmp->wt = _wt;
    tmp->start = _strt;
    tmp->dest = _dest;
    tmp->status = 2;
    return tmp;
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
            return 1;
        }
    }
    return 0;
}

int delete_elmt1(personList** _list, int id){
    personList* tmp, * prevtmp;
    prevtmp = NULL;
    for(tmp = *_list; tmp != NULL; prevtmp = tmp, tmp = tmp->next){
        if(tmp->perv->uniqueId == id){
            if(prevtmp == NULL)
                *_list = tmp->next;
            else
                prevtmp->next = tmp->next;
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
        personList* tmp1 = *_list;
        while(tmp1->next != NULL)
            tmp1 = tmp1->next;
        tmp1->next = tmp;
        tmp->next = NULL;
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
