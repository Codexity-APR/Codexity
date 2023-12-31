List of vulnerabilities detected: 
Error: Use After Lifetime   Pulse found a potential null pointer dereference  on line 19 indirectly during the call to `test2()`.
 Example: 
  18.     printf("Before test2: %d\n", *pointer);
  19.     test2(&pointer);
  20.     printf("After test2: %d\n", *pointer);
                                      ^
  21.     return 0;
  22. }

 Error type: CWE-562 at line: 9. Error message: Address of local auto-variable assigned to a function parameter.


#include <stdio.h>
void test1(int *int_pointer) {
    *int_pointer = 5;
}
void test2(int **int_pointer) {
    int i = 6;
    *int_pointer = &i;
}
int main() {
    int value = 0;
    int *pointer = &value;
    printf("Before test1: %d\n", *pointer);
    test1(pointer);
    printf("After test1: %d\n", *pointer);
    printf("Before test2: %d\n", *pointer);
    test2(&pointer);
    printf("After test2: %d\n", *pointer);
    return 0;
}