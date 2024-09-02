#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 100

typedef struct {
    char name[MAX_NAME_LENGTH];
    int N;
} ThreadArgs;

void *printName(void *args) {
    ThreadArgs *targs = (ThreadArgs *)args;

    for (int i = 0; i < targs->N; i++) {
        printf("%s\n", targs->name);
        for (int j = 0; j < 1000000; j++); 
    }

    pthread_exit(NULL);
}
int main() {
    char name[MAX_NAME_LENGTH];
    int N;
    printf("Enter the name: ");
    fgets(name, MAX_NAME_LENGTH, stdin);
    name[strcspn(name, "\n")] = '\0'; 

    printf("Enter the number of times to print the name: ");
    scanf("%d", &N);

    ThreadArgs targs;
    strncpy(targs.name, name, MAX_NAME_LENGTH);
    targs.N = N;

    pthread_t thread;
    pthread_create(&thread, NULL, printName, (void *)&targs);
    pthread_join(thread, NULL);

    return 0;
}

