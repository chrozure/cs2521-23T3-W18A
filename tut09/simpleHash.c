#include <stdio.h>

int hash(char *key, int N);

int main(void) {

    int size = 10;
    // printf("hash(\"hi\") = %d\n", hash("hi", size));
    printf("hash(\"cat\") = %d\n", hash("cat", size));
    printf("hash(\"act\") = %d\n", hash("act", size));
    printf("hash(\"tac\") = %d\n", hash("tac", size));
    // printf("hash(\"hello\") = %d\n", hash("hello", size));
    // printf("hash(\"zID\") = %d\n", hash("zID", size));

    return 0;
}

int hash(char *key, int N) {
	int h = 0;
    int i = 0;
	char *c;
	for (c = key; *c != '\0'; c++, i++) {
		h = h + (*c * i);
	}
	return h % N;
}


// person = {
//     "name": "Harry"
//     "year": 3
//     "degree": "Compsci/Math"
// }


// marks = {
//     "z23456": 35,
//     "z1239487" : 87,
//     "z1287468": 12
// }

