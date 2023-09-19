#include <stdio.h>
#include <stdlib.h>

struct node {
	int value;
	struct node *next;
};

struct node *newNode(int val);
int listCountOdds(struct node *l);

int main(void) {

    struct node *n1 = newNode(3);
    struct node *n2 = newNode(1);
    struct node *n3 = newNode(4);
    struct node *n4 = newNode(1);

    n1->next = n2;
    n2->next = n3;
    n3->next = n4;

    int length = listCountOdds(n1);
    printf("Number of odds: %d\n", length);

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

int listCountOdds(struct node *l) {

    return 0;
}
