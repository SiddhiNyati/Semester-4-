#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>

#define STACK_SIZE 50000
typedef struct {
    int *buffer;
    int top;
} Stack;

Stack st; 
void initStack(Stack *stack) {
    stack->buffer = (int *)malloc(STACK_SIZE * sizeof(int));
    stack->top = -1; 
}

void push(Stack *stack, int value) {
    if (stack->top == STACK_SIZE - 1) {
        printf("Stack Overflow\n");
        return;
    }
    stack->buffer[++stack->top] = value;
}
void *pushNumbers(void *arg) {
    int *start = (int *)arg;
    int end = *start + 10000;

    srand(time(NULL)); 

    for (int i = *start; i <= end; i++) {
        int randNum = rand() % 1000000; 
        push(&st, randNum);
    }

    pthread_exit(NULL);
}

int main() {
    initStack(&st); 

    pthread_t t1, t2;
    int start1 = 1, start2 = -1;

    if (pthread_create(&t1, NULL, pushNumbers, &start1) != 0) {
        fprintf(stderr, "Error creating thread t1\n");
        return 1;
    }

    if (pthread_create(&t2, NULL, pushNumbers, &start2) != 0) {
        fprintf(stderr, "Error creating thread t2\n");
        return 1;
    }

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    int totalElements = STACK_SIZE;
    printf("Total elements that should have been pushed: %d\n", totalElements);

    printf("Total elements actually pushed: %d\n", st.top + 1);

    free(st.buffer); 
    return 0;
}
