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
    
    // Read the words from the file and update the word count
    while ((p = fscanf(fp, "%s", words[wordCount])) != NULL) {
        wordCount++;
    }
    
    // Convert all words to lowercase for case-insensitive comparison
    for (int i = 0; i < wordCount; i++) {
        for (int j = 0; j < strlen(words[i]); j++) {
            words[i][j] = tolower(words[i][j]);
        }
    }
    
    // Count the frequency of each word
    for (int i = 0; i < wordCount; i++) {
        int isNew = 1;
        for (int j = 0; j < distinctCount; j++) {
            if (strcmp(words[i], words[j]) == 0) {
                count[j]++;
                isNew = 0;
                break;
            }
        }
        if (isNew) {
            strcpy(words[distinctCount], words[i]);
            count[distinctCount]++;
            distinctCount++;
        }
    }
    
    // Find the most frequently used word
    for (int i = 0; i < distinctCount; i++) {
        if (count[i] > maxCount) {
            maxCount = count[i];
            strcpy(mostFreqWord, words[i]);
        }
    }
    
    // Print the results
    printf("Total words: %d\n", wordCount);
    printf("Distinct words: %d\n", distinctCount);
    printf("Most frequently used word: %s (appeared %d times)\n", mostFreqWord, maxCount);
    
    fclose(fp);
    
    return 0;
}