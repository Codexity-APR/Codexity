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
            perror("fail create thread");
            exit(EXIT_FAILURE);
        }
    }

    // collect partial sums
    for (i = 0; i < num_threads; ++i)
    {
        if (pthread_join(ids[i], NULL) != 0)
        {
            perror("fail join thread");
            exit(EXIT_FAILURE);
        }
        pi += params[i].sum;
    }

    pi *= 4;

    printf("Pi estimation: %.15f\n", pi);

    // free memory
    free(params);
    free(CntIter);
    free(ids);

    return ret_code;
}

void *partial_sum(void *ptr)
{
    union params *params = (union params *)ptr;
    unsigned long long i = params->idx;
    double sum = 0.0;
    unsigned long long j;

    for (j = i; !is_interrupted; j += num_threads)
    {
        sum += (j % 2 == 0 ? 1.0 : -1.0) / (2 * j + 1);
        CntIter[i]++;

        if (j % (num_threads * num_steps_per_check) == 0)
        {
            pthread_rwlock_wrlock(&rwlock);
            if (is_interrupted)
            {
                pthread_rwlock_unlock(&rwlock);
                break;
            }
            params->sum += sum;
            pthread_rwlock_unlock(&rwlock);
            sum = 0.0;
        }
    }

    return NULL;
}

void handlesgint(int sig)
{
    (void)sig;
    pthread_rwlock_wrlock(&rwlock);
    is_interrupted = 1;
    pthread_rwlock_unlock(&rwlock);
}