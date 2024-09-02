#include <stdio.h>
#include <unistd.h>

int main() {
    int x = 10;
    int r = fork();

    if (r == 0) {
        printf("Child process:\n");
        printf("x value: %d, x address: %p\n", x, (void*)&x);
        printf("r value: %d, r address: %p\n", r, (void*)&r);
    } else if (r > 0) {
        printf("Parent process:\n");
        printf("x value: %d, x address: %p\n", x, (void*)&x);
        printf("r value: %d, r address: %p\n", r, (void*)&r);
    } else {
        printf("Fork failed!\n");
    }

    return 0;
}

