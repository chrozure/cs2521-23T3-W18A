#include <stdio.h>
#include <stdlib.h>

struct node {
	int value;
	struct node *next;
};

struct node *newNode(int val);
void printList(struct node *l);
struct node *listDelete(struct node *l, int value);

int main(void) {

    struct node *n1 = newNode(3);
    struct node *n2 = newNode(1);
    struct node *n3 = newNode(4);
    struct node *n4 = newNode(1);

    n1->next = n2;
    n2->next = n3;
    n3->next = n4;

    printf("List: ");
    printList(n1);

    n1 = listDelete(n1, 1);

    printf("\nList: ");
    printList(n1);

    free(n1);
    // free(n2); Should be freed already from listDelete
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

// A helper function to print a list... done recursively!
void printList(struct node *l) {
    if (l == NULL) return;
    printf("%d ", l->value);
    printList(l->next);
}

struct node *listDelete(struct node *l, int value) {

    // Base case 1 - empty list
    if (l == NULL) {
        return l;
    }

    // Base case 2 - value matches first node in the list
    if (l->value == value) {
        struct node *tmp = l->next;
        free(l);
        return tmp;
    }


    /*
    Stuff we discussed in the tutorial about checking the next node's value
    This was a good idea, but it turns out we don't actually need it.

    This is because base case 2 will cover it once it reaches the node we are interested in
    Feel free to uncomment this section and play around with this implementation.

    // Base case 3 - only one non-matching node in the list
    if (l->next == NULL) {
        return l;
    }

    // Base case 4 - next node is matching
    if (l->next->value == value) {
        struct node *tmp = l->next;
        l->next = l->next->next;
        free(tmp);
        return l;
    }
    */

    // Recursive case
    else {
        /*
        This might be a bit tricky to wrap your head around.

        Essentially, the listDelete function is supposed to return the head of the list
        So, we can't do something like "return listDelete(l->next, value);" because
        that would just return the end of the list

        Instead, we say that the node after the head of the list
        should be the head of the rest of the list,
        and then return the actual head.
        */
        l->next = listDelete(l->next, value);
        return l;
    }

}
