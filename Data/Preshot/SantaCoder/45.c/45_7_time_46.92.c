#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 50

int main() {
    char word[MAX_LENGTH];
    char str[MAX_LENGTH] = {0};
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

    printf("%s\n", str);

    return 0;
}