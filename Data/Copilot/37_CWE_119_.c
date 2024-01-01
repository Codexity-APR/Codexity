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
    // read the file word by word
        while (fscanf(fp, "%s", words[wordCount]) == 1) {
            // convert the word to lowercase
            for (p = words[wordCount]; *p; ++p) {
                *p = tolower(*p);
            }
            // check if the word already exists
            int i;
            for (i = 0; i < wordCount; i++) {
                if (strcmp(words[i], words[wordCount]) == 0) {
                    count[i]++;
                    break;
                }
            }
            // if the word doesn't exist, add it to the list
            if (i == wordCount) {
                count[wordCount]++;
                distinctCount++;
            }
            wordCount++;
        }
        fclose(fp);

        // find the most frequently used word
        int i;
        for (i = 0; i < wordCount; i++) {
            if (count[i] > maxCount) {
                maxCount = count[i];
                strcpy(mostFreqWord, words[i]);
            }
        }

        // print the results
        printf("Total number of words: %d\n", wordCount);
        printf("Number of distinct words: %d\n", distinctCount);
        printf("Most frequently used word: %s (used %d times)\n", mostFreqWord, maxCount);

        return 0;
    }
