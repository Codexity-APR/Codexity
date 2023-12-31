#include <stdio.h>

void test1(int *int_pointer) {
    *int_pointer = 5; 
}

void test2(int **int_pointer) { 
    int i = 6;
    *int_pointer = &i;
    // Here, we are assigning the address of variable i to the pointer to a pointer to int.
    // The pointer to a pointer to int now points to variable i.
}

int main() {
    int *int_pointer = NULL;
    test1(int_pointer);
    test2(&int_pointer);
    printf("%d",*int_pointer); // should print 6
    return 0;
}