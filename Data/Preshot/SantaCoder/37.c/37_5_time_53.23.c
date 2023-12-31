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
    
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 0;
    }
    
    fp = fopen(argv[1], "r");
    if (fp == NULL) {
        printf("File %s Missing!\n", argv[1]);
        return 0;
    }
    
    // rest of the code goes here
    
    fclose(fp); // close the file when done
    return 0;
}