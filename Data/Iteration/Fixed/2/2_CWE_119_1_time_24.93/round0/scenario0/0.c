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
    printf("Enter your physics score: ");
    scanf("%d", &p);
    printf("Enter your chemistry score: ");
    scanf("%d", &c);
    printf("Enter your math score: ");
    scanf("%d", &m);
    // Rest of the code goes here
    return 0;
}