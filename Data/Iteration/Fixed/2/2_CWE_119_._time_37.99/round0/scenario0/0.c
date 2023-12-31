List of vulnerabilities detected: 
 Error type: CWE-119 at line: 10. Error message: scanf() without field width limits can crash with huge input data.


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    char name[20];
    int p, c, m;
    printf("Enter your name: ");
    scanf("%s", name);
    printf("Enter your physics marks: ");
    scanf("%d", &p);
    printf("Enter your chemistry marks: ");
    scanf("%d", &c);
    printf("Enter your maths marks: ");
    scanf("%d", &m);
    int total = p + c + m;
    float average = total / 3.0;
    printf("\nName: %s\n", name);
    printf("Physics marks: %d\n", p);
    printf("Chemistry marks: %d\n", c);
    printf("Maths marks: %d\n", m);
    printf("Total marks: %d\n", total);
    printf("Average marks: %.2f\n", average);
    return 0;
}