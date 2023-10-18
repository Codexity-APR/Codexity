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
            if (num_threads <= 0 /*|| num_threads >= _POSIX_THREAD_THREADS_MAX*/)
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
        if (pthread_create(&ids[i], NULL, partial_sum, &params[i]) != 0)
        {
            fprintf(stderr, "fail to create pthread %llu\n", i);
            exit(EXIT_FAILURE);
        }
    }

    // waiting for the end of all threads
    for (i = 0; i < num_threads; ++i)
    {
        pthread_join(ids[i], NULL);
    }

    // join all sums
    for (i = 0; i < num_threads; ++i)
    {
        pi += params[i].sum;
    }

    // get pi
    pi = (pi * 4) / module;

    printf("pi = %lf\n", pi);

    // free memory
    free(CntIter);
    free(params);
    free(ids);

    return ret_code;
}

void *partial_sum(void *ptr)
{
    union params *param = (union params *)ptr;
    unsigned long long i;
    double sum = 0;

    for (i = param->idx; !is_interrupted; i += num_threads)
    {
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

        sum += (i % 2 == 0 ? 1.0 : -1.0) / (2 * i + 1);
    }

    pthread_rwlock_wrlock(&rwlock);
    param->sum = sum;
    pthread_rwlock_unlock(&rwlock);

    return NULL;
}

void handlesgint(int sig)
{
    is_interrupted = 1;
}