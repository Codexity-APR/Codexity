List of vulnerabilities detected: 
Error: Memory Leak   Pulse found a potential memory leak. Memory dynamically allocated at line 11 by call to `malloc`, is not freed after the last access at line 14, column 5.
 Example: 
  12.     int value = 5;
  13.     int *value_ptr = &value;
  14.     add_value_to_array(&arr, value_ptr);
          ^
  15.     printf("looool\n");
  16.     printf("looool\n");

Error: Null Dereference   pointer `*array` last assigned on line 5 could be null and is dereferenced at line 6, column 5.
 Example: 
  4. void add_value_to_array(int ***array, int *value_ptr) {
  5.     *array = malloc(sizeof(int **));
  6.     **array = malloc(sizeof(int *));
         ^
  7.     ***array = *value_ptr;
  8. }

Error: Null Dereference   pointer `**array` last assigned on line 6 could be null and is dereferenced at line 7, column 5.
 Example: 
  5.     *array = malloc(sizeof(int **));
  6.     **array = malloc(sizeof(int *));
  7.     ***array = *value_ptr;
         ^
  8. }
  9.

Error: Nullptr Dereference   Pulse found a potential null pointer dereference  on line 6.
 Example: 
  5.     *array = malloc(sizeof(int **));
  6.     **array = malloc(sizeof(int *));
  7.     ***array = *value_ptr;
         ^
  8. }
  9.

Error: Nullptr Dereference   Pulse found a potential null pointer dereference  on line 5.
 Example: 
  4. void add_value_to_array(int ***array, int *value_ptr) {
  5.     *array = malloc(sizeof(int **));
  6.     **array = malloc(sizeof(int *));
         ^
  7.     ***array = *value_ptr;
  8. }


#include <stdio.h>
#include <stdlib.h>
void add_value_to_array(int ***array, int *value_ptr) {
    *array = malloc(sizeof(int **));
    **array = malloc(sizeof(int *));
    ***array = *value_ptr;
}
int main() {
    int **arr = malloc(sizeof(int *));
    int value = 5;
    int *value_ptr = &value;
    add_value_to_array(&arr, value_ptr);
    printf("looool\n");
    printf("looool\n");
    printf("looool\n");
    printf("looool\n");
    free(*arr);
    free(arr);
    return 0;
}