#include <stdio.h>
#include <stdlib.h>

struct node {
	int value;
	struct node *next;
};

struct node *newNode(int val);
int listLength(struct node *l);

int main(void) {

    struct node *n1 = newNode(3);
    struct node *n2 = newNode(1);
    struct node *n3 = newNode(4);
    struct node *n4 = newNode(1);

    n1->next = n2;
    n2->next = n3;
    n3->next = n4;

    int length = listLength(n1);
    printf("List length: %d\n", length);

    free(n1);
    free(n2);
    free(n3);
    free(n4);
}

struct node *newNode(int val) {
    struct node *new = malloc(sizeof(*new));
    if (new == NULL) {
        fprintf(stderr, "could not allocate memory");
        exit(EXIT_FAILURE);
    }

    new->next = NULL;
    new->value = val;

    return new;
}

int listLength(struct node *l) {

    // Base case: - empty list
    if (l == NULL) {
        return 0;
    }

    // Recursive case - a node, and the rest of the list
    else {
        return 1 + listLength(l->next);
    }

}



/*
A factorial is the number that you get by multiplying
a number with all the natural numbers less than it

3! = 3 * 2 * 1

Iteratively: you need a variable to store the product
A condition, and a counter

Recursively: you call the same function repeatedly
with an argument that gets smaller, and stop at tthe base case

3! = 3 * 2!
3! = 3 * (2 * 1!)
3! = 3 * (2 * 1 * 0!)

BASE CASE:
0! = 1




LINKED LIST RECUSIVE DEFINITION:

A linked list is either:
    - an empty list (NULL)
    - some node, and the rest of the list
*/
