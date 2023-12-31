List of vulnerabilities detected: 
 Error type: CWE-119 at line: 27. Error message: fscanf() without field width limits can crash with huge input data.


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
    // Read words from the file
    while (!feof(fp)) {
        char word[50];
        fscanf(fp, "%s", word);
        // Convert word to lowercase
        for (int i = 0; i < strlen(word); i++) {
            word[i] = tolower(word[i]);
        }
        // Check if the word already exists in the words array
        int exists = 0;
        for (int i = 0; i < distinctCount; i++) {
            if (strcmp(words[i], word) == 0) {
                exists = 1;
                count[i]++;
                if (count[i] > maxCount) {
                    maxCount = count[i];
                    strcpy(mostFreqWord, words[i]);
                }
                break;
            }
        }
        // Add the word to the words array if it doesn't exist
        if (!exists) {
            strcpy(words[distinctCount], word);
            count[distinctCount]++;
            distinctCount++;
            if (count[distinctCount - 1] > maxCount) {
                maxCount = count[distinctCount - 1];
                strcpy(mostFreqWord, words[distinctCount - 1]);
            }
        }
        wordCount++;
    }
    printf("Total number of words: %d\n", wordCount);
    printf("Total number of distinct words: %d\n", distinctCount);
    printf("Most frequently used word: %s\n", mostFreqWord);
    fclose(fp);
    return 0;
}