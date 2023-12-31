List of vulnerabilities detected: 
Error: Use After Lifetime   Pulse found a potential null pointer dereference  on line 21 indirectly during the call to `test2()`.
 Example: 
  20.     printf("Before test2: %d\n", *num_pointer);
  21.     test2(&num_pointer);
  22.     printf("After test2: %d\n", *num_pointer);
                                      ^
  23. 
  24.     return 0;

 Error type: CWE-562 at line: 9. Error message: Address of local auto-variable assigned to a function parameter.


#include <stdio.h>
void test1(int *int_pointer) {
    *int_pointer = 5;
}
void test2(int **int_pointer) {
    int i = 6;
    *int_pointer = &i; // Assign the address of i to int_pointer
}
int main() {
    int num = 0;
    int *num_pointer = &num;
    printf("Before test1: %d\n", *num_pointer);
    test1(num_pointer);
    printf("After test1: %d\n", *num_pointer);
    printf("Before test2: %d\n", *num_pointer);
    test2(&num_pointer);
    printf("After test2: %d\n", *num_pointer);
    return 0;
}