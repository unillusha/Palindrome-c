#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to check if the input string is a palindrome
int isPalindrome(const char *s) {
    int left = 0;
    int right = strlen(s) - 1;
    while (left < right) {
        if (s[left] != s[right]) {
            return 0;
        }
        left++;
        right--;
    }
    return 1;
}

// Function to sort a string in lexicographical order
void sortString(char *s) {
    int n = strlen(s);
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (s[i] > s[j]) {
                // Swap characters
                char temp = s[i];
                s[i] = s[j];
                s[j] = temp;
            }
        }
    }
}

int main() {
    char input[100];
    printf("Enter the string: ");
    scanf("%s", input);

    if (isPalindrome(input)) {
        sortString(input);
        printf("Sorted palindrome string: %s\n", input);
    } else {
        printf("The string is not a palindrome.\n");
    }

    return 0;
}
