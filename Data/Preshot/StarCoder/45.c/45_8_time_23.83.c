#include <stdio.h>
#include <string.h>

#define MAX_LEN 50 // define the maximum length for word and str

int main() {
    char word[MAX_LEN];
    char str[MAX_LEN];
    char c;
    memset(str, 0, sizeof(str)); // initialize str variable with 0

    printf("Enter word to encrypt: ");
    scanf("%49[^\n]", word); // limit input to 49 characters to avoid buffer overflow

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