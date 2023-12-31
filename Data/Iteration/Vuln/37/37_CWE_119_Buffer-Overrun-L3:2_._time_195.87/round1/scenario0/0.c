List of vulnerabilities detected: 
Error: Buffer Overrun L3   Offset: [-1, +oo] Size: 2500.
 Example: 
  45.         }
  46.         // Update max count and most frequent word
  47.         if (count[wordCount-1] > maxCount) {
                  ^
  48.             maxCount = count[wordCount-1];
  49.             strcpy(mostFreqWord, words[wordCount-1]);

Error: Buffer Overrun L3   Offset: [-1, +oo] (⇐ [-1, +oo] + [0, +oo]) Size: 2500.
 Example: 
  47.         if (count[wordCount-1] > maxCount) {
  48.             maxCount = count[wordCount-1];
  49.             strcpy(mostFreqWord, words[wordCount-1]);
                  ^
  50.         }
  51.     }


#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h> // to use the function tolower()
#define MAX_WORDS 2500 // define the maximum number of words
#define MAX_WORD_LENGTH 50 // define the maximum length of a word
int main(int argc, char *argv[])
{
    int wordCount = 0;
    int distinctCount = 0;
    char words[MAX_WORDS][MAX_WORD_LENGTH]; // store the words
    int count[MAX_WORDS] = {0}; // store the count of each word
    int maxCount = 0; // store the max count
    char mostFreqWord[MAX_WORD_LENGTH] = ""; // store the most frequently used word
    char *p;
    FILE *fp;
    fp = fopen("COEN12_LAB1.txt", "r");
    if (fp == NULL) {
        printf("File Missing!\n");
        return 0;
    }
    // Read words from the file
    char word[MAX_WORD_LENGTH];
    while (fscanf(fp, "%49s", word) == 1) {
        // Convert word to lowercase
        for (int i = 0; i < strlen(word); i++) {
            word[i] = tolower(word[i]);
        }
        // Check if word is already stored
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
        // Update max count and most frequent word
        if (count[wordCount-1] > maxCount) {
            maxCount = count[wordCount-1];
            strcpy(mostFreqWord, words[wordCount-1]);
        }
    }
    // Print the results
    printf("Number of words: %d\n", wordCount);
    printf("Number of distinct words: %d\n", distinctCount);
    printf("Most frequently used word: %s (%d times)\n", mostFreqWord, maxCount);
    // Close the file
    fclose(fp);
    return 0;
}