#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

typedef struct {
    int *arr;
    int length;
    int start_index;
} ThreadArgs;

void *sumPartialArray(void *args) {
    ThreadArgs *targs = (ThreadArgs *)args;
    int sum = 0;
    int end_index = targs->start_index + 50; 
    for (int i = targs->start_index; i < end_index && i < targs->length; ++i) {
        sum += targs->arr[i];
    }
    int *result = (int *)malloc(sizeof(int));
    *result = sum;

    pthread_exit(result);
}

int sumArray(int *arr, int length) {
    int num_threads = (length + 49) / 50; 
    pthread_t threads[num_threads];
    ThreadArgs targs[num_threads];
    int total_sum = 0;
    for (int i = 0; i < num_threads; ++i) {
        targs[i].arr = arr;
        targs[i].length = length;
        targs[i].start_index = i * 50;
        pthread_create(&threads[i], NULL, sumPartialArray, (void *)&targs[i]);
    }
    for (int i = 0; i < num_threads; ++i) {
        void *thread_result;
        pthread_join(threads[i], &thread_result);
        total_sum += *((int *)thread_result);
        free(thread_result); 
    }
    return total_sum;
}

int main() {
    int size;
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    int arr[size];
    printf("Enter %d elements of the array:\n", size);
    for (int i = 0; i < size; ++i) {
        scanf("%d", &arr[i]);
    }

    int sum = sumArray(arr, size);
    printf("Sum of array elements: %d\n", sum);

    return 0;
}

