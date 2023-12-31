List of vulnerabilities detected: 
Error: Null Dereference   pointer `params` last assigned on line 54 could be null and is dereferenced at line 61, column 9.
 Example: 
  59.     for (i = 0; i < num_threads; ++i)
  60.     {
  61.         params[i].idx = i;
              ^
  62.         if (0 != pthread_create(&ids[i], NULL, partial_sum, (void *)&params[i]))
  63.         {


#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <signal.h>
union params {
    unsigned long long idx;
    double sum;
};
#define module (1299709L)
#define num_steps_per_check (1)
unsigned long long *CntIter = NULL;
int num_threads = 0;
int is_interrupted = 0;
pthread_rwlock_t rwlock = PTHREAD_RWLOCK_INITIALIZER;
void *partial_sum(void *ptr);
void handlesgint(int sig);
int main(int argc, char *argv[])
{
    double pi = 0;
    unsigned long long i;
    int opt;
    pthread_t *ids;
    union params *params;
    int ret_code = 0;
    // parse command line
    if (argc < 3 || strcmp(argv[1], "-n") != 0)
    {
        fprintf(stderr, "Usage: %s -n num_threads\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    num_threads = atoi(argv[2]);
    if (num_threads <= 0)
    {
        fprintf(stderr, "Invalid quantity of threads\n");
        exit(EXIT_FAILURE);
    }
    // setting handler
    if (SIG_ERR == signal(SIGINT, handlesgint))
    {
        perror("fail signal");
        exit(EXIT_FAILURE);
    }
    // init memory
    params = (union params *)malloc(num_threads * sizeof(union params));
    CntIter = (unsigned long long *)calloc(num_threads, sizeof(unsigned long long));
    ids = (pthread_t *)malloc(num_threads * sizeof(pthread_t));
    // operation distribution
    for (i = 0; i < num_threads; ++i)
    {
        params[i].idx = i;
        if (0 != pthread_create(&ids[i], NULL, partial_sum, (void *)&params[i]))
        {
            fprintf(stderr, "error creating thread #%llu\n", i);
            ret_code = 1;
            goto error;
        }
    }
    // operation waiting
    for (i = 0; i < num_threads; ++i)
    {
        if (0 != pthread_join(ids[i], NULL))
        {
            fprintf(stderr, "error waiting thread #%llu\n", i);
            ret_code = 1;
            goto error;
        }
    }
    // calculate pi
    for (i = 0; i < num_threads; i++)
    {
        pi += params[i].sum;
    }
    pi *= 4;
    printf("Pi: %0.15f\n", pi);
error:
    // free memory
    free(CntIter);
    free(ids);
    free(params);
    return ret_code;
}
void *partial_sum(void *ptr)
{
    union params *param = (union params *)ptr;
    unsigned long long idx = param->idx;
    double sum = 0.0;
    unsigned long long i;
    unsigned long long start = idx * num_steps_per_check;
    unsigned long long end = (idx + 1) * num_steps_per_check;
    for (i = start; i < end && !is_interrupted; ++i)
    {
        double x = (i + 0.5) / module;
        sum += 1.0 / (1.0 + x * x);
    }
    pthread_rwlock_wrlock(&rwlock);
    param->sum = sum;
    CntIter[idx] = i;
    pthread_rwlock_unlock(&rwlock);
    pthread_exit(NULL);
}
void handlesgint(int sig)
{
    is_interrupted = 1;
}