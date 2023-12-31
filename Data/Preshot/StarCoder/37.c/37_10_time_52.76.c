#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_WORDS 2500

int main(int argc, char *argv[]) {
    int wordCount = 0;
    int distinctCount = 0;
    char words[MAX_WORDS][50];
    int count[MAX_WORDS] = {0};
    int maxCount = 0;
    char mostFreqWord[50] = "";
    char *p;
    FILE *fp = NULL;

    fp = fopen("COEN12_LAB1.txt", "r");
    if (fp == NULL) {
        printf("File Missing!\n");
        return 0;
    }

    // read the words from the file, limiting the read to 49 characters to avoid buffer overflows
    while (fscanf(fp, "%49s", words[wordCount]) != EOF && wordCount < MAX_WORDS) {
        wordCount++;
    }
    fclose(fp);

    // count the number of distinct words
    for (int i = 0; i < wordCount; i++) {
        count[i] = 1;
        for (int j = i+1; j < wordCount; j++) {
            if (strcmp(words[i], words[j]) == 0) {
                count[i]++;
                count[j] = -1; // mark as a duplicate
            }
        }
        if (count[i] == 1) {
            distinctCount++;
        }
    }

    // find the most frequently used word
    for (int i = 0; i < wordCount; i++) {
        if (count[i] > maxCount && count[i] != -1) {
            maxCount = count[i];
            strcpy(mostFreqWord, words[i]);
        }
    }

    // convert most frequent word to lowercase
    p = mostFreqWord;
    while (*p) {
        *p = tolower(*p);
        p++;
    }

    // print the result
    printf("The number of distinct words is %d\n", distinctCount);
    printf("The most frequently used word is %s\n", mostFreqWord);
    printf("The number of times the word %s is used is %d\n", mostFreqWord, maxCount);

    return 0;
}