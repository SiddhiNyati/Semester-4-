// Task 8
#include <stdio.h>

int main() {
    int (*printfPtr)(const char *, ...) = &printf;

    printf("Address of printf: %p\n", (void*)printfPtr);

    return 0;
}
