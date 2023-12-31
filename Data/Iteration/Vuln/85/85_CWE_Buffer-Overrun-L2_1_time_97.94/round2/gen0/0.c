#include <stdio.h>
#include <string.h>

#define MAXLINE 1000

int get_input_line(char *line, int max);

int main(int argc, char *argv[]) {
    char line[MAXLINE];
    while (get_input_line(line, MAXLINE) != EOF) {
        // Add your code here
    }
    return 0;
}

int get_input_line(char *line, int max) {
    int c, i;
    for (i = 0; i < max - 1 && (c = getchar()) != EOF && c != '\n'; ++i) {
        line[i] = c;
    }
    if (i == max - 1) {
        // Discard remaining characters in the input buffer
        while ((c = getchar()) != EOF && c != '\n') {
            // Do nothing
        }
    }
    if (c == '\n') {
        line[i] = c;
        ++i;
    }
    line[i] = '\0';

    // Check if the input exceeded the buffer size
    if (i == max - 1 && c != '\n') {
        // Discard remaining characters in the input buffer
        while ((c = getchar()) != EOF && c != '\n') {
            // Do nothing
        }
    }

    return c;
}