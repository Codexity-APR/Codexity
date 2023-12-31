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

    // Read words from the file and count their occurrence
    while (fscanf(fp, "%s", words[wordCount]) == 1) {
        // Convert the word to lowercase
        for (p = words[wordCount]; *p; ++p) {
            *p = tolower(*p);
        }
        wordCount++;
    }

    // Count the occurrence of each word
    for (int i = 0; i < wordCount; i++) {
        count[i] = 1; // Set initial count to 1

        // Check if the word is already counted
        for (int j = i + 1; j < wordCount; j++) {
            if (strcmp(words[i], words[j]) == 0) {
                count[i]++;
            }
        }

        // Update the maximum count and most frequent word
        if (count[i] > maxCount) {
            maxCount = count[i];
            strcpy(mostFreqWord, words[i]);
        }
    }

    // Count the number of distinct words
    for (int i = 0; i < wordCount; i++) {
        if (count[i] == 1) {
            distinctCount++;
        }
    }

    printf("Total words: %d\n", wordCount);
    printf("Distinct words: %d\n", distinctCount);
    printf("Most frequent word: %s (%d occurrences)\n", mostFreqWord, maxCount);

    fclose(fp);
    return 0;
}