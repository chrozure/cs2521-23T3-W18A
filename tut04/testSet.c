#include <stdio.h>

#include "Set.h"

#define MAX_SIZE 32

int numOddOccurrences(int arr[], int size);
int numSingleOccurrences(int arr[], int size);

int main(void) {

    int a[MAX_SIZE] = {4, 3, 4, 8, 8, 4};
    // int b[MAX_SIZE] = {4, 3, 4, 8, 7, 4};

    printf("Number of integers that occur an odd number of times in a: %d\n", numOddOccurrences(a, 6));
    // printf("Number of integers that occur once in b: %d\n", numSingleOccurrences(b, 6));

}

int numOddOccurrences(int arr[], int size) {

    // Create an empty set
    // which stores the numbers that appear an odd number of times
    Set oddOccurrences = SetNew();

    // Loop through the given array
    for (int i = 0; i < size; i++) {

        // If the current number is not in the set,
        //      add it to the set
        if (!SetContains(oddOccurrences, arr[i])) {
            SetInsert(oddOccurrences, arr[i]);
        }
        // Otherwise, remove it from the set
        else {
            SetDelete(oddOccurrences, arr[i]);
        }

    }

    int num = SetSize(oddOccurrences);
    SetFree(oddOccurrences);
    // Return the size of the set at the end
    return num;
}

int numSingleOccurrences(int arr[], int size) {

	return 0;
}
