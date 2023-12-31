List of vulnerabilities detected: 
 Error type: CWE-119 at line: 21. Error message: scanf() without field width limits can crash with huge input data.


#include <stdio.h>
int main()
{
    FILE *f;
    int i;
    typedef struct {
        int a;
        char ab[10];
    } b;
    b var[2];
    f = fopen("new.c", "wb");
    if (f == NULL) {
        printf("Failed to open file\n");
        return 1;
    }
    printf("Enter values in structure\n");
    for (i = 0; i < 2; i++) {
        scanf("%d", &var[i].a);
        printf("Enter string: ");
        scanf("%s", var[i].ab);
    }
    fwrite(var, sizeof(b), 2, f);
    fclose(f);
    return 0;
}