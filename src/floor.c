/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.

* File Name : floor.c

* Purpose : Software Engineering Assignment

* Creation Date : 11-02-2013

* Last Modified : Monday 11 February 2013 12:08:08 AM IST

* Created By : npsabari

_._._._._._._._._._._._._._._._._._._._._.*/

#include <stdlib.h>
#include <string.h>
#include "floor.h"
#include "person.h"

floor* create_new_node(int _level){
    floor* tmp = (floor *)malloc(sizeof(floor));
    tmp->levelNo = _level;
    return tmp;
}
