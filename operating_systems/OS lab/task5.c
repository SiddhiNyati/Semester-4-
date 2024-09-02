// Task 5
#include <stdio.h>

void fn() {
    int x = 20;
    printf("Address of x in fn: %p\n", (void*)&x);
}

int main() {
    fn();

    int z = 30;
    printf("Address of z in main: %p\n", (void*)&z);

    fn();

    return 0;
}
