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
    
    while (!feof(fp)) {
        char word[50];
        fscanf(fp, "%s", word);
        
        // Convert word to lowercase
        for (int i = 0; word[i]; i++) {
            word[i] = tolower(word[i]);
        }
        
        // Check if word is already in the list
        int found = 0;
        for (int i = 0; i < wordCount; i++) {
            if (strcmp(words[i], word) == 0) {
                count[i]++;
                found = 1;
                break;
            }
        }
        
        // If word is not found, add it to the list
        if (!found) {
            strcpy(words[wordCount], word);
            count[wordCount]++;
            wordCount++;
            distinctCount++;
        }
    }
    
    // Find the most frequently used word
    for (int i = 0; i < wordCount; i++) {
        if (count[i] > maxCount) {
            maxCount = count[i];
            strcpy(mostFreqWord, words[i]);
        }
    }
    
    printf("Total number of words: %d\n", wordCount);
    printf("Number of distinct words: %d\n", distinctCount);
    printf("Most frequently used word: %s\n", mostFreqWord);
    
    fclose(fp);
    
    return 0;
}