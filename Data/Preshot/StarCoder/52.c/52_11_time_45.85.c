#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char* trim_whitespace(const char* input) {
    if (input == NULL) {
        return NULL;
    }

    const char* start = input;
    const char* end = input + strlen(input) - 1;

    // Find the first non-whitespace character
    while (isspace(*start)) {
        start++;
    }

    // Find the last non-whitespace character
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
    if (scanf("%d", &NMK) != 1) {
        printf("Invalid input. Exiting program.\n");
        return 1;
    }
    printf("Masukkan nilai mata kuliahnya:\n");
    if (scanf("%d", &nilai) != 1) {
        printf("Invalid input. Exiting program.\n");
        return 1;
    }
    if (nilai <= 50) {
        printf("kamu harus belajar lagi karena nilai kamu kurang\n\n");
    }

    return 0;
}