#include <stdio.h>

int main(){
    char c, w[50], s[300];
    int i = 0, j = 0;

    printf("Enter a string: ");
    gets(s);

    printf("\nEnter a character to search: ");
    scanf("%c", &c);

    while (s[i] != '\0') {
        if (s[i] == c) {
            j++;
            break;
        }
        i++;
    }

    if (j != 0)
        printf("\n'%c' is present in the string.", c);
    else
        printf("\n'%c' is not present in the string.", c);

    return 0;
}