List of vulnerabilities detected: 
Error: Use After Lifetime   Pulse found a potential null pointer dereference  on line 19 indirectly during the call to `test2()`.
 Example: 
  18. 
  19.     test2(&ptr);
  20.     printf("After test2: %d\n", *ptr);
                                      ^
  21. 
  22.     return 0;

 Error type: CWE-562 at line: 9. Error message: Address of local auto-variable assigned to a function parameter.


#include <stdio.h>
void test1(int *int_pointer) {
    *int_pointer = 5;
}
void test2(int **int_pointer) { // We need to pass a pointer to a pointer to int
    int i = 6;
    *int_pointer = &i; // Assign the address of i to the pointer to pointer
}
int main() {
    int num = 0;
    int *ptr = &num;
    test1(ptr);
    printf("After test1: %d\n", num);
    test2(&ptr);
    printf("After test2: %d\n", *ptr);
    return 0;
}