#include <stdio.h>

int main(){
    char c, w[50], s[300];
    int i = 0, j = 0;

    printf("Enter a sentence: ");

    // Read in the sentence character by character
    while ((c = getchar()) != '\n' && i < 299) {
        s[i++] = c;

        // If the character is a space or the end of the sentence, 
        // we've finished reading in a word
        if (c == ' ' || c == '\n') {
            // Terminate the string with a null character
            w[j] = '\0';

            // Print the word
            printf("%s\n", w);

            // Reset the word buffer and increment counter
            j = 0;
        } else {
            // Add the character to the current word
            w[j++] = c;
        }
    }

    // Terminate the string with a null character
    s[i] = '\0';

    // Print the entire sentence
    printf("%s\n", s);

    return 0;
}