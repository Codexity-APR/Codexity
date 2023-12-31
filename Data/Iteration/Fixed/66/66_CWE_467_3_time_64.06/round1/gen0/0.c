#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int sortAndFindLargest(int arr[], int size);

int main() {
    int array1[] = {1, 2, 3, 4, 5};
    int array2[] = {6, 7, 8, 9, 10};
    int pipefd[2], result1, result2;

    if (pipe(pipefd) == -1) {
        perror("pipe");
        exit(EXIT_FAILURE);
    }

    pid_t pid = fork();
    if (pid == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    } else if (pid == 0) {
        close(pipefd[0]);
        result1 = sortAndFindLargest(array1, sizeof(array1) / sizeof(array1[0]));
        write(pipefd[1], &result1, sizeof(int));
        close(pipefd[1]);
        exit(EXIT_SUCCESS);
    } else {
        close(pipefd[1]);
        result2 = sortAndFindLargest(array2, sizeof(array2) / sizeof(array2[0]));
        wait(NULL);
        read(pipefd[0], &result1, sizeof(int));
        close(pipefd[0]);
        printf("Result: %d\n", result2 - result1);
        exit(EXIT_SUCCESS);
    }
}

int sortAndFindLargest(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    return arr[size - 1];
}