#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

void *childThread(void *arg) {
    for (int i = 0; i < 10000; ++i) {
        printf("child\n");
        fflush(stdout);
        usleep(100000); 
    }
    return NULL;
}
int main() {
    pthread_t thread;
    pthread_create(&thread, NULL, childThread, NULL);
    for (int i = 0; i < 10000; ++i) {
        printf("parent\n");
        fflush(stdout); 
    }
    pthread_join(thread, NULL);

    return 0;
}
