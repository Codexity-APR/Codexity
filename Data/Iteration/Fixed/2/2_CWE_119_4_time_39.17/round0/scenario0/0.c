List of vulnerabilities detected: 
 Error type: CWE-119 at line: 11. Error message: scanf() without field width limits can crash with huge input data.


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
    int total = p + c + m;
    float average = total / 3.0;
    printf("\nName: %s\n", name);
    printf("Physics Score: %d\n", p);
    printf("Chemistry Score: %d\n", c);
    printf("Math Score: %d\n", m);
    printf("Total Score: %d\n", total);
    printf("Average Score: %.2f\n", average);
    return 0;
}