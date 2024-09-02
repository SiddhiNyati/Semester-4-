// Task 3
#include <stdio.h>

void fn() {
    int x = 20;
    printf("Address of x in fn: %p\n", (void*)&x);
}

void gn() {
    float y = 4.5;
    printf("Address of y in gn: %p\n", (void*)&y);
}

int main() {
    fn();
    gn();

    return 0;
}
