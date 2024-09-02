#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main() {
    int pid = getpid();
    printf("PID: %d\n", pid);
    
    printf("Press any key to continue...");
    getchar();
    
    int i = 1;
    int child_pid = fork(); 
    if (child_pid < 0) {
        perror("Fork failed");
        exit(EXIT_FAILURE);
    }

    if (child_pid == 0) {
        while (1) {
            printf("Child process: %d\n", i++);
            usleep(500000); 
        }
    } else {
        while (1) {
            printf("Parent process: %d\n", i++);
            usleep(500000); 
        }
    }

    return 0;
}

