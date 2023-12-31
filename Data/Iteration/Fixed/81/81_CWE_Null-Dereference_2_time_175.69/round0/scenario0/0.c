List of vulnerabilities detected: 
Error: Null Dereference   pointer `params` last assigned on line 66 could be null and is dereferenced at line 73, column 9.
 Example: 
  71.     for (i = 0; i < num_threads; ++i)
  72.     {
  73.         params[i].idx = i;
              ^
  74.         if (0 != pthread_create(&ids[i], NULL, partial_sum, &params[i]))
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
        if (0 != pthread_create(&ids[i], NULL, partial_sum, &params[i]))
        {
            perror("pthread_create");
            exit(EXIT_FAILURE);
        }
    }
    // waiting threads
    for (i = 0; i < num_threads; ++i)
    {
        if (0 != pthread_join(ids[i], NULL))
        {
            perror("pthread_join");
            exit(EXIT_FAILURE);
        }
    }
    // calculate pi
    for (i = 0; i < num_threads; ++i)
    {
        pi += params[i].sum;
    }
    pi = pi * 4;
    printf("pi = %.15g\n", pi);
    // cleanup
    free(params);
    free(CntIter);
    free(ids);
    return ret_code;
}
void *partial_sum(void *ptr)
{
    unsigned long long i;
    double factor;
    unsigned long long idx = ((union params *)ptr)->idx;
    double sum = 0.0;
    // perform partial sum
    for (i = idx; !is_interrupted && i < module; i += num_threads)
    {
        factor = (i % 2 == 0) ? 1.0 : -1.0;
        sum += factor / (2 * i + 1);
        // check for interruption
        if (i % num_steps_per_check == 0)
        {
            pthread_rwlock_rdlock(&rwlock);
            if (is_interrupted)
            {
                pthread_rwlock_unlock(&rwlock);
                break;
            }
            pthread_rwlock_unlock(&rwlock);
        }
    }
    // store partial sum
    pthread_rwlock_wrlock(&rwlock);
    CntIter[idx] = i;
    ((union params *)ptr)->sum = sum;
    pthread_rwlock_unlock(&rwlock);
    return NULL;
}
void handlesgint(int sig)
{
    pthread_rwlock_wrlock(&rwlock);
    is_interrupted = 1;
    pthread_rwlock_unlock(&rwlock);
}