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
    
    // Read words from the file and store them in the words array
    while (fscanf(fp, "%s", words[wordCount]) != EOF) {
        // Convert the word to lowercase
        for (int i = 0; words[wordCount][i]; i++) {
            words[wordCount][i] = tolower(words[wordCount][i]);
        }
        wordCount++;
    }
    
    // Count the frequency of each word
    for (int i = 0; i < wordCount; i++) {
        // Check if the word has already been counted
        int isDistinct = 1;
        for (int j = 0; j < i; j++) {
            if (strcmp(words[i], words[j]) == 0) {
                isDistinct = 0;
                break;
            }
        }
        
        if (isDistinct) {
            // Increment the count of the distinct word
            distinctCount++;
            count[i]++;
            
            // Check if the count is the new max count
            if (count[i] > maxCount) {
                maxCount = count[i];
                strcpy(mostFreqWord, words[i]);
            }
        } else {
            // Increment the count of the non-distinct word
            count[j]++;
            
            // Check if the count is the new max count
            if (count[j] > maxCount) {
                maxCount = count[j];
                strcpy(mostFreqWord, words[j]);
            }
        }
    }
    
    // Print the results
    printf("Total Words: %d\n", wordCount);
    printf("Distinct Words: %d\n", distinctCount);
    printf("Most Frequent Word: %s (%d times)\n", mostFreqWord, maxCount);
    
    fclose(fp);
    
    return 0;
}