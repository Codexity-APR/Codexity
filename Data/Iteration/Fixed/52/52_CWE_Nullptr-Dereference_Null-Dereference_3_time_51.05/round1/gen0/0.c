#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char* trim_whitespace(const char* input) {
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

    // Check if the input string is empty or contains only whitespace
    if (trimmed_length == 0) {
        return NULL;
    }

    // Allocate memory for the trimmed string
    char* trimmed_string = malloc((trimmed_length + 1) * sizeof(char));

    // Check if memory allocation was successful
    if (trimmed_string == NULL) {
        return NULL;
    }

    // Copy the trimmed string and add the null terminator
    strncpy(trimmed_string, start, trimmed_length);
    trimmed_string[trimmed_length] = '\0';

    return trimmed_string;
}

int main() {
    const char* input = "   Hello, World!   ";
    char* trimmed = trim_whitespace(input);

    if (trimmed == NULL) {
        printf("Error: Empty or whitespace-only string\n");
        return 1;
    }

    printf("Original string: '%s'\n", input);
    printf("Trimmed string: '%s'\n", trimmed);

    free(trimmed);
    return 0;
}