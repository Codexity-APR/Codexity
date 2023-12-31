#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_WORDS 2500

int main(int argc, char *argv[])
{
    int wordCount = 0;
    int distinctCount = 0;
    char words[MAX_WORDS][50];
    int count[MAX_WORDS] = {0};
    int maxCount = 0;
    char mostFreqWord[50] = "";
    char *p;
    FILE *fp = NULL;
    int ret = 0;

    fp = fopen("COEN12_LAB1.txt", "r");
    if (fp == NULL) {
        printf("File Missing!\n");
        return 0;
    }

    while (wordCount < MAX_WORDS && (ret = fscanf(fp, "%49s", words[wordCount])) == 1) {
        wordCount++;
    }

    if (ret == 0 && !feof(fp)) {
        fprintf(stderr, "Error occurred while reading the file!\n");
        return -1;
    }

    fclose(fp);

    for (int i = 0; i < wordCount; i++) {
        count[i] = 1;
        for (int j = i+1; j < wordCount; j++) {
            if (strcmp(words[i], words[j]) == 0) {
                count[i]++;
                count[j] = -1;
            }
        }
        if (count[i] > 0) {
            distinctCount++;
        }
    }

    for (int i = 0; i < wordCount; i++) {
        if (count[i] > maxCount) {
            maxCount = count[i];
            strcpy(mostFreqWord, words[i]);
        }
    }

    printf("The number of distinct words is %d\n", distinctCount);
    printf("The most frequently used word is %s\n", mostFreqWord);
    printf("The number of times the word %s is used is %d\n", mostFreqWord, maxCount);

    return 0;
}