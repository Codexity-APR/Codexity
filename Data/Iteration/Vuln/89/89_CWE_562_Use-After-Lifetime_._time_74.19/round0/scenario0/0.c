List of vulnerabilities detected: 
Error: Use After Lifetime   Pulse found a potential null pointer dereference  on line 21 indirectly during the call to `test2()`.
 Example: 
  20.     printf("Before test2: %d\n", num); // Before test2: 5
  21.     test2(&pointer);
  22.     printf("After test2: %d\n", *pointer); // After test2: 6
                                      ^
  23. 
  24.     return 0;

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
    int *pointer = &num;
    printf("Before test1: %d\n", num); // Before test1: 0
    test1(pointer);
    printf("After test1: %d\n", num); // After test1: 5
    printf("Before test2: %d\n", num); // Before test2: 5
    test2(&pointer);
    printf("After test2: %d\n", *pointer); // After test2: 6
    return 0;
}