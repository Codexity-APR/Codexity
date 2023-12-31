#include <stdio.h>
#include <string.h>

#define MAX_LEN 50

int main() {
    char word[MAX_LEN];
    char str[MAX_LEN] = {0}; // Initialize str to 0
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

    printf("Encrypted word: %s\n", str);
    return 0;
}