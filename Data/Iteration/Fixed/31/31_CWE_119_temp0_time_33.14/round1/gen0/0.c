#include <stdio.h>
#define MAX_STRING_LENGTH 10

int main()
{
    FILE *f;
    int i;
    typedef struct {
        int a;
        char ab[MAX_STRING_LENGTH];
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
        scanf("%9s", var[i].ab); // Specify field width limit as 9
    }
    fwrite(var, sizeof(b), 2, f);
    fclose(f);
    return 0;
}