List of vulnerabilities detected: 
Error: Memory Leak   Pulse found a potential memory leak. Memory dynamically allocated at line 19 by call to `malloc`, is not freed after the last access at line 27, column 9.
 Example: 
  25.         printf("Before test2: %d\n", *num_pointer);
  26.         test2(&num_pointer);
  27.         printf("After test2: %d\n", *num_pointer);
              ^
  28.         free(num_pointer); // Free the dynamically allocated memory
  29.         num_pointer = NULL; // Set the pointer to NULL after freeing


#include <stdio.h>
#include <stdlib.h>
void test1(int *int_pointer) {
    if (int_pointer != NULL) {
        *int_pointer = 5;
    }
}
void test2(int **int_pointer) {
    int *i = malloc(sizeof(int));
    if (i != NULL) {
        *i = 6;
        *int_pointer = i;
    }
}
int main() {
    int *num_pointer = malloc(sizeof(int));
    if (num_pointer != NULL) {
        *num_pointer = 0;
        printf("Before test1: %d\n", *num_pointer);
        test1(num_pointer);
        printf("After test1: %d\n", *num_pointer);
        printf("Before test2: %d\n", *num_pointer);
        test2(&num_pointer);
        printf("After test2: %d\n", *num_pointer);
        free(num_pointer); // Free the dynamically allocated memory
        num_pointer = NULL; // Set the pointer to NULL after freeing
    }
    return 0;
}