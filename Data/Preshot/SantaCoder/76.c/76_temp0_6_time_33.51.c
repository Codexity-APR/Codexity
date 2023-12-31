#include <stdio.h>

int main(){
    char c, w[50], s[300];
    int i = 0, j = 0, k = 0;

    printf("Enter a sentence: ");
    while ((c = getchar()) != '\n') {
        s[i++] = c;
        if (c == ' ') {
            w[j] = '\0';
            printf("%s ", w);
            j = 0;
        } else {
            w[j++] = c;
        }
    }
    w[j] = '\0';
    printf("%s\n", w);

    return 0;
}