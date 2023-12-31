#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 50

void LetterCapitalize(char str[]) {
    int i;
    char res[MAX_SIZE];

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
    char str[MAX_SIZE];
    printf("Enter a string: ");
    if (fgets(str, MAX_SIZE, stdin)) {
        str[strcspn(str, "\n")] = '\0'; // removes the trailing newline character
        LetterCapitalize(str);
    }
    return 0;
}