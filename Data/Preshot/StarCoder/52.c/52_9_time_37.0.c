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

    while (isspace(*start)) {
        start++;
    }

    while (isspace(*end) && end > start) {
        end--;
    }

    size_t trimmed_length = end - start + 1;
    char* trimmed_string = malloc((trimmed_length + 1) * sizeof(char));

    if (trimmed_string == NULL) {
        return NULL;
    }

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
        printf("Kamu harus belajar lagi karena nilai kamu kurang\n\n");
    }

    return 0;
}