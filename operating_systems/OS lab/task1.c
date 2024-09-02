// Task 1
#include <stdio.h>

int main() {
    int a = 10;
    float b = 3.14;
    char c = 'A';

    printf("Address of a: %p\n", (void*)&a);
    printf("Address of b: %p\n", (void*)&b);
    printf("Address of c: %p\n", (void*)&c);

    return 0;
}
