#include <stdio.h>
#include <stdlib.h>

struct node {
	int value;
	struct node *next;
};

int listSum(struct node *n);
struct node *newNode(int val);

int main(void) {

    struct node *head = newNode(3);
    struct node *n2 = newNode(1);
    struct node *n3 = newNode(4);

    head->next = n2;
    n2->next = n3;

    int sum = listSum(head);
    printf("%d\n", sum);

    free(head);
    free(n2);
    free(n3);
}

struct node *newNode(int val) {
    struct node *n = malloc(sizeof(*n));

    n->value = val;
    n->next = NULL;

    return n;
}

int listSum(struct node *n) {

    return 0;
}