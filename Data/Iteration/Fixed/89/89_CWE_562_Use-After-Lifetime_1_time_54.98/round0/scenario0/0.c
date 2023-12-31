List of vulnerabilities detected: 
Error: Use After Lifetime   Pulse found a potential null pointer dereference  on line 17 indirectly during the call to `test2()`.
 Example: 
  18. 
  19.     printf("num1: %d\n", num1); // Output: num1: 5
  20.     printf("num2: %d\n", *num2); // Output: num2: 6
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
    int num1 = 0;
    int *num2 = NULL;
    test1(&num1);
    test2(&num2);
    printf("num1: %d\n", num1); // Output: num1: 5
    printf("num2: %d\n", *num2); // Output: num2: 6
    return 0;
}