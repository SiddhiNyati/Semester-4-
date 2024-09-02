// Task 7
#include <stdio.h>

void fn() {
    printf("Inside fn()\n");
}

void gn() {
    printf("Inside gn()\n");
}

int main() {
    void (*ptr1)() = &fn;
    void (*ptr2)() = &gn;

    printf("Address of fn: %p\n", (void*)ptr1);
    printf("Address of gn: %p\n", (void*)ptr2);

    return 0;
}
