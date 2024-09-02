// Task 6
#include <stdio.h>

int globalVar = 100;

void fn() {
    static int staticVar = 50;
    int x = 20;

    printf("Address of globalVar: %p\n", (void*)&globalVar);
    printf("Address of staticVar: %p\n", (void*)&staticVar);
    printf("Address of x in fn: %p\n", (void*)&x);
}

int main() {
    fn();

    return 0;
}
