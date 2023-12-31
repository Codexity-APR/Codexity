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
    FILE *fp;
    fp = fopen("COEN12_LAB1.txt", "r");
    if (fp == NULL) {
        printf("File Missing!\n");
        return 1;
    }
    
    // Read file contents
    char buffer[1000];
    while (fgets(buffer, 1000, fp)) {
        // Split line into words
        p = strtok(buffer, " ,.?!\n");
        while (p != NULL) {
            // Convert word to lowercase
            for (int i = 0; i < strlen(p); i++) {
                p[i] = tolower(p[i]);
            }
            // Check if word already exists
            int index = -1;
            for (int i = 0; i < wordCount; i++) {
                if (strcmp(words[i], p) == 0) {
                    index = i;
                    break;
                }
            }
            if (index >= 0) {
                // Increment count
                count[index]++;
            }
            else {
                // Add new word
                strcpy(words[wordCount], p);
                count[wordCount]++;
                wordCount++;
            }
            p = strtok(NULL, " ,.?!\n");
        }
    }
    
    fclose(fp);
    
    // Find most frequent word
    for (int i = 0; i < wordCount; i++) {
        if (count[i] > maxCount) {
            maxCount = count[i];
            strcpy(mostFreqWord, words[i]);
        }
    }
    
    // Print results
    printf("Total Words: %d\n", wordCount);
    printf("Distinct Words: %d\n", distinctCount);
    printf("Most Frequent Word: %s\n", mostFreqWord);
    
    return 0;
}