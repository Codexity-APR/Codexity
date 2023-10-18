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
    
    // Read words from file and count their occurrences
    while (fscanf(fp, "%s", words[wordCount]) != EOF) {
        // Convert word to lowercase
        for (p = words[wordCount]; *p; ++p) {
            *p = tolower(*p);
        }
        
        // Check if word already exists in the array
        int found = 0;
        for (int i = 0; i < wordCount; i++) {
            if (strcmp(words[i], words[wordCount]) == 0) {
                count[i]++;
                found = 1;
                break;
            }
        }
        
        // If word is not found, add it to the array
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