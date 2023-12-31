List of vulnerabilities detected: 
Error: Null Dereference   pointer `i` last assigned on line 9 could be null and is dereferenced at line 10, column 5.
 Example: 
   8. void test2(int **int_pointer) {
   9.     int *i = malloc(sizeof(int));
  10.     *i = 6;
          ^
  11.     *int_pointer = i;
  12. }

Error: Nullptr Dereference   Pulse found a potential null pointer dereference  on line 9.
 Example: 
   8. void test2(int **int_pointer) {
   9.     int *i = malloc(sizeof(int));
  10.     *i = 6;
          ^
  11.     *int_pointer = i;
  12. }


#include <stdio.h>
#include <stdlib.h>
void test1(int *int_pointer) {
    *int_pointer = 5; 
}
void test2(int **int_pointer) {
    int *i = malloc(sizeof(int));
    *i = 6;
    *int_pointer = i;
}
int main() {
    int num = 0;
    int *num_pointer = &num;
    test1(num_pointer);
    printf("Value after test1: %d\n", num);
    test2(&num_pointer);
    printf("Value after test2: %d\n", *num_pointer);
    free(num_pointer); // Free the dynamically allocated memory
    return 0;
}