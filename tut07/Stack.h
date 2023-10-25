#ifndef STACK_H
#define STACK_H

#include <stdbool.h>
#include <stdio.h>

typedef int Item;

typedef struct stack *Stack;

/**
 * Creates a new empty stack
 */
Stack StackNew(void);

/**
 * Frees all resources associated with the given stack
 */
void StackFree(Stack s);

/**
 * Adds an item to the top of the stack
 */
void StackPush(Stack s, Item it);

/**
 * Removes an item from the top of the stack and returns it
 * Assumes that the stack is not empty
 */
Item StackPop(Stack s);

/**
 * Gets the item at the top of the stack without removing it
 * Assumes that the stack is not empty
 */
Item StackTop(Stack s);

/**
 * Gets the size of the given stack
 */
int StackSize(Stack s);

/**
 * Returns true if the stack is empty, and false otherwise
 */
bool StackIsEmpty(Stack s);

/**
 * Prints the stack to the given file with items space-separated
 */
void StackDump(Stack s, FILE *fp);

#endif
