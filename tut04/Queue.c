// An implementatino of a Queue ADT with Stacks
#include <stdlib.h>

// In this exercise you are forced to implement
// the stack ADT by using two stacks
#include "Stack.h"

struct queue {
	Stack s1;
	Stack s2;
};

typedef struct queue *Queue;

Queue QueueNew(void) {
	Queue q = malloc(sizeof(struct queue));
	q->s1 = StackNew();
	q->s2 = StackNew();
	return q;
}

void QueueEnqueue(Queue q, int item) {
	// TODO
}

int QueueDequeue(Queue q) {
	// TODO
    return 0;
}