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

    struct node *n1 = newNode(1);
    struct node *n2 = newNode(3);
    struct node *n3 = newNode(4);
    struct node *n4 = newNode(5);

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

    // Base case 1 - list is empty
    if (l == NULL) {
        return true;
    }

    // Base case 2 - only one node in list
    if (l->next == NULL) {
        return true;
    }

    // Base case 3 - if the next node has a smaller value
    if (l->next->value < l->value) {
        return false;
    }

    // Recursive case
    else {
        return listIsSorted(l->next);
    }

}



