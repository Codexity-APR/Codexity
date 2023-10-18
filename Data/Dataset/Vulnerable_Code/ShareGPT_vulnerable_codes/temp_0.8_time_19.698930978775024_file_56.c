#include <omp.h>
#include <stdio.h>

#define MAX_PEOPLE 10

int main() {
    int num_people = 0;
    int people[MAX_PEOPLE];

    // Add code here

    #pragma omp parallel num_threads(4)
    {
        int thread_num = omp_get_thread_num();
        int start_index = thread_num * (MAX_PEOPLE / omp_get_num_threads());
        int end_index = (thread_num + 1) * (MAX_PEOPLE / omp_get_num_threads());

        for (int i = start_index; i < end_index; i++) {
            if (people[i] > 0) {
                #pragma omp critical
                {
                    num_people++;
                }
            }
        }
    }

    printf("Number of people greater than 0: %d\n", num_people);

    return 0;
}