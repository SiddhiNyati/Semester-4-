// Task 11
#include <stdio.h>

int main() {
    int num = 42;
    int *ptr = &num;

    printf("Original address: %p\n", (void*)ptr);
    ptr += 1;
    printf("New address after increment: %p\n", (void*)ptr);

    return 0;
}
