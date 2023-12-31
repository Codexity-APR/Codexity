#include <stdio.h>
#include <string.h>

#define MAXLINE 1000

int get_input_line(char *line, int max);

int main(int argc, char *argv[]) {
    char line[MAXLINE];
    int len;
    
    while ((len = get_input_line(line, MAXLINE)) > 0) {
        // Your code here
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
        // You can choose to truncate the line or display an error message
        // Here, we simply discard the remaining characters
        while ((c = getchar()) != EOF && c != '\n') {
            // Discard the characters
        }
    }
    
    if (c == '\n') {
        line[i] = c;
        i++;
    }
    
    if (i < max) {
        line[i] = '\0';
    } else {
        line[max - 1] = '\0';
    }
    
    return i;
}