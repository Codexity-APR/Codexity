#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int sortAndFindLargest(int arr[]);

int main() {
    int array1[] = {1, 2, 3, 4, 5};
    int array2[] = {6, 7, 8, 9, 10};
    int pipefd[2], result1, result2;

    // create pipe for communication between parent and child
    if (pipe(pipefd) == -1) {
        perror("pipe");
        exit(EXIT_FAILURE);
    }

    // fork a child process
    pid_t pid = fork();

    if (pid == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    } else if (pid == 0) {  // child process
        close(pipefd[0]);  // close read end of pipe
        result1 = sortAndFindLargest(array1);
        write(pipefd[1], &result1, sizeof(int));  // send result to parent
        close(pipefd[1]);  // close write end of pipe
        exit(EXIT_SUCCESS);
    } else {  // parent process
        close(pipefd[1]);  // close write end of pipe
        result2 = sortAndFindLargest(array2);
        wait(NULL);  // wait for child to finish
        read(pipefd[0], &result1, sizeof(int));  // read result from child
        close(pipefd[0]);  // close read end of pipe
        printf("Result: %d\n", result2 - result1);  // compute and print final result
        exit(EXIT_SUCCESS);
    }
}

int sortAndFindLargest(int arr[]) {
    int n = sizeof(arr) / sizeof(arr[0]);
    int temp;
  
    // Sorting the array in ascending order
    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            if (arr[j] < arr[i]) {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
  
    // Find the largest element
    int largest = arr[n-1];
  
    return largest;
}