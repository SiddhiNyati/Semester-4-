// Task 13
#include <stdio.h>

int main() {
    int num = 42;
    int *ptr1 = &num;
    int **ptr2 = &ptr1;

    printf("Address of ptr1: %p\n", (void*)ptr1);
    printf("Address of ptr2: %p\n", (void*)ptr2);

    ptr2 += 1;
    printf("New address after increment: %p\n", (void*)ptr2);

    return 0;
}
