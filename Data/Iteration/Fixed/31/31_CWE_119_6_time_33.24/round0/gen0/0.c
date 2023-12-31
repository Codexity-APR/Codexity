#include <stdio.h>

typedef struct {
    int a;
    char ab[10];
} b;

int main()
{
    FILE *f;
    int i;
    b var[2];
    f = fopen("new.c", "wb");
    if (f == NULL) {
        printf("Failed to open file\n");
        return 1;
    }
    printf("Enter values in structure\n");
    for (i = 0; i < 2; i++) {
        printf("Enter value for var[%d].a: ", i);
        scanf("%d", &var[i].a);
        printf("Enter value for var[%d].ab: ", i);
        scanf("%s", var[i].ab);
    }
    fwrite(var, sizeof(b), 2, f);
    fclose(f);
    return 0;
}