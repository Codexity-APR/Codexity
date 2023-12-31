List of vulnerabilities detected: 
Error: Null Dereference   pointer `params` last assigned on line 66 could be null and is dereferenced at line 73, column 9.
 Example: 
  71.     for (i = 0; i < num_threads; ++i)
  72.     {
  73.         params[i].idx = i;
              ^
  74.         if (pthread_create(&ids[i], NULL, partial_sum, (void *)&params[i]) != 0)
  75.         {


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
    if (1 == argc)
    {
        fprintf(stderr, "Usage: %s -n num_threads\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    while ((opt = getopt(argc, argv, "n:")) != -1)
    {
        switch (opt)
        {
        case 'n':
            num_threads = atoi(optarg);
            {
                fprintf(stderr, "quantity of threads invalid\n");
                exit(EXIT_FAILURE);
            }
            break;
        default:
            fprintf(stderr, "Usage: %s -n num_threads\n", argv[0]);
            exit(EXIT_FAILURE);
        }
    }
    // setting handler
    if (SIG_ERR == signal(SIGINT, handlesgint))
    {
        perror("fail signal");
        exit(EXIT_FAILURE);
    }
    // init memory
    params = (union params *)malloc(num_threads * sizeof(union params));
    CntIter = (unsigned long long *)calloc(num_threads, sizeof(long long));
    ids = (pthread_t *)malloc(num_threads * sizeof(pthread_t));
    // operation distribution
    for (i = 0; i < num_threads; ++i)
    {
        params[i].idx = i;
        if (pthread_create(&ids[i], NULL, partial_sum, (void *)&params[i]) != 0)
        {
            fprintf(stderr, "Thread creation failed\n");
            exit(EXIT_FAILURE);
        }
    }
    // wait for threads to finish
    for (i = 0; i < num_threads; ++i)
    {
        if (pthread_join(ids[i], NULL) != 0)
        {
            fprintf(stderr, "Thread join failed\n");
            exit(EXIT_FAILURE);
        }
        pi += params[i].sum;
    }
    pi = pi * num_steps_per_check / module;
    // cleanup
    free(params);
    free(ids);
    free(CntIter);
    printf("Calculated pi: %.10f\n", pi);
    return ret_code;
}
void *partial_sum(void *ptr)
{
    union params *local_params = (union params *)ptr;
    unsigned long long idx = local_params->idx;
    double sum = 0;
    unsigned long long i;
    for (i = idx; !is_interrupted; i += num_threads)
    {
        sum += ((i % 2 == 0) ? 1.0 : -1.0) / (2 * i + 1);
        CntIter[idx]++;
    }
    local_params->sum = sum;
    return NULL;
}
void handlesgint(int sig)
{
    (void)sig;
    is_interrupted = 1;
}