#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char str[] = "..1....10..20....30...40....50...80...";
    int nums[10] = {0}; // initializing the array with 0s
    int i, num_count = 0;

    // using strlen to get the length of the string
    for (i = 0; i < strlen(str); i++) {
        // using single quotes for character comparison
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

// atoi implementation
int atoi(char *str) {
    int i = 0, sign = 1, num = 0;

    // handling the sign of the integer
    if (str[i] == '-') {
        sign = -1;
        i++;
    } else if (str[i] == '+') {
        i++;
    }

    // calculating the integer value
    while (str[i] != '\0' && str[i] >= '0' && str[i] <= '9') {
        num = num * 10 + str[i] - '0';
        i++;
    }

    return num * sign;
}