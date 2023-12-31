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
    if (params == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    CntIter = (unsigned long long *)calloc(num_threads, sizeof(unsigned long long));
    if (CntIter == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        free(params);
        exit(EXIT_FAILURE);
    }

    ids = (pthread_t *)malloc(num_threads * sizeof(pthread_t));
    if (ids == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        free(params);
        free(CntIter);
        exit(EXIT_FAILURE);
    }

    // operation distribution
    for (i = 0; i < num_threads; ++i)
    {
        params[i].idx = i;
        if (pthread_create(&ids[i], NULL, partial_sum, &params[i]) != 0)
        {
            fprintf(stderr, "Unable to create thread %llu\n", i);
            exit(EXIT_FAILURE);
        }
    }

    // join threads
    for (i = 0; i < num_threads; ++i)
    {
        if (pthread_join(ids[i], NULL) != 0)
        {
            fprintf(stderr, "Unable to join thread %llu\n", i);
            exit(EXIT_FAILURE);
        }
    }

    // free memory
    free(params);
    free(CntIter);
    free(ids);

    // calculate pi
    for (i = 0; i < num_threads; ++i)
    {
        pi += params[i].sum;
    }

    // print result
    printf("Pi: %.10f\n", pi);

    return ret_code;
}

void *partial_sum(void *ptr)
{
    union params *p = (union params *)ptr;
    unsigned long long i = p->idx;
    double sum = 0;
    unsigned long long start = i;
    unsigned long long end = module;
    unsigned long long j;

    for (j = start; j < end; j += num_threads)
    {
        double x = (double)j / module;
        sum += 4.0 / (1 + x * x);
    }

    pthread_rwlock_wrlock(&rwlock);
    p->sum = sum;
    pthread_rwlock_unlock(&rwlock);

    return NULL;
}

void handlesgint(int sig)
{
    is_interrupted = 1;
}