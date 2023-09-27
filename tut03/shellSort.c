#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

void shellSort(int a[], int lo, int hi);

int main(void) {

    // Feel free to play around with this shell sort implementation!
    int a[SIZE] = {42, 63, 94, -36, -93, -1, 92, 39, 62, -59};

    shellSort(a, 0, SIZE - 1);

    for (int i = 0; i < SIZE; i++) {
        printf("%d ", a[i]);
    }
    putchar('\n');
}


void shellSort(int a[], int lo, int hi)
{
	int h;
	for (h = 1; h <= (hi - lo) / 9; h = 3 * h + 1);

	for (; h > 0; h /= 3) {
		for (int i = lo + h; i <= hi; i++) {
			int val = a[i];
			int j = i;
			while (j >= lo + h && val < a[j - h]) {
				a[j] = a[j - h];
				j -= h;
			}
			a[j] = val;
		}
	}
}