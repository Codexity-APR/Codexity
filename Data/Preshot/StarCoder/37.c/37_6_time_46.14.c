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
    FILE *fp = NULL;
    fp = fopen("COEN12_LAB1.txt", "r");
    if (fp == NULL) {
        printf("File Missing!\n");
        return 0;
    }

    // read the words from the file
    while (wordCount < MAX_WORDS && fscanf(fp, "%49s", words[wordCount]) == 1) {
        wordCount++;
    }
    fclose(fp);

    // count the number of distinct words
    for (int i = 0; i < wordCount; i++) {
        count[i] = 0;
        for (int j = 0; j < wordCount; j++) {
            if (strcmp(words[i], words[j]) == 0) {
                count[i]++;
            }
        }
        if (count[i] == 1) {
            distinctCount++;
        }
    }

    // find the most frequently used word
    for (int i = 0; i < wordCount; i++) {
        if (count[i] > maxCount) {
            maxCount = count[i];
            strcpy(mostFreqWord, words[i]);
        }
    }

    // print the result
    printf("The number of distinct words is %d\n", distinctCount);
    printf("The most frequently used word is %s\n", mostFreqWord);
    printf("The number of times the word %s is used is %d\n", mostFreqWord, maxCount);

    return 0;
}