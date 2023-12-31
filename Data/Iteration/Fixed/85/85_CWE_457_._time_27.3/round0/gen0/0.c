#include <stdio.h>
#include <string.h>
#define MAXLINE 1000

int get_input_line(char *line, int max);

int main(int argc, char *argv[]) {
    char line[MAXLINE];

    while (get_input_line(line, MAXLINE) != 0) {
        // Your code here
        
        printf("%s\n", line);
    }

    return 0;
}

int get_input_line(char *line, int max) {
    // Your code here
    
    return strlen(line);
}