List of vulnerabilities detected: 
 Error type: CWE-467 at line: 43. Error message: Using 'sizeof' on array given as function argument returns size of a pointer.


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
    // sort the array
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    // return the largest element
    return arr[n - 1];
}