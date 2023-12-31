#include <stdio.h>
#include <string.h>

int main() {
    char word[50];
    char str[50] = {0}; // Initialize str array to avoid CWE-457
    char c;

    printf("Enter word to encrypt: ");
    scanf(" %49[^\n]", word);

    for (int i = 0; i < strlen(word); i++) {
        c = word[i];
        if (c == ' ') {
            str[i] = c;
            continue;
        }
        if (c == '!') {
            str[i] = '\0';
            break;
        }
        str[i] = c + 1;
    }

    printf("Encrypted word: %s\n", str); // Use printf to print str

    return 0;
}