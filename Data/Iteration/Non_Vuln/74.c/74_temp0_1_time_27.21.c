#include <stdio.h>

int main() {
    int n, largest, smallest, sum, count;
    
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    
    printf("Enter element 1: ");
    scanf("%d", &largest);
    
    smallest = largest;
    sum = largest;
    count = 1;
    
    for (int i = 2; i <= n; i++) {
        int num;
        printf("Enter element %d: ", i);
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
    
    printf("Largest element: %d\n", largest);
    printf("Smallest element: %d\n", smallest);
    printf("Sum of all elements: %d\n", sum);
    printf("Average of all elements: %.2f\n", (float) sum / count);
    
    return 0;
}