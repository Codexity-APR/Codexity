#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char str[] = "..1....10..20....30...40....50...80...";
    int nums[10] = {0}; // initializing the array to zero
    int i, num_count = 0;
    
    for (i = 0; i < strlen(str); i++) {
        if (str[i] >= '0' && str[i] <= '9') {
            // read the number as a string using sscanf
            char num_str[10];
            int j = 0;
            while (str[i] >= '0' && str[i] <= '9') {
                num_str[j++] = str[i++];
            }
            num_str[j] = '\0';
            // convert the string to an integer using atoi
            nums[num_count++] = atoi(num_str);
        }
    }
    
    // print the extracted numbers
    for (i = 0; i < num_count; i++) {
        printf("%d ", nums[i]);
    }
    return 0;
}

int atoi(char *str) {
    int i, j, num_count = 0;
    int sign = 1;
    int nums[10] = {0}; // initializing the array to zero
    
    for (i = 0; i < strlen(str); i++) {
        if (str[i] >= '0' && str[i] <= '9') {
            // read the number as a string using sscanf
            char num_str[10];
            int j = 0;
            while (str[i] >= '0' && str[i] <= '9') {
                num_str[j++] = str[i++];
            }
            num_str[j] = '\0';
            // convert the string to an integer using atoi
            nums[num_count++] = atoi(num_str);
        } else if (str[i] == '+') {
            sign = 1;
        } else if (str[i] == '-') {
            sign = -1;
        }
    }
    
    // calculate the integer value
    int result = 0;
    for (i = 0; i < num_count; i++) {
        result = result * 10 + nums[i];
    }
    result *= sign;
    return result;
}

int sscanf(char *str, char *fmt, int *n) {
    // not implemented in this example
    return 0;
}

int sscanf(char *str, char *fmt) {
    // not implemented in this example
    return 0;
}