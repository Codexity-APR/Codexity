#include <stdio.h>

int main(){
    char c, w[50], s[300];
    int i = 0, j = 0, k = 0;

    printf("Enter a sentence: ");
    
    // Read input string character by character
    while((c = getchar()) != '\n') {
        // Check if the character is a space or not
        if(c != ' ') {
            // If not a space, add the character to the current word
            w[i++] = c;
        } else {
            // If a space, terminate the current word with a null character
            w[i] = '\0';
            // Copy the current word to the sentence and add a space
            strcpy(&s[j], w);
            j += i + 1;
            // Reset the counter for the current word
            i = 0;
            // Increment the counter for the number of words
            k++;
        }
    }
    
    // Terminate the last word with a null character
    w[i] = '\0';
    // Add the last word to the sentence
    strcpy(&s[j], w);
    // Increment the counter for the number of words
    k++;

    printf("\nInput sentence contains %d words:\n", k);
    printf("%s", s);
    
    return 0;
}