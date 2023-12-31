List of vulnerabilities detected: 
Error: Use After Lifetime   Pulse found a potential null pointer dereference  on line 19 indirectly during the call to `test2()`.
 Example: 
  18.     int temp;
  19.     test2(&ptr);
  20.     temp = *ptr;
                 ^
  21.     printf("After test2: %d\n", temp);
  22.

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
    int num = 0;
    int *ptr = &num;
    test1(ptr);
    printf("After test1: %d\n", num);
    int temp;
    test2(&ptr);
    temp = *ptr;
    printf("After test2: %d\n", temp);
    return 0;
}