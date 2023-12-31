#include <stdio.h>
#define MAX_INPUT_SIZE 10

int main()
{
    FILE *f;
    int i;
    typedef struct {
        int a;
        char ab[MAX_INPUT_SIZE];
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
        printf("Enter value for ab: ");
        scanf("%9s", var[i].ab); // Specify field width limit as 9
    }
    fwrite(var, sizeof(b), 2, f);
    fclose(f);
    f = fopen("new.c", "rb");
    if (f == NULL) {
        printf("Failed to open file\n");
        return 1;
    }
    b readVar[2];
    fread(readVar, sizeof(b), 2, f);
    fclose(f);
    printf("Values read from file:\n");
    for (i = 0; i < 2; i++) {
        printf("a: %d, ab: %s\n", readVar[i].a, readVar[i].ab);
    }
    return 0;
}