#include <stdio.h>

int main(){
    char c, w[50], s[300];
    int i = 0, j = 0, k = 0;

    printf("Enter a sentence: ");

    // Read in a sentence from the user
    while ((c = getchar()) != '\n') {
        s[i++] = c;

        // If we encounter a space or a punctuation, we've found a new word
        if (c == ' ' || c == '.' || c == ',' || c == '!' || c == '?') {
            s[i-1] = '\0'; // Terminate the word with a null character
            printf("%s\n", s+j); // Print the word
            j = i; // Move the starting index of the next word to the end of the current word
        }
    }

    // Print the last word (if there was no punctuation at the end of the sentence)
    s[i] = '\0';
    printf("%s\n", s+j);

    return 0;
}