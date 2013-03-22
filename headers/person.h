#ifndef PERSON_H
#define PERSON_H

#define MAX_PERSONS 16 

typedef struct person_ person;

struct person_{
    int uniqueId;
    int status;     //2 if not in inside the lift but waiting ; 1 if inside a lift ; 0 if not in the scene
    int start;
    int dest;
    int wt;
};

typedef struct personList_ personList;

struct personList_{
    person* perv;
    struct personList_* next;
};

person* create_new_person(int, int, int, int);
int delete_elmt(personList **, person *);
int delete_elmt1(personList **, int );
int list_length(personList *);
void add_elmt(personList **, person *);
int compareTo(person *, person *);

#endif
