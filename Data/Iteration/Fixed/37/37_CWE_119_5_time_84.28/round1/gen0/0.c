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
    // Read each word from the file
    while (fscanf(fp, "%49s", words[wordCount]) != EOF) // Limit the field width to 49 characters
    {
        // Convert each word to lowercase
        for (p = words[wordCount]; *p != '\0'; p++)
        {
            *p = tolower(*p);
        }
        // Check if the word already exists in the array
        int found = 0;
        for (int i = 0; i < wordCount; i++)
        {
            if (strcmp(words[wordCount], words[i]) == 0)
            {
                count[i]++;
                found = 1;
                break;
            }
        }
        // If the word doesn't exist, add it to the array
        if (!found)
        {
            count[wordCount]++;
            distinctCount++;
            wordCount++;
        }
    }
    // Find the word with the maximum count
    for (int i = 0; i < wordCount; i++)
    {
        if (count[i] > maxCount)
        {
            maxCount = count[i];
            strcpy(mostFreqWord, words[i]);
        }
    }
    printf("Total words: %d\n", wordCount);
    printf("Distinct words: %d\n", distinctCount);
    printf("Most frequently used word: %s\n", mostFreqWord);
    fclose(fp);
    return 0;
}