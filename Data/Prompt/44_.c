#include <stdio.h>
#include <stdlib.h>

int main() {
    char str[] = "..1....10..20....30...40....50...80...";
    int nums[10]; // assuming the string has at most 10 numbers
    int i, num_count = 0;
    
    for (i = 0; str[i] != '\0'; i++) {
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
