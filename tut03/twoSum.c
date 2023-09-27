#include <stdio.h>
#include <stdbool.h>

#define SIZE 10

bool hasTwoSum(int a[], int n, int v);

int main(void) {
    int a[SIZE] = {21, 35, 47, -18, -46, -4, 42, 19, 31, -30};

    int target = 50;
    if (hasTwoSum(a, SIZE, target)) {
        printf("Array has a two sum that equals %d\n", target);
    } else {
        printf("Array does not have a two sum that equals %d\n", target);
    }
}

bool hasTwoSum (int a[], int n, int v) {

    // BRUTE FORCE METHOD
    // Iterate through the array and check all possible pairs of numbers
    // With every pair, check if their sum is equal to the target value
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            // Check if the two numbers add to the targer
            if (a[i] + a[j] == v) {
                printf("a[i]: %d, a[j]: %d\n", a[i], a[j]);
                return true;
            }
        }
    }


    // OPTIMISED SOLUTION
    // First sorts the array in ascending order, and then
    // uses a "two pointer" method where you iterate from the
    // start and the end and adjust depending on if the sum
    // is greater than or less than the target value.
    /*
    mergeSort(a, 0, n - 1);
    int i = 0;
    int j = n - 1;
    while (i <= j) {
        if (a[i] + a[j] < v) {
            i++;
        } else if (a[i] + a[j] > v) {
            j--;
        } else {
            return true;
        }
    }
    */

    return false;
}

/*
Time complexity analysis

BRUTE FORCE METHOD
number of pairs
= (n-1) + (n-2) + ... + 2 + 1
= n(n - 1)/2
= (n^2 - n)/2
= 1/2*n^2 - 1/2*n
= O(n^2).


OPTIMISED SOLUTION
Merge sort: O(n log n)
Single loop: O(n)

Hence, overall worst case time complexity is O(n log n).


CHALLENGE:
It is actually possible to complete the two sum problem
in O(n)! Can you figure out the algorithm?
*/



/*
BIG-O

Describes how efficient an algorithm is as the input size becomes very large

3*n^2 + 4*n + 5*logn + 3

To find big-O:
    - disregard all coefficients
    - remove all lower order terms

n^2 + n + logn + 1
O(n^2)

*/