#include <stdlib.h>
#include <assert.h>
#include "myDeque.h"

#define NUM_DIRECTIONS (2)

struct deque {
    struct deque *next[NUM_DIRECTIONS];
    char value;
};

Deque *
dequeCreate(char value)
{
    Deque *d;
    d = malloc(sizeof(struct deque));

    /* test is to deal with malloc failure */
    if(d) {
        d->next[DEQUE_FRONT] = d->next[DEQUE_BACK] = NULL;
        d->value = value;
    } 
    return d;
}

void
dequeWrite(Deque *d, char value) 
{
	if (!dequeIsEmpty(d)) {
		d->value = value;
	}
}
	
void
dequePush(Deque *d, int direction, char value)
{
    struct deque *e;  /* new element */

    assert(direction == DEQUE_FRONT || direction == DEQUE_BACK);

    e = malloc(sizeof(struct deque));
    assert(e);
    
    e->next[direction] = d->next[direction];
    e->next[!direction] = d;
    e->value = value;

    d->next[direction] = e;
}

char
dequePeek(Deque *d) 
{
	if (!dequeIsEmpty(d)) {
		return d->value;
	}
	
	return DEQUE_EMPTY;
}

char
dequePeekNext(Deque *d, int direction) 
{
	struct deque *e;
	
	assert(direction == DEQUE_FRONT || direction == DEQUE_BACK);
	
	e = d->next[direction];
	
	return dequePeek(e);
}

Deque *
dequeNext(Deque *d, int direction) {
	
	struct deque *e;
	
	assert(direction == DEQUE_FRONT || direction == DEQUE_BACK);
	
	e = d->next[direction];
	
	return e;
}		
	
char
dequePop(Deque *d, int direction)
{
    struct deque *e;
    int retval;

    assert(direction == DEQUE_FRONT || direction == DEQUE_BACK);

    e = d->next[direction];

    if (dequeIsEmpty(e)) {
        return DEQUE_EMPTY;
    }

    /* else remove it */
    d->next[direction] = e->next[direction];
    
    if (dequePeekNext(e, direction) != DEQUE_EMPTY) {
    	e->next[direction]->next[!direction] = d;
    }

    retval = e->value;

    free(e);

    return retval;
}

int
dequeIsEmpty(Deque *d)
{
    return d == NULL;
}

void
dequeDestroy(Deque *d)
{
    while(dequePeekNext(d, DEQUE_FRONT) != DEQUE_EMPTY) {
        dequePop(d, DEQUE_FRONT);
    }
    
    while(dequePeekNext(d, DEQUE_BACK) != DEQUE_EMPTY) {
        dequePop(d, DEQUE_BACK);
    }

    free(d);
}

int
convertDirection(char dir) 
{
	if (dir == '+') {
		return DEQUE_FRONT;
	}
	
	return DEQUE_BACK;
}
