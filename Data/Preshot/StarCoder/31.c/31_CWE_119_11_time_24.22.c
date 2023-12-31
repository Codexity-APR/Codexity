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
        printf("Enter a string for element %d: ", i);
        scanf("%s", var[i].ab);
    }
    printf("Values entered are:\n");
    for (i = 0; i < 2; i++) {
        printf("%d %s\n", var[i].a, var[i].ab);
    }
    fwrite(&var, sizeof(var), 1, f);
    fclose(f);
    return 0;
}