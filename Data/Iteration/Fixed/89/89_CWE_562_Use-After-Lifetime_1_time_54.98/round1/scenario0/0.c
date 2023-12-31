List of vulnerabilities detected: 
Error: Use After Lifetime   Pulse found a potential null pointer dereference  on line 16 indirectly during the call to `test2()`.
 Example: 
  18.     
  19.     if (num2 != NULL) {
  20.         printf("num2: %d\n", *num2);
                                   ^
  21.     } else {
  22.         printf("num2 is NULL\n");

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
    int num1 = 0;
    int *num2 = NULL;
    test1(&num1);
    test2(&num2);
    printf("num1: %d\n", num1);
    if (num2 != NULL) {
        printf("num2: %d\n", *num2);
    } else {
        printf("num2 is NULL\n");
    }
    return 0;
}