#include <stdio.h>
#include <string.h>

void foo(char *input) {
    char buf[10];
    strncpy(buf, input, sizeof(buf)-1);
    buf[sizeof(buf)-1] = '\0';
    printf("Input: %s\n", buf);
}

int main() {
    char input[100];
    printf("Enter a string: ");
    fgets(input, 100, stdin);
    foo(input);
    return 0;
}
