#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char str[] = "..1....10..20....30...40....50...80...";
    int nums[10] = {0}; // initializing nums array to all zeros
    int i, num_count = 0;

    for (i = 0; str[i] != '\0'; i++) {
        if (isdigit(str[i])) { // using isdigit() function to check if character is a digit
            char num_str[10];
            int j = 0;
            while (isdigit(str[i])) {
                num_str[j++] = str[i++];
            }
            num_str[j] = '\0';
            nums[num_count++] = atoi(num_str);
        }
    }

    for (i = 0; i < num_count; i++) {
        printf("%d ", nums[i]);
    }

    return 0;
}