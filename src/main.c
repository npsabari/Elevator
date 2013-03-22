/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.

* File Name : main.c

* Purpose : Software Engineering Assignment 

* Creation Date : 10-02-2013

* Last Modified : Friday 22 March 2013 04:16:21 PM IST

* Created By : npsabari

_._._._._._._._._._._._._._._._._._._._._.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include "../headers/person.h"
#include "../headers/elevator.h"
#include "../headers/floor.h"

#define PRINT_DEBUG

#define MAX_SIMUL 1024 
#define SLEEP_TIME 1000
#define MAX_WT 550
#define MAX_WT2 700
#define CAPACITY 8
#define CAPACITY2 10
#define abs(a) (a >= 0 ? a : -a)

static int uniqueId = 0;

int findClosest(elevator* elv, personList* pq){
    int minval, val;
    minval = MAXLEVEL + 1;
    val = -1;
    int curlvl = elv->curLevel;
    int type = elv->isMov;
    while(pq != NULL){
        switch(type){
            case 0: if(abs(curlvl-(pq->perv->start)) < minval){
                        val = pq->perv->start;
                        minval = abs(curlvl - (pq->perv->start));
                    }
                    break;
            case 1: if( curlvl >= pq->perv->start && curlvl-pq->perv->start < minval){
                        val = pq->perv->start;
                        minval = curlvl - pq->perv->start;
                    }
                    break;
            case 2: if(curlvl <= pq->perv->start && pq->perv->start-curlvl < minval){
                        val = pq->perv->start;
                        minval = pq->perv->start-curlvl;
                    }
                    break;
        }
        pq = pq->next;
    }
#ifdef PRINT_DEBUG
/*    if(val != -1)
        printf("The closest point is %d\n", val);
*/
#endif
    personList* lst = elv->passengerList;
    while(lst != NULL){
        switch(type){
            case 0: if(abs(curlvl-lst->perv->start) < minval){
                        val = lst->perv->start;
                        minval = abs(curlvl-lst->perv->start);
                    }
                    break;
            case 1: if(curlvl >= lst->perv->start && curlvl-lst->perv->start < minval){
                        val = lst->perv->start;
                        minval = curlvl- lst->perv->start;
                    }
                    break;
            case 2: if(curlvl <= lst->perv->start && lst->perv->start-curlvl < minval){
                        val = lst->perv->start;
                        minval = lst->perv->start-curlvl;
                    }
                    break;
        }
        lst = lst->next;
    }

    return val;
}

void createPerson(personList** queue, floor** fl){
    int strt, end, wt;
    wt = rand()%100 + 20;
    strt = rand()%(MAXLEVEL+1);
    while((end = rand()%(MAXLEVEL+1)) == strt);

    person* new_per = create_new_person(++uniqueId, wt, strt, end);
    add_elmt(strt < end? &(fl[strt]->listGoingUp) : &(fl[strt]->listGoingDown), new_per); 
    add_elmt(queue, new_per);
    printf("Person %d wants to go from %d to %d\n", new_per->uniqueId, strt, end);
}

void moveTowards(elevator* elv, floor* fl, personList** queue){
    if(fl->levelNo == elv->curLevel){
        int type = elv->isMov;
        personList* tmp = NULL;
        switch(type){
            case 0: /*Prefer going down*/
                    tmp = fl->listGoingUp;
                    while(tmp != NULL && elv->curWt <= elv->maxWt && elv->curCount <= elv->capacity){
                        if(delete_elmt1(&(fl->listGoingUp), tmp->perv->uniqueId)){
                            delete_elmt(queue, tmp->perv);
                            add_person(elv, tmp->perv);
                            printf("Person %d is getting into the elevator\n", tmp->perv->uniqueId);
                        }
                        tmp = tmp->next;
                    }
                    break;
            case 1:
                    tmp = fl->listGoingDown;
                    while(tmp != NULL && elv->curWt <= elv->maxWt && elv->curCount <= elv->capacity){
                        if(delete_elmt1(&(fl->listGoingUp), tmp->perv->uniqueId)){
                            add_person(elv, tmp->perv);
                            printf("Person %d is getting into the elevator\n", tmp->perv->uniqueId);
                            delete_elmt(queue, tmp->perv);
                        }
                        tmp = tmp->next;
                    }
                    tmp = fl->listGoingUp;
                    while(tmp != NULL && elv->curWt <= elv->maxWt && elv->curCount <= elv->capacity){
                        if(delete_elmt1(&(fl->listGoingUp), tmp->perv->uniqueId)){
                            add_person(elv, tmp->perv);
                            printf("Person %d is getting into the elevator\n", tmp->perv->uniqueId);
                            delete_elmt(queue, tmp->perv);
                        }
                        tmp = tmp->next;
                    }
                    break;
            case 2:
                    tmp = fl->listGoingUp;
                    while(tmp != NULL && elv->curWt <= elv->maxWt && elv->curCount <= elv->capacity){
                        if(delete_elmt1(&(fl->listGoingUp), tmp->perv->uniqueId)){
                            add_person(elv, tmp->perv);
                            printf("Person %d is getting into the elevator\n", tmp->perv->uniqueId);
                            delete_elmt(queue, tmp->perv);
                        }
                        tmp = tmp->next;
                    }
                    tmp = fl->listGoingDown;
                    while(tmp != NULL && elv->curWt <= elv->maxWt && elv->curCount <= elv->capacity){
                        if(delete_elmt1(&(fl->listGoingDown), tmp->perv->uniqueId)){
                            add_person(elv, tmp->perv);
                            printf("Person %d is getting into the elevator\n", tmp->perv->uniqueId);
                            delete_elmt(queue, tmp->perv);
                        }
                        tmp = tmp->next;
                    }
                    break;
        }
    }
    else{
        int type = elv->isMov;
        int curlvl = elv->curLevel;
        switch(type){
            case 0: if(curlvl > fl->levelNo)
                        move_down(elv);
                    else
                        move_up(elv);
                    break;
            case 1: move_down(elv);
                    break;
            case 2: move_up(elv);
                    break;
        }
    }
}

void servePerson(elevator* elv, int *cnt){
    personList* tmp = elv->passengerList;
    while(tmp != NULL){
        if(tmp->perv->dest == elv->curLevel){
            printf("Person %d who started at %d is getting down at %d\n", tmp->perv->uniqueId, tmp->perv->start, tmp->perv->dest);
            unload_person(elv, tmp->perv);
            (*cnt)++;
        }
        tmp = tmp->next;
    }
}

void moveElevator(elevator* elv){
    personList* lst = elv->passengerList;
    if(elv->isMov == 2)
        move_up(elv);
    else if(elv->isMov == 1)
        move_down(elv);
    else
        move_up(elv);
}

int checkqueue(elevator** lst, personList* pq){
    if(list_length(lst[0]->passengerList) > 0 || list_length(lst[1]->passengerList) > 0 || list_length(pq) > 0)
        return 1;
    return 0;
}

int main(){
    int i = 0;
    int numPersons = 0;
    int numServed = 0;
    personList* queue = NULL;
    srand(time(NULL));

    floor* floorLst[MAXLEVEL+1];

    for(i = 0; i <= MAXLEVEL; ++i)
        floorLst[i] = create_new_floor(i);

    elevator* elvLst[2];
    elvLst[0] = create_new_elevator(CAPACITY, MAX_WT);
    elvLst[1] = create_new_elevator(CAPACITY2, MAX_WT2);

    for(i = 0; i < MAX_SIMUL && numServed < MAX_PERSONS; ++i, usleep(SLEEP_TIME)){
#ifdef PRINT_DEBUG
        printf("------------------------Time stamp %d-------------------------------\n", i);
        printf("Elevator 1 is at %d\tElevator 2 is at %d\n", elvLst[0]->curLevel, elvLst[1]->curLevel);
#endif
        servePerson(elvLst[0], &numServed);
        servePerson(elvLst[1], &numServed);
        if(rand()%10 < 4 && numPersons <= MAX_PERSONS+124){
            createPerson(&queue, floorLst);
            ++numPersons;
#ifdef PRINT_DEBUG
//            printf("After adding queue length is %d\n", list_length(queue));
#endif
        }
        if(queue != NULL){
            int closest1 = findClosest(elvLst[0], queue);
            int closest2 = findClosest(elvLst[1], queue);
            if(closest1 == closest2 && closest1 != -1){
                if(abs(elvLst[0]->curLevel - closest1) < abs(elvLst[1]->curLevel - closest2)){
                    moveTowards(elvLst[0], floorLst[closest1], &queue);
                }
                else{
                    moveTowards(elvLst[1], floorLst[closest2], &queue);
                }
            }
            else{
                if(closest1 != -1)
                    moveTowards(elvLst[0], floorLst[closest1], &queue);
                if(closest2 != -1)
                    moveTowards(elvLst[1], floorLst[closest2], &queue);
            }
        }
        servePerson(elvLst[0], &numServed);
        servePerson(elvLst[1], &numServed);
        if(elvLst[0]->curCount != 0)
            moveElevator(elvLst[0]);
        if(elvLst[1]->curCount != 0)
            moveElevator(elvLst[1]);
        if(list_length(queue) == 0){
            if(list_length(elvLst[0]->passengerList) != 0)
                stop_elv(elvLst[0]);
            if(list_length(elvLst[1]->passengerList) != 0)
                stop_elv(elvLst[1]);
        }

    }
    return 0;
}
