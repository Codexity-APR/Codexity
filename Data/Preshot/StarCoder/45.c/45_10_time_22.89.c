#include <stdio.h>
#include <string.h>

int main() {
    char word[50];
    char str[50] = {0}; // Initialize str with null characters
    char c;

    printf("Enter word to encrypt: ");
    scanf("%49[^\n]", word); // Remove the space before % to avoid buffer overflow

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

    printf("Encrypted word: %s\n", str);
    memset(word, 0, sizeof(word)); // Clear the word array
    memset(str, 0, sizeof(str)); // Clear the str array
    return 0;
}