#include <stdio.h>
#include <string.h>

#define MAX_LEN 50

int main() {
    char word[MAX_LEN];
    char str[MAX_LEN];
    char c;
    int i;

    printf("Enter word to encrypt: ");
    scanf(" %49[^\n]", word);

    for (i = 0; i < strlen(word) && i < MAX_LEN; i++) {
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
    
    str[i] = '\0'; // Null-terminate the string to avoid errors
    
    printf("%s\n", str);
    return 0;
}