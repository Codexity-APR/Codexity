#include <stdio.h>
#include <string.h>

void foo(char *input) {
    char buf[10];
    strcpy(buf, input);
    printf("Input: %s\n", buf);
}

int main() {
    char input[100];
    printf("Enter a string: ");
    fgets(input, 100, stdin);
    input[strcspn(input, "\n")] = '\0'; // remove the newline character from input
    
    foo(input);
    
    return 0;
}