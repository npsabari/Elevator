/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.

* File Name : floor.c

* Purpose : Software Engineering Assignment

* Creation Date : 11-02-2013

* Last Modified : Friday 22 March 2013 04:16:22 PM IST

* Created By : npsabari

_._._._._._._._._._._._._._._._._._._._._.*/

#include <stdlib.h>
#include <string.h>
#include "../headers/floor.h"
#include "../headers/person.h"

floor* create_new_floor(int _level){
    floor* tmp = (floor *)malloc(sizeof(floor));
    tmp->levelNo = _level;
    return tmp;
}
