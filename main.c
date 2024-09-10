#include <stdio.h>
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
                char temp = s[i];
                s[i] = s[j];
                s[j] = temp;
            }
        }
    }
}

// Function to find the lexicographically smallest palindrome
char* findSmallestPalindrome(char *s) {
    if (!isPalindrome(s)) {
        return NULL;  // Return NULL if input is not a palindrome
    }

    sortString(s);

    int freq[256] = {0};  // ASCII table size for character frequencies
    int n = strlen(s);
    char firstHalf[100] = "", middle = '\0';
    int oddCount = 0;

    // Count character frequencies
    for (int i = 0; i < n; i++) {
        freq[(unsigned char)s[i]]++;
    }

    // Build the palindrome components
    int halfIndex = 0;
    for (int i = 0; i < 256; i++) {
        if (freq[i] % 2 != 0) {
            oddCount++;
            middle = (char)i;  // Set the middle character if frequency is odd
        }
        for (int j = 0; j < freq[i] / 2; j++) {
            firstHalf[halfIndex++] = (char)i;
        }
    }

    // If more than one character has an odd frequency, it's not possible to form a palindrome
    if (oddCount > 1) {
        return NULL;
    }

    firstHalf[halfIndex] = '\0';  // Null-terminate the first half

    // Form the full palindrome by mirroring the first half
    static char result[200];
    strcpy(result, firstHalf);
    if (middle != '\0') {
        strncat(result, &middle, 1);  // Add middle character if exists
    }
    strrev(firstHalf);  // Reverse the first half
    strcat(result, firstHalf);

    return result;
}

int main() {
    char input[100];
    while (1) {
        printf("Enter the string (or type 'exit' to quit): ");
        scanf("%s", input);

        // Exit condition
        if (strcmp(input, "exit") == 0) {
            break;
        }

        char *result = findSmallestPalindrome(input);

        if (result == NULL) {
            printf("No palindrome can be formed.\n");
        } else {
            printf("The lexicographically smallest palindrome is: %s\n", result);
        }
    }

    return 0;
}
