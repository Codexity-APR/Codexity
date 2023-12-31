#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char str[] = "..1....10..20....30...40....50...80...";
    int nums[10] = {0}; // initialize the array
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
    int nums[10] = {0}; // initialize the array
    
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
    
    // print the extracted numbers
    int result = 0;
    for (i = 0; i < num_count; i++) {
        result = result * 10 + nums[i];
    }
    return result * sign;
}

int sscanf(char *str, char *fmt, int *n) {
    int i, j, num_count = 0;
    int sign = 1;
    int nums[10] = {0}; // initialize the array
    
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
            nums[num_count++] = sscanf(num_str, fmt, n);
        } else if (str[i] == '+') {
            sign = 1;
        } else if (str[i] == '-') {
            sign = -1;
        }
    }
    
    // print the extracted numbers
    int result = 0;
    for (i = 0; i < num_count; i++) {
        result = result * 10 + nums[i];
    }
    return result * sign;
}

int sscanf(char *str, char *fmt) {
    int i, j, num_count = 0;
    int sign = 1;
    int nums[10] = {0}; // initialize the array
    
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
            nums[num_count++] = sscanf(num_str, fmt);
        } else if (str[i] == '+') {
            sign = 1;
        } else if (str[i] == '-') {
            sign = -1;
        }
    }
    
    // print the extracted numbers
    int result = 0;
    for (i = 0; i < num_count; i++) {
        result = result * 10 + nums[i];
    }
    return result * sign;
}

int sscanf(char *str, char *fmt, int *n) {
    int i, j, num_count = 0;
    int sign = 1;
    int nums[10] = {0}; // initialize the array
    
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
            nums[num_count++] = sscanf(num_str, fmt, n);
        } else if (str[i] == '+') {
            sign = 1;
        } else if (str[i] == '-') {
            sign = -1;
        }
    }
    
    // print the extracted numbers
    int result = 0;
    for (i = 0; i < num_count; i++) {
        result = result * 10 + nums[i];
    }
    return result * sign;
}