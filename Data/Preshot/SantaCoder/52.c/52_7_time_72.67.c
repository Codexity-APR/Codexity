#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void trim_whitespace(const char* input, char* output) {
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

    // Copy the trimmed string and add the null terminator
    for (size_t i = 0; i < trimmed_length; i++) {
        output[i] = *start + i;
    }
    output[trimmed_length] = 0;
}

int main() {
    int nilai, NMK; 
    printf("Masukkan mata kuliah yang ingin dicari analisa nya:\n");
    scanf("%d", &NMK);
    printf("Masukkan nilai mata kuliahnya:\n");
    scanf("%d", &nilai);
    if (nilai <= 50) {
        printf("kamu harus belajar lagi karena nilai kamu kurang\n\n");
    }

    char input[] = "  Hello World  ";
    char output[strlen(input)];
    trim_whitespace(input, output);
    printf("%s\n", output);
    
    return 0;
}