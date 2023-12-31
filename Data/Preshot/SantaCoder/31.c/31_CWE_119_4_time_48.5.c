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
        printf("Enter integer value for element %d: ", i+1);
        scanf("%d", &var[i].a);
        printf("Enter string value for element %d: ", i+1);
        scanf("%s", var[i].ab);
    }
    fwrite(var, sizeof(b), 2, f);
    fclose(f);
    printf("Values entered in structure are:\n");
    for (i = 0; i < 2; i++) {
        printf("Element %d: Integer: %d, String: %s\n", i+1, var[i].a, var[i].ab);
    }
    return 0;
}