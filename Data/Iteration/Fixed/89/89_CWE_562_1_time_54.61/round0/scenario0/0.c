List of vulnerabilities detected: 
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
    int x = 0;
    int *ptr = &x;
    test1(ptr);
    printf("After test1, x = %d\n", x);
    test2(&ptr);
    printf("After test2, x = %d\n", x);
    return 0;
}