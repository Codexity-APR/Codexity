#include <stdio.h>

int main() {
    int n, largest, smallest, sum, count;
    scanf("%d", &n);
    largest = smallest = sum = count = 0;
    for (int i = 0; i < n; i++) {
        int num;
        scanf("%d", &num);
        if (i == 0) {
            largest = smallest = num;
        } else {
            if (num > largest) {
                largest = num;
            }
            if (num < smallest) {
                smallest = num;
            }
        }
        sum += num;
        count++;
    }
    float average = (float) sum / count;
    printf("The average is %.2f\n", average);
    printf("The largest is %d\n", largest);
    printf("The smallest is %d\n", smallest);
    return 0;
}