#include <stdio.h>

int main() {
    int n, largest, smallest, sum, count;
    
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter %d integers: ", n);
    scanf("%d", &largest);
    smallest = largest;
    sum = largest;
    count = 1;

    for (int i = 1; i < n; i++) {
        int num;
        scanf("%d", &num);
        
        if (num > largest) {
            largest = num;
        }
        if (num < smallest) {
            smallest = num;
        }
        
        sum += num;
        count++;
    }

    printf("Largest number: %d\n", largest);
    printf("Smallest number: %d\n", smallest);
    printf("Sum of numbers: %d\n", sum);
    printf("Average of numbers: %.2f\n", (float) sum / count);

    return 0;
}