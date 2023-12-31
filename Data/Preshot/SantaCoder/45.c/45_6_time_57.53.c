#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 50

int main() {
    char word[MAX_LENGTH];
    char str[MAX_LENGTH];
    char c;
    size_t len_word;

    printf("Enter word to encrypt: ");
    scanf("%49[^\n]", word);
    len_word = strlen(word);

    if (len_word >= MAX_LENGTH) {
        fprintf(stderr, "Error: input too long.\n");
        return 1;
    }

    for (int i = 0; i < len_word; i++) {
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

    str[len_word] = '\0';
    printf("Encrypted message: %s\n", str);
    return 0;
}