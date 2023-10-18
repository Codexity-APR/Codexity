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
    
    // Read words from file and count their occurrences
    char word[50];
    while (fscanf(fp, "%s", word) == 1) {
        // Convert word to lowercase
        for (p = word; *p != '\0'; p++) {
            *p = tolower(*p);
        }
        
        // Check if word is already in words array
        int i;
        for (i = 0; i < wordCount; i++) {
            if (strcmp(words[i], word) == 0) {
                count[i]++; // Increment count of existing word
                break;
            }
        }
        
        // If word is not already in words array, add it
        if (i == wordCount) {
            strcpy(words[i], word);
            count[i]++;
            wordCount++;
            distinctCount++;
        }
    }
    
    // Find the most frequently used word
    for (int i = 0; i < wordCount; i++) {
        if (count[i] > maxCount) {
            maxCount = count[i];
            strcpy(mostFreqWord, words[i]);
        }
    }
    
    // Print the results
    printf("Total words: %d\n", wordCount);
    printf("Distinct words: %d\n", distinctCount);
    printf("Most frequent word: %s (%d occurrences)\n", mostFreqWord, maxCount);
    
    // Close the file
    fclose(fp);
    
    return 0;
}