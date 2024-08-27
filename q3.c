// Javokhir Ganiboev
// Question3: Longest Substring without Repeating Characters

#include <stdio.h>
#include <string.h>

int lengthOfLongestSubstring(char* s) {
    int lastIndex[257]; // Array to store the last index of each character (ASCII characters + extended ASCII)
    
    // Initialize the array with -1, meaning that initially, no character has been encountered
    memset(lastIndex, -1, sizeof(lastIndex));
    
    int start = 0; // Start index of the current window for checking substrings
    int maxLength = 0; // Maximum length of a substring without repeating characters
    
    // Loop through the string character by character
    for (int end = 0; s[end] != '\0'; end++) {
        char currentChar = s[end]; // The current character in the string
        
        // If the character has been seen before and is within the current window
        if (lastIndex[currentChar] >= start) {
            // Move the start index to one position right of the last occurrence of currentChar
            start = lastIndex[currentChar] + 1;
        }
        
        // Update the last seen index of the current character to the current position
        lastIndex[currentChar] = end;
        
        // Calculate the length of the current substring without repeating characters
        int currentLength = end - start + 1;
        
        // If the current length is greater than the maximum length found so far, update maxLength
        if (currentLength > maxLength) {
            maxLength = currentLength;
        }
    }
    
    // Return the length of the longest substring found
    return maxLength;
}

int main() {
    char* s1 = "abcabcbb";
    char* s2 = "bbbbb";
    char* s3 = "pwwkew";

    printf("Length of longest substring without repeating characters in '%s': %d\n", s1, lengthOfLongestSubstring(s1));
    printf("Length of longest substring without repeating characters in '%s': %d\n", s2, lengthOfLongestSubstring(s2));
    printf("Length of longest substring without repeating characters in '%s': %d\n", s3, lengthOfLongestSubstring(s3));

    return 0;
}
