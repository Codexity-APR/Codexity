List of vulnerabilities detected: 
Error: Use After Lifetime   Pulse found a potential null pointer dereference  on line 19 indirectly during the call to `test2()`.
 Example: 
  18.     printf("Before test2: %d\n", number);
  19.     test2(&number_pointer);
  20.     printf("After test2: %d\n", *number_pointer);
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
    int number = 0;
    int *number_pointer = &number;
    printf("Before test1: %d\n", number);
    test1(number_pointer);
    printf("After test1: %d\n", number);
    printf("Before test2: %d\n", number);
    test2(&number_pointer);
    printf("After test2: %d\n", *number_pointer);
    return 0;
}