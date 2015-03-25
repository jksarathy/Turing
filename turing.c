#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <stdio.h>
#include "myDeque.h"

#define DEFAULT_SYMBOL ('a')
#define DEFAULT_STATE (1)
#define HALTING_STATE (0)

int
main(int argc, char **argv)
{
	Deque *currentDeque;
	char symbol;
	int direction;
	int state;
	
	int count;
	char *instructions;
	int i;
	int j;
	int length;
	
	currentDeque = dequeCreate(DEFAULT_SYMBOL);
	state = DEFAULT_STATE;
	symbol = DEFAULT_SYMBOL;
	count = 0;
	
	while (state != HALTING_STATE) {
		//printf("count: %d\n", count);
		instructions = argv[state];
		length = strlen(instructions); 
		//printf("     instructions: %s\n", instructions);
		symbol = dequePeek(currentDeque);
		//printf("     symbol: %c, state: %d\n", symbol, state);
		i = symbol - DEFAULT_SYMBOL; 
		
		if ((j = i*3) < length) {
			//printf("     j: %d\n", j);
			symbol = instructions[j];
			direction = convertDirection(instructions[j+1]);
			state = instructions[j+2] - '0';
			//printf("     symbol: %c, direction: %d, state: %d\n", symbol, direction, state);
		}
		
		dequeWrite(currentDeque, symbol);
		
		//printf("Write worked\n");
		
		if (dequePeekNext(currentDeque, direction) == DEQUE_EMPTY) {
			//printf("creating new node\n");
			dequePush(currentDeque, direction, DEFAULT_SYMBOL);		
			//printf("created new deque\n");
		}
		
		currentDeque = dequeNext(currentDeque, direction);
		//printf("moved over\n");
		
		count++;
	}
		
	printf("%d\n", count);
	
	dequeDestroy(currentDeque);

    return 0;
}

