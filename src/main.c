/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.

* File Name : main.c

* Purpose : Software Engineering Assignment 

* Creation Date : 10-02-2013

* Last Modified : Monday 11 February 2013 02:14:03 AM IST

* Created By : npsabari

_._._._._._._._._._._._._._._._._._._._._.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include "person.h"
#include "elevator.h"
#include "floor.h"

#define MAX_SIMUL 10
#define SLEEP_TIME 500000
#define MAX_WT 550
#define MAX_WT2 700
#define CAPACITY 8
#define CAPACITY2 10

static int uniqueId;

int main(int argc, char *argv[]){
    int i = 0;
    personList* queue = NULL;
    srand(time(NULL));
    int strt, end, wt;

    floor* floorLst[MAXLEVEL+1];
    for(i = 0; i <= MAXLEVEL; ++i)
        floorLst[i] = create_new_floor(i);
    elevator* elvLst[2];
    for(i = 0; i < 2; ++i)
        elvLst[i] = create_new_elevator
    for(i = 0; i < MAX_SIMUL; ++i, usleep(SLEEP_TIME)){
        if(rand()%10 < 4){
            strt = rand()%(MAXLEVEL+1);
            while((end = rand()%(MAXLEVEL+1)) == strt);
            wt = rand()%100 + 20;
            person* new_per = create_new_person(++uniqueId, wt, strt, end);
            add_elmt(strt < dest ? &(floorLst[strt]->listGoingUp) : &(floorLst[strt]->listGoingDown), new_per); 
            add_elmt(&queue, new_per);
        }
        if(queue != NULL){
            
        }
    }
    return 0;
}
