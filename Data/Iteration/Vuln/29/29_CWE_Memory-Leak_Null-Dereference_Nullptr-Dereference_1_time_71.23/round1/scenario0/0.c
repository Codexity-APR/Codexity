List of vulnerabilities detected: 
Error: Null Dereference   pointer `arr` last assigned on line 15 could be null and is dereferenced at line 20, column 10.
 Example: 
  18.     printf("looool\n");
  19.     printf("looool\n");
  20.     free(*arr);
               ^
  21.     free(arr);
  22.     return 0;

Error: Nullptr Dereference   Pulse found a potential null pointer dereference  on line 15 indirectly during the call to `add_value_to_array()`.
 Example: 
  18.     printf("looool\n");
  19.     printf("looool\n");
  20.     free(*arr);
               ^
  21.     free(arr);
  22.     return 0;

Error: Memory Leak   Pulse found a potential memory leak. Memory dynamically allocated at line 12 by call to `malloc`, is not freed after the last access at line 15, column 5.
 Example: 
  13.     int value = 5;
  14.     int *value_ptr = &value;
  15.     add_value_to_array(&arr, value_ptr);
          ^
  16.     printf("looool\n");
  17.     printf("looool\n");


#include <stdio.h>
#include <stdlib.h>
void add_value_to_array(int ***array, int *value_ptr) {
    *array = malloc(sizeof(int **));
    if (*array != NULL) {
        **array = value_ptr;
    }
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