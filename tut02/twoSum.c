#include <stdio.h>
#include <stdbool.h>

bool hasTwoSum(int a[], int n, int v);

int main(void) {
    int a[6] = {3, 1, 4, 1, 5, 9};

    if (hasTwoSum(a, 6, 7)) {
        printf("Array has a two sum\n");
    } else {
        printf("Array does not have a two sum\n");
    }
}

bool hasTwoSum (int a[], int n, int v) {


    return false;
}