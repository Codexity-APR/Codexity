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
    // Read words from the file and store them in the words array
    char word[MAX_WORD_LENGTH];
    while (fscanf(fp, "%49s", word) != EOF) { // Limit the field width to 49 characters
        // Convert the word to lowercase
        for (int i = 0; word[i]; i++) {
            word[i] = tolower(word[i]);
        }
        // Check if the word already exists in the array
        int found = 0;
        for (int i = 0; i < wordCount; i++) {
            if (strcmp(words[i], word) == 0) {
                found = 1;
                count[i]++;
                if (count[i] > maxCount) {
                    maxCount = count[i];
                    strcpy(mostFreqWord, words[i]);
                }
                break;
            }
        }
        // If the word is not found, add it to the array
        if (!found) {
            strcpy(words[wordCount], word);
            count[wordCount]++;
            distinctCount++;
            if (count[wordCount] > maxCount) {
                maxCount = count[wordCount];
                strcpy(mostFreqWord, words[wordCount]);
            }
            wordCount++;
        }
    }
    // Print the results
    printf("Total words: %d\n", wordCount);
    printf("Distinct words: %d\n", distinctCount);
    printf("Most frequent word: %s\n", mostFreqWord);
    printf("Count: %d\n", maxCount);
    // Close the file
    fclose(fp);
    return 0;
}