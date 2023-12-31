#include <stdio.h>
#include <string.h>

#define MAXLINE 1000

int get_input_line(char *line, int max);

int main(int argc, char *argv[]) {
    char line[MAXLINE];
    int len;
    while ((len = get_input_line(line, MAXLINE)) > 0) {
        // Add your code here
    }
    return 0;
}

int get_input_line(char *line, int max) {
    int c, i;
    for (i = 0; i < max - 1 && (c = getchar()) != EOF && c != '\n'; i++) {
        line[i] = c;
    }
    if (i == max - 1 && c != '\n') {
        // Handle the case where the input line exceeds the maximum length
        while ((c = getchar()) != EOF && c != '\n') {
            // Discard the remaining characters in the input line
        }
    }
    line[i] = '\0';
    return i;
}