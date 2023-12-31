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
    
    if (argc != 2) {
        printf("Usage: %s filename\n", argv[0]);
        return 1;
    }
    
    fp = fopen(argv[1], "r");
    if (fp == NULL) {
        printf("Error: File not found or cannot be opened!\n");
        return 1;
    }
    
    // rest of the code goes here
    
    fclose(fp);
    return 0;
}