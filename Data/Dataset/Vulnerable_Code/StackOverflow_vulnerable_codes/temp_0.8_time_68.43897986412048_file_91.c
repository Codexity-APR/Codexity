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
        p = words[wordCount];
        while (*p) {
            *p = tolower(*p);
            p++;
        }
        wordCount++;
    }

    fclose(fp);

    // Count the occurrences of each word
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

    // Find the word with the maximum count
    for (int i = 0; i < distinctCount; i++) {
        if (count[i] > maxCount) {
            maxCount = count[i];
            strcpy(mostFreqWord, words[i]);
        }
    }

    // Print the results
    printf("Word Count: %d\n", wordCount);
    printf("Distinct Words: %d\n", distinctCount);
    printf("Most Frequently Used Word: %s\n", mostFreqWord);

    return 0;
}