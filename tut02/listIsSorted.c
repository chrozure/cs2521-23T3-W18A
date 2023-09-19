#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node {
	int value;
	struct node *next;
};

struct node *newNode(int val);
bool listIsSorted(struct node *l);

int main(void) {

    struct node *n1 = newNode(3);
    struct node *n2 = newNode(1);
    struct node *n3 = newNode(4);
    struct node *n4 = newNode(1);

    n1->next = n2;
    n2->next = n3;
    n3->next = n4;

    if (listIsSorted(n1)) {
        printf("List is sorted\n");
    } else {
        printf("List is NOT sorted\n");
    }

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

bool listIsSorted(struct node *l) {

    return true;
}