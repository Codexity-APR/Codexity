#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_INPUT_LENGTH 50

void LetterCapitalize(char str[]) {
    int i;
    char res[MAX_INPUT_LENGTH];

    res[0] = toupper(str[0]);
    for(i = 1; i < strlen(str); i++) {
        if(str[i-1] == ' ') {
            res[i] = toupper(str[i]);
        } else {
            res[i] = str[i];
        }
    }

    printf("%s\n", res);
}

int main() {
    char str[MAX_INPUT_LENGTH];
    printf("Enter a string (max length %d): ", MAX_INPUT_LENGTH-1);
    if (fgets(str, sizeof(str), stdin)) {
        str[strcspn(str, "\n")] = 0; // remove trailing newline
        LetterCapitalize(str);
    }
    return 0;
}