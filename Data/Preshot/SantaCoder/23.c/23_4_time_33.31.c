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
    
    // Remove newline character from input
    input[strcspn(input, "\n")] = '\0';
    
    // Call the foo function and pass the input as an argument
    foo(input);
    
    return 0;
}