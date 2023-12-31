#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h> // to use the function tolower()

#define MAX_WORDS 2500 // define the maximum number of words

int main(int argc, char *argv[])
{
    int wordCount = 0;
    int distinctCount = 0;
    char words[MAX_WORDS][50]; // store the words
    int count[MAX_WORDS] = {0}; // store the count of each word
    int maxCount = 0; // store the max count
    char mostFreqWord[50] = ""; // store the most frequently used word
    char *p;
    FILE *fp;
    fp = fopen("COEN12_LAB1.txt", "r");
    if (fp == NULL) {
        printf("File Missing!\n");
        return 0;
    }
    while ((p = fgets(words[wordCount], sizeof(words[wordCount]), fp)) != NULL) {
        // Remove trailing newline character
        words[wordCount][strcspn(words[wordCount], "\n")] = '\0';
        
        // Convert word to lowercase
        for (int i = 0; i < strlen(words[wordCount]); i++) {
            words[wordCount][i] = tolower(words[wordCount][i]);
        }
        
        // Check if word is already counted
        int isDistinct = 1;
        for (int i = 0; i < wordCount; i++) {
            if (strcmp(words[i], words[wordCount]) == 0) {
                count[i]++;
                isDistinct = 0;
                break;
            }
        }
        
        // If word is distinct, increment distinct count
        if (isDistinct) {
            count[wordCount]++;
            distinctCount++;
        }
        
        // Update max count and most frequently used word
        if (count[wordCount] > maxCount) {
            maxCount = count[wordCount];
            strcpy(mostFreqWord, words[wordCount]);
        }
        
        wordCount++;
    }
    
    // Print results
    printf("Total words: %d\n", wordCount);
    printf("Distinct words: %d\n", distinctCount);
    printf("Most frequently used word: %s (%d occurrences)\n", mostFreqWord, maxCount);
    
    // Close the file
    fclose(fp);
    
    return 0;
}