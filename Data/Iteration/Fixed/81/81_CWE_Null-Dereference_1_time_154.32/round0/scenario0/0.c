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
            fprintf(stderr, "fail pthread_create\n");
            exit(EXIT_FAILURE);
        }
    }
    // operation join
    for (i = 0; i < num_threads; ++i)
    {
        pthread_join(ids[i], NULL);
    }
    // calculation of pi
    for (i = 0; i < num_threads; ++i)
    {
        pi += params[i].sum;
    }
    pi *= 4.0;
    printf("pi=%.15g\n", pi);
    // free memory
    free(CntIter);
    free(ids);
    free(params);
    return ret_code;
}
void *partial_sum(void *ptr)
{
    double sum = 0;
    union params *p = (union params *)ptr;
    unsigned long long idx = p->idx;
    unsigned long long first_iter = idx * num_steps_per_check;
    unsigned long long last_iter = (idx + 1) * num_steps_per_check;
    unsigned long long i;
    for (i = first_iter; i < last_iter && !is_interrupted; ++i)
    {
        double x = (i + 0.5) / module;
        sum += 1.0 / (1.0 + x * x);
    }
    pthread_rwlock_wrlock(&rwlock);
    CntIter[idx] = i - first_iter;
    p->sum = sum;
    pthread_rwlock_unlock(&rwlock);
    return NULL;
}
void handlesgint(int sig)
{
    is_interrupted = 1;
}