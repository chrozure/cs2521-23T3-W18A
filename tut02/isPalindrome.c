#include <stdio.h>
#include <stdbool.h>

bool isPalindrome(char *s);

int main(int argc, char *argv[]) {

    if (argc != 2) {
        printf("Usage: ./isPalindrome <string>\n");
        return 1;
    }

    if (isPalindrome(argv[1])) {
        printf("Is a palindrome\n");
    } else {
        printf("Is not a palindrome\n");
    }

}

bool isPalindrome(char *s) {

    return false;
}