#include <stdio.h>
#include <stdlib.h>

#include "bst.h"

int bstCountOdds(struct node *t);
int bstCountInternal(struct node *t);
int bstNodeLevel(struct node *t, int key);
int bstCountGreater(struct node *t, int val);

int main(void) {
    struct node *root = bstNew();

    root = bstInsert(root, 5);
    root = bstInsert(root, 2);
    root = bstInsert(root, 3);
    root = bstInsert(root, 4);
    root = bstInsert(root, 6);
    root = bstInsert(root, 1);
    root = bstInsert(root, 7);

    /*
    The tree looks like
            5
           / \
          2   6
         / \   \
        1   3   7
             \
              4
    */

    printf("The tree has %d odd values\n", bstCountOdds(root));
    // printf("The tree has %d internal nodes\n", bstCountInternal(root));
    // int target = 4;
    // printf("The node level of %d is %d\n", target, bstNodeLevel(root, target));
    // printf("The number of nodes greater than %d is %d\n", target, bstCountGreater(root, 4));


    bstFree(root);
}


int bstCountOdds(struct node *t) {
    return 0;
}

int bstCountInternal(struct node *t) {
    return 0;
}

int bstNodeLevel(struct node *t, int key) {
    return 0;
}

int bstCountGreater(struct node *t, int val) {
    return 0;
}
