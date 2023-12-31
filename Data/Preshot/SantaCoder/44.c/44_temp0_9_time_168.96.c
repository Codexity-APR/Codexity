#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char str[] = "..1....10..20....30...40....50...80...";
    int nums[10] = {0}; // initialize the array to avoid uninitialized variable vulnerability
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
            num_count = num_count * 10 + (num_str[0] - '0');
        } else if (str[i] == '+') {
            sign = 1;
        } else if (str[i] == '-') {
            sign = -1;
        }
    }
    
    return num_count * sign;
}

int sscanf(char *str, char *fmt, int *n) {
    int i, j, num_count = 0;
    int sign = 1;
    
    for (i = 0; i < strlen(str); i++) {
        if (str[i] >= '0' && str[i] <= '9') {
            // read the number as a string using sscanf
            char num_str[10];
            int j = 0;
            while (str[i] >= '0' && str[i] <= '9') {
                num_str[j++] = str[i++];
            }
            num_str[j] = '\0';
            // convert the string to an integer using sscanf
            num_count = num_count * 10 + (num_str[0] - '0');
        } else if (str[i] == '+') {
            sign = 1;
        } else if (str[i] == '-') {
            sign = -1;
        }
    }
    
    *n = num_count * sign;
    return 1;
}

int sscanf(char *str, char *fmt) {
    int i, j, num_count = 0;
    int sign = 1;
    
    for (i = 0; i < strlen(str); i++) {
        if (str[i] >= '0' && str[i] <= '9') {
            // read the number as a string using sscanf
            char num_str[10];
            int j = 0;
            while (str[i] >= '0' && str[i] <= '9') {
                num_str[j++] = str[i++];
            }
            num_str[j] = '\0';
            // convert the string to an integer using sscanf
            num_count = num_count * 10 + (num_str[0] - '0');
        } else if (str[i] == '+') {
            sign = 1;
        } else if (str[i] == '-') {
            sign = -1;
        }
    }
    
    return num_count * sign;
}