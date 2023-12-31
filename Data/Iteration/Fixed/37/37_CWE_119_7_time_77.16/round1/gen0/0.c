#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h> // to use the function tolower()
#define MAX_WORDS 2500 // define the maximum number of words
#define MAX_WORD_LENGTH 50 // define the maximum length of a word

int main(int argc, char *argv[])
{
    int wordCount = 0;
    int distinctCount = 0;
    char words[MAX_WORDS][MAX_WORD_LENGTH]; // store the words
    int count[MAX_WORDS] = {0}; // store the count of each word
    int maxCount = 0; // store the max count
    char mostFreqWord[MAX_WORD_LENGTH] = ""; // store the most frequently used word
    char *p;
    FILE *fp;
    fp = fopen("COEN12_LAB1.txt", "r");
    if (fp == NULL) {
        printf("File Missing!\n");
        return 0;
    }
    while (fscanf(fp, "%49s", words[wordCount]) != EOF) { // Limit the field width to 49 characters
        // Convert word to lowercase
        p = words[wordCount];
        while (*p) {
            *p = tolower(*p);
            p++;
        }
        // Check if word already exists in the list
        int found = 0;
        for (int i = 0; i < wordCount; i++) {
            if (strcmp(words[wordCount], words[i]) == 0) {
                count[i]++;
                found = 1;
                break;
            }
        }
        // If word doesn't exist, add it to the list
        if (!found) {
            count[wordCount]++;
            distinctCount++;
            wordCount++;
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
    printf("Most frequently used word: %s\n", mostFreqWord);
    fclose(fp);
    return 0;
}