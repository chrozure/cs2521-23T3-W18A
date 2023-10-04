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
    printf("The tree has %d internal nodes\n", bstCountInternal(root));
    int target = 4;
    printf("The node level of %d is %d\n", target, bstNodeLevel(root, target));
    printf("The number of nodes greater than %d is %d\n", target, bstCountGreater(root, 4));


    bstFree(root);
}

/*
Youi can view a binary search tree as:
    - an empty tree OR
    - a node, with a left subtree and a right subtree
*/


int bstCountOdds(struct node *t) {

    // Base case: empty tree
    if (t == NULL) {
        return 0;
    } else if (t->value % 2 == 1) {
        return 1 + bstCountOdds(t->left) + bstCountOdds(t->right);
    } else {
        return bstCountOdds(t->left) + bstCountOdds(t->right);
    }

    return 0;
}

int bstCountInternal(struct node *t) {

    // Base case: empty tree
    if (t == NULL) {
        return 0;
    }

    // Base case 2: tree has a single node
    else if (t->left == NULL && t->right == NULL) {
        return 0;
    }

    // Recursive case:
    else {
        return 1 + bstCountInternal(t->left) + bstCountInternal(t->right);
    }

    return 0;
}

int bstNodeLevel(struct node *t, int key) {
    // Base case: empty tree, so key is definitely not in this tree
    if (t == NULL) {
        return -1;
    }

    // Base case: the root node has value equal to the key
    else if (t->value == key) {
        return 0;
    }

    // Recursive case: the key could be in a subtree
    int l = bstNodeLevel(t->left, key);
    int r = bstNodeLevel(t->right, key);
    if (l == -1 && r == -1) {
        // Not in either subtree
        return -1;
    } else if (l != -1) {
        return 1 + l;
    } else {
        return 1 + r;
    }

}

int bstCountGreater(struct node *t, int val) {
    // Base case: empty tree
    if (t == NULL) {
        return 0;
    }

    // Recursive case: if the root is greater than the value,
    // check both subtrees as they could both contain
    // values greater than val
    else if (t->value > val) {
        return 1 + bstCountGreater(t->left, val) + bstCountGreater(t->right, val);
    }

    // Recursive case: the root is smaller than the value,
    // there still could be viable nodes in the right subtree
    else {
        return bstCountGreater(t->right, val);
    }
}
