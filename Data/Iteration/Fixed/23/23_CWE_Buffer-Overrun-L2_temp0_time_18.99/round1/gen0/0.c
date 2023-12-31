#include <stdio.h>
#include <string.h>

void foo(char *input) {
    char buf[11]; // Increase buffer size by 1 to accommodate the null terminator
    strncpy(buf, input, sizeof(buf) - 1); // Use strncpy to limit the number of characters copied
    buf[sizeof(buf) - 1] = '\0'; // Ensure null termination
    printf("Input: %s\n", buf);
}

int main() {
    char input[100];
    printf("Enter a string: ");
    fgets(input, sizeof(input), stdin);
    foo(input);
    return 0;
}