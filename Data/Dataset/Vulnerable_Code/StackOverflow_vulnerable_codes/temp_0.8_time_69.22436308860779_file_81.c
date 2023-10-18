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

    // Read words from file and store them in the 'words' array
    while (fscanf(fp, "%s", words[wordCount]) == 1) {
        // Convert word to lowercase for case-insensitive comparison
        for (p = words[wordCount]; *p != '\0'; p++) {
            *p = tolower(*p);
        }
        wordCount++;
    }

    fclose(fp);

    // Process the words and find the frequency of each word
    for (int i = 0; i < wordCount; i++) {
        int found = 0;
        for (int j = 0; j < distinctCount; j++) {
            if (strcmp(words[i], words[j]) == 0) {
                count[j]++;
                found = 1;
                break;
            }
        }
        if (!found) {
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
    printf("Most frequently used word: %s (used %d times)\n", mostFreqWord, maxCount);

    return 0;
}