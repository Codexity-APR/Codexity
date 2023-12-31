List of vulnerabilities detected: 
Error: Memory Leak   Pulse found a potential memory leak. Memory dynamically allocated at line 15 by call to `add_value_to_array()`, is not freed after the last access at line 20, column 5.
 Example: 
  18.     printf("looool\n");
  19.     printf("looool\n");
  20.     free(arr[0]);
          ^
  21.     return 0;
  22. }


#include <stdio.h>
#include <stdlib.h>
void add_value_to_array(int ***array, int *value_ptr) {
    *array = malloc(sizeof(int**));
    if (*array != NULL) {
        **array = value_ptr;
    }
}
int main() {
    int *arr[1] = {NULL};
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