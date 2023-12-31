List of vulnerabilities detected: 
Error: Use After Lifetime   Pulse found a potential null pointer dereference  on line 19 indirectly during the call to `test2()`.
 Example: 
  18. 
  19.     test2(&num_pointer);
  20.     printf("Value after test2: %d\n", *num_pointer);
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
    *int_pointer = &i;
}
int main() {
    int num = 0;
    int *num_pointer = &num;
    test1(num_pointer);
    printf("Value after test1: %d\n", num);
    test2(&num_pointer);
    printf("Value after test2: %d\n", *num_pointer);
    return 0;
}