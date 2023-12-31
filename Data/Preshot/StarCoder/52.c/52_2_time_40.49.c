#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char* trim_whitespace(const char* input) {
    if(input == NULL) {
        return NULL; // Return NULL if input is NULL
    }

    const char* start = input;
    const char* end = input + strlen(input) - 1;

    // Find the first non-whitespace character
    while (isspace(*start) && *start != '\0') {
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
        return NULL; // Return NULL if memory allocation fails
    }

    // Copy the trimmed string and add the null terminator
    strncpy(trimmed_string, start, trimmed_length);
    trimmed_string[trimmed_length] = '\0';

    return trimmed_string;
}

int main(int argc, char* argv[]) {
    char* input = "  hello  ";
    char* trimmed = trim_whitespace(input);
    if (trimmed == NULL) {
        printf("Error: Memory allocation failed.\n");
        return 1; // Return error code if memory allocation fails
    }
    printf("%s\n", trimmed);
    free(trimmed);
    return 0;
}