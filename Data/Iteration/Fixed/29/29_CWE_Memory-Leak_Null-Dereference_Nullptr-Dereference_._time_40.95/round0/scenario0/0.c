List of vulnerabilities detected: 
Error: Memory Leak   Pulse found a potential memory leak. Memory dynamically allocated at line 14 by call to `add_value_to_array()`, is not freed after the last access at line 21, column 5.
 Example: 
  19.     printf("looool\n");
  20. 
  21.     free(arr[0]);
          ^
  22.     return 0;
  23. }

Error: Null Dereference   pointer `*array` last assigned on line 5 could be null and is dereferenced at line 6, column 5.
 Example: 
  4. void add_value_to_array(int ***array, int *value_ptr) {
  5.     *array = malloc(sizeof(int**));
  6.     **array = value_ptr;
         ^
  7. }
  8.

Error: Nullptr Dereference   Pulse found a potential null pointer dereference  on line 5.
 Example: 
  4. void add_value_to_array(int ***array, int *value_ptr) {
  5.     *array = malloc(sizeof(int**));
  6.     **array = value_ptr;
         ^
  7. }
  8.


#include <stdio.h>
#include <stdlib.h>
void add_value_to_array(int ***array, int *value_ptr) {
    *array = malloc(sizeof(int**));
    **array = value_ptr;
}
int main() {
    int *arr[1] = {0}; // or int **arr = malloc(sizeof(int *));
    int value = 5;
    int *value_ptr = &value;
    add_value_to_array(&arr, value_ptr);
    printf("looool\n");
    printf("looool\n");
    printf("looool\n");
    printf("looool\n");
    free(arr[0]);
    return 0;
}