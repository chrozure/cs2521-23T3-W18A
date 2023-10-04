// Implementation of the Set ADT

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

#include "Set.h"

typedef struct node *Node;
struct node {
    int value;
    Node next;
};

// Linked list implementation of the set
struct set {
    Node head;
};

Set SetNew(void) {
    Set new = malloc(sizeof(*new));
    if (new == NULL) {
        fprintf(stderr, "Could not allocate memory for new set\n");
        exit(EXIT_FAILURE);
    }
    new->head = NULL;
    return new;
}

void SetFree(Set s) {
    Node prev = NULL;
    Node curr = s->head;

    while (curr != NULL) {
        prev = curr;
        curr = curr->next;
        free(prev);
    }

    free(s);
}

void SetInsert(Set s, int elem) {
    // Check if an element is in the set
    Node curr = s->head;
    while (curr != NULL) {
        if (curr->value == elem) {
            return;
        }
        curr = curr->next;
    }

    // Insert the new node in the head
    Node new = malloc(sizeof(*new));
    if (new == NULL) {
        fprintf(stderr, "Could not allocate memory for new node\n");
        exit(EXIT_FAILURE);
    }
    new->value = elem;
    new->next = s->head;
    s->head = new;
}

void SetDelete(Set s, int elem) {

    Node curr = s->head;
    // Check if the head is the specified element
    if (curr->value == elem) {
        Node tmp = curr->next;
        free(curr);
        s->head = tmp;
        return;
    }

    Node prev = NULL;
    while (curr != NULL) {
        prev = curr;
        curr = curr->next;
        if (curr->value == elem) {
            prev->next = curr->next;
            free(curr);
            return;
        }
    }
}

bool SetContains(Set s, int elem) {
    Node curr = s->head;
    while (curr != NULL) {
        if (curr->value  == elem) {
            return true;
        }
        curr = curr->next;
    }

    return false;
}


int SetSize(Set s) {
    Node curr = s->head;
    int size = 0;

    while (curr != NULL) {
        size++;
        curr = curr->next;
    }

    return size;
}
