#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char* trim_whitespace(char* input) {
    if (input == NULL) {
        return NULL;
    }

    size_t len = strlen(input);
    if (len == 0) {
        return input;
    }

    // Find the first non-whitespace character
    char* start = input;
    while (isspace(*start)) {
        start++;
    }

    // Find the last non-whitespace character
    char* end = input + len - 1;
    while (isspace(*end) && end > start) {
        end--;
    }

    // Calculate the trimmed string length
    size_t trimmed_length = end - start + 1;

    // Allocate memory for the trimmed string
    char* trimmed_string = malloc((trimmed_length + 1) * sizeof(char));
    if (trimmed_string == NULL) {
        return NULL;
    }

    // Copy the trimmed string and add the null terminator
    strncpy(trimmed_string, start, trimmed_length);
    trimmed_string[trimmed_length] = '\0';

    return trimmed_string;
}

int main() {
    int nilai, NMK; 
    printf("Masukkan mata kuliah yang ingin dicari analisa nya:\n");
    scanf("%d", &NMK);
    printf("Masukkan nilai mata kuliahnya:\n");
    scanf("%d", &nilai);
    if (nilai <= 50) {
        printf("Kamu harus belajar lagi karena nilai kamu kurang.\n");
    }
    else {
        printf("Nilai kamu sudah cukup baik.\n");
    }

    return 0;
}