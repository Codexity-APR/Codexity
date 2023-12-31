#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char* trim_whitespace(const char* input) {
    if (input == NULL) {
        return NULL;
    }

    // Find the first non-whitespace character
    const char* start = input;
    while (isspace(*start)) {
        start++;
    }

    // Find the last non-whitespace character
    const char* end = input + strlen(input) - 1;
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
    for (size_t i = 0; i < trimmed_length; i++) {
        trimmed_string[i] = start[i];
    }
    trimmed_string[trimmed_length] = '\0';

    return trimmed_string;
}

int main() {
    char input[100];
    printf("Masukkan kata: ");
    scanf("%99[^\n]", input);

    char* trimmed_input = trim_whitespace(input);
    if (trimmed_input != NULL) {
        printf("Kata hasil trim: %s\n", trimmed_input);
        free(trimmed_input);
    } else {
        printf("Gagal melakukan trim kata.\n");
    }

    return 0;
}